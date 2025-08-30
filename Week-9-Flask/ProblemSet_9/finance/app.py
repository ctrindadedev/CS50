import os
from datetime import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]

    # Get user cash balance
    user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    user_cash = user_cash_db[0]["cash"]

    # Get user stock holdings
    stocks = db.execute(
        "SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0",
        user_id,
    )

    # Initialize variables for portifolio value
    grand_total = user_cash
    holdings = []

    # Loop to get current price and value (over stock)
    for stock in stocks:
        quote = lookup(stock["symbol"])
        if quote:
            total_value = stock["total_shares"] * quote["price"]
            grand_total += total_value
            holdings.append(
                {
                    "symbol": stock["symbol"],
                    "shares": stock["total_shares"],
                    "price": quote["price"],
                    "total_value": total_value,
                }
            )

    return render_template(
        "index.html",
        holdings=holdings,
        cash=user_cash,
        grand_total=grand_total,
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares_str = request.form.get("shares")

        if not symbol:
            return apology("must provide symbol", 400)

        if not shares_str or not shares_str.isdigit() or int(shares_str) <= 0:
            return apology("shares must be a positive integer", 400)

        shares = int(shares_str)
        quote = lookup(symbol)

        if quote is None:
            return apology("invalid symbol", 400)

        price = quote["price"]
        total_cost = shares * price
        user_id = session["user_id"]

        user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = user_cash_db[0]["cash"]

        if user_cash < total_cost:
            return apology("can't afford", 400)

        # Update user's cash
        updated_cash = user_cash - total_cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updated_cash, user_id)

        # Record the transaction
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price, transacted_at) VALUES (?, ?, ?, ?, ?)",
            user_id,
            symbol,
            shares,
            price,
            datetime.now(),
        )

        flash("Bought!")
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    transactions = db.execute(
        "SELECT symbol, shares, price, transacted_at FROM transactions WHERE user_id = ? ORDER BY transacted_at DESC",
        user_id,
    )
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    session.clear()
    if request.method == "POST":
        if not request.form.get("username"):
            return apology("must provide username", 403)
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        session["user_id"] = rows[0]["id"]
        return redirect("/")
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""
    session.clear()
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        quote = lookup(symbol)
        if not quote:
            return apology("invalid symbol", 400)
        return render_template("quoted.html", quote=quote)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Validate submission
        if not username:
            return apology("must provide username", 400)
        elif not password:
            return apology("must provide password", 400)
        elif password != confirmation:
            return apology("passwords do not match", 400)

        hash = generate_password_hash(password)

        # Insert user into DB
        try:
            new_user_id = db.execute(
                "INSERT INTO users (username, hash) VALUES(?, ?)", username, hash
            )
        except ValueError:
            return apology("username already exists", 400)

        #  User login in
        session["user_id"] = new_user_id

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = session["user_id"]

    # Return symbols of stocks the user owns
    stocks = db.execute(
        "SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0",
        user_id,
    )

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares_str = request.form.get("shares")

        if not symbol:
            return apology("must select a symbol", 400)
        if not shares_str or not shares_str.isdigit() or int(shares_str) <= 0:
            return apology("shares must be a positive integer", 400)

        shares_to_sell = int(shares_str)

        # Check if have enough shares
        owned_shares_db = db.execute(
            "SELECT SUM(shares) as total_shares FROM transactions WHERE user_id = ? AND symbol = ? GROUP BY symbol",
            user_id,
            symbol,
        )
        if not owned_shares_db or owned_shares_db[0]["total_shares"] < shares_to_sell:
            return apology("not enough shares", 400)

        # Get current price and calculate sale value
        quote = lookup(symbol)
        if quote is None:
            return apology("invalid symbol", 400)
        price = quote["price"]
        sale_value = shares_to_sell * price

        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", sale_value, user_id)

        # Save the transaction
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price, transacted_at) VALUES (?, ?, ?, ?, ?)",
            user_id,
            symbol,
            -shares_to_sell,
            price,
            datetime.now(),
        )

        flash("Sold!")
        return redirect("/")

    else:
        return render_template("sell.html", stocks=stocks)
    
@app.route("/password_change", methods=["GET", "POST"])
@login_required
def password_change():
    """Allow user to change password"""
    if request.method == "POST":
        current_password = request.form.get("current_password")
        new_password = request.form.get("new_password")
        confirmation = request.form.get("confirmation")
        user_id = session["user_id"]

        if not current_password or not new_password or not confirmation:
            return apology("must provide all fields", 400)

        # Query database for current user hash
        rows = db.execute("SELECT hash FROM users WHERE id = ?", user_id)

    #Verify passwords
        if not check_password_hash(rows[0]["hash"], current_password):
            return apology("invalid current password", 403)

       
        if new_password != confirmation:
            return apology("new passwords do not match", 400)

        new_hash = generate_password_hash(new_password)

        db.execute("UPDATE users SET hash = ? WHERE id = ?", new_hash, user_id)

        flash("Password changed successfully")
        return redirect("/")

    else:
        return render_template("password_change.html")



