coins = 0
# Prompt the user for change owed, in cents
change_owed = float(input("Change: "))
#Check if the change is a positive number
if (change_owed <= 0):
    print("Não terá troco.")


# Calculate how many quarters you should give customer
while (change_owed >= 25):
    coins += 1
    # Subtract the value of those quarters from cents
    change_owed = change_owed - 25

#Calculate how many dimes you should give customer
while (change_owed >= 10):
    coins += 1
    #Subtract the value of those dimes from cents
    change_owed = change_owed - 10

#Calculate how many nickels you should give customer
while (change_owed >= 5):
    coins += 1
    #Subtract the value of those nickels from cents
    change_owed = change_owed - 5

 #Calculate how many pennies you should give customer
while (change_owed >= 1):
    coins += 1
# Subtract the value of those pennies from cents
    change_owed = change_owed - 1

#Print total coins
print(coins)