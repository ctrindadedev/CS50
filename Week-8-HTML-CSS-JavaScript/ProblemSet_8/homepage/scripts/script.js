document.addEventListener("DOMContentLoaded", function () {
  const greetButton = document.querySelector("#greet");
  if (greetButton) {
    greetButton.addEventListener("click", function () {
      const messageDiv = document.querySelector("#message");
      messageDiv.textContent =
        "Welcome! Thanks for your interest in pet adoption.";
    });
  }

  const adoptButtons = document.querySelectorAll(".adopt-btn");
  adoptButtons.forEach(function (button) {
    button.addEventListener("click", function () {
      alert(
        "Thank you for your interest! Please contact us to start the adoption process."
      );
    });
  });

  const contactForm = document.querySelector("#contactForm");
  if (contactForm) {
    contactForm.addEventListener("submit", function (event) {
      event.preventDefault();
      const responseDiv = document.querySelector("#form-response");
      responseDiv.textContent =
        "Thank you for your message! We will get back to you soon.";
      contactForm.reset();
    });
  }
});
