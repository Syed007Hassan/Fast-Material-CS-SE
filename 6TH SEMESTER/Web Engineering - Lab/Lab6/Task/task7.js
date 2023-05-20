function validateForm() {
  // Regular expressions for validation
  var name_regex = /^[A-Za-z ]+$/;
  var contact_regex = /^\d{11}$/;
  var email_regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  var password_regex = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z]{8,}$/;

  // Get form input values
  var name = document.forms["signup"]["name"].value;
  var contact = document.forms["signup"]["contact"].value;
  var email = document.forms["signup"]["email"].value;
  var password = document.forms["signup"]["password"].value;
  var gender = document.querySelector('input[name="gender"]:checked');
  var interests = document.querySelectorAll('input[name="interests"]:checked');

  // Validate name field
  if (!name_regex.test(name)) {
    alert("Please enter a valid name.");
    return false;
  }

  // Validate contact field
  if (!contact_regex.test(contact)) {
    alert("Please enter a valid 11-digit phone number.");
    return false;
  }

  // Validate email field
  if (!email_regex.test(email)) {
    alert("Please enter a valid email address.");
    return false;
  }

  // Validate password field
  if (!password_regex.test(password)) {
    alert(
      "Please enter a password that is at least 8 characters long and contains at least one uppercase letter, one lowercase letter, and one number."
    );
    return false;
  }

  // Validate gender field
  if (!gender) {
    alert("Please select a gender.");
    return false;
  }

  // Validate interests field
  if (interests.length < 1) {
    alert("Please select at least one interest.");
    return false;
  }

  // Form validated successfully
  alert("Form validated successfully!");
  return true;
}
