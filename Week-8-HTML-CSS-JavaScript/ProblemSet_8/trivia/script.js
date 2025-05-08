//Part 1 Script

const multipleChoiceQuestions = document.querySelector(".answer-options");
const feedbackResposta = document.querySelector(".answer-feedback");

console.log(feedbackResposta.textContent);

// Usa o event delegation para detectar cliques nas opções
multipleChoiceQuestions.addEventListener("click", (event) => {
  // Verifica se o clique foi em um botão
  if (event.target.tagName === "BUTTON") {
    feedbackResposta.classList.remove("answer-feedback");
    if (event.target.classList.contains("correct-answer")) {
      feedbackResposta.textContent = "You're right, congratulations!";
      feedbackResposta.style.color = "green";
    } else {
      feedbackResposta.textContent = "Sorry, your answer isnt correct :(";
      feedbackResposta.style.color = "red";
    }
  }
});

//Part 2 Script
const sendButton = document.getElementById("submit-response");
sendButton.addEventListener("click", () => {
  const userResponse = document.getElementById("free-response-input");
  const feedback = document.getElementById("free-response-feedback");
  const correctAnswer = "Paris";

  // Verifica se a resposta está correta
  if (userResponse.value.trim().toLowerCase() === correctAnswer.toLowerCase()) {
    userResponse.style.backgroundColor = "lightgreen";
    feedback.textContent = "Correct!";
    feedback.style.color = "green";
  } else {
    userResponse.style.backgroundColor = "lightcoral";
    feedback.textContent = "Incorrect";
    feedback.style.color = "red";
  }
});
