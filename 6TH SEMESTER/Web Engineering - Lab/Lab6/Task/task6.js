function displayValues() {
  var name = document.forms["signup"]["name"].value;
  var contact = document.forms["signup"]["contact"].value;
  var email = document.forms["signup"]["email"].value;
  var password = document.forms["signup"]["password"].value;
  var gender = document.querySelector('input[name="gender"]:checked');
  var interests = document.querySelectorAll('input[name="interests"]:checked');

  var namePara = document.createElement("p");
  var contactPara = document.createElement("p");
  var emailPara = document.createElement("p");
  var passwordPara = document.createElement("p");
  var genderPara = document.createElement("p");
  var interestsPara = document.createElement("p");

  namePara.innerHTML = "Name: " + name;
  contactPara.innerHTML = "Contact: " + contact;
  emailPara.innerHTML = "Email: " + email;
  passwordPara.innerHTML = "Password: " + password;
  genderPara.innerHTML = "Gender: " + gender.value;
  interestsPara.innerHTML = "Interests: ";
  for (var i = 0; i < interests.length; i++) {
    interestsPara.innerHTML += interests[i].value + " ";
  }

  document.body.appendChild(namePara);
  document.body.appendChild(contactPara);
  document.body.appendChild(emailPara);
  document.body.appendChild(passwordPara);
  document.body.appendChild(genderPara);
  document.body.appendChild(interestsPara);
}

function validateForm() {
  var name_regex = /^[A-Za-z ]+$/;
  var contact_regex = /^\d{11}$/;
  var email_regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  var password_regex = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z]{8,}$/;

  var name = document.forms["signup"]["name"].value;
  var contact = document.forms["signup"]["contact"].value;
  var email = document.forms["signup"]["email"].value;
  var password = document.forms["signup"]["password"].value;
  var gender = document.querySelector('input[name="gender"]:checked');
  var interests = document.querySelectorAll('input[name="interests"]:checked');

  if (!name_regex.test(name)) {
    alert("Please enter a valid name.");
    return false;
  }

  if (!contact_regex.test(contact)) {
    alert("Please enter a valid 10-digit phone number.");
    return false;
  }

  if (!email_regex.test(email)) {
    alert("Please enter a valid email address.");
    return false;
  }

  if (!password_regex.test(password)) {
    alert(
      "Please enter a password that is at least 8 characters long and contains at least one uppercase letter, one lowercase letter, and one number."
    );
    return false;
  }

  if (!gender) {
    alert("Please select a gender.");
    return false;
  }

  if (interests.length < 1) {
    alert("Please select at least one interest.");
    return false;
  }

  displayValues();
  return false;
}
