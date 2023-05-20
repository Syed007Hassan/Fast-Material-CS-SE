// practice.js
const clickMe = () => {
  var name = document.getElementById("first").innerText;

  len = name.length;
  var name2 = "";
  for (let i = len - 1; i >= 0; i--) {
    name2 += name[i];
  }

  document.getElementById("second").innerText = name2;
  document.getElementById("second").style.color = "red";
};
