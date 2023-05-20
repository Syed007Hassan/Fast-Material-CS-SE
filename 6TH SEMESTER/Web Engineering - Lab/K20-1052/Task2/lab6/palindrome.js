const isPalindrome = (str) => {
  if (str === "") {
    return "";
  }
  return isPalindrome(str.substr(1)) + str.charAt(0);
};

let x = "12321";
let z = isPalindrome(x);
if (x == z) {
  alert("x: " + x + " is a palindrome");
} else {
  alert("x: " + x + " is not a palindrome");
}
