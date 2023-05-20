const progressBar = document.getElementById("bar");
const incrementButton = document.getElementById("increment-button");
const question = document.getElementById("question");

let progress = 0;
incrementButton.addEventListener("click", function () {
  progress = Math.min(progress + 20, 100);
  progressBar.style.width = progress + "%";
  progressBar.innerText = progress + "%";
  if (progress === 20) {
    question.innerText = "Q1. What is the capital of France?";
  }
  if (progress === 40) {
    question.innerText = "Q2. What is the capital of Germany?";
  }
  if (progress === 60) {
    question.innerText = "Q3. What is the capital of Italy?";
  }
  if (progress === 80) {
    question.innerText = "Q4. What is the capital of Spain?";
  }
  if (progress === 100) {
    question.innerText = "You have completed the quiz!";
  }
});

// Path: index.js
