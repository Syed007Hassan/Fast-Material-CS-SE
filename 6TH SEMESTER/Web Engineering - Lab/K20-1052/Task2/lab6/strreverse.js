// Task 2: Reverse a string

const reverseString = (str) => {
  if (str === "") {
    return "";
  }
  return reverseString(str.substr(1)) + str.charAt(0);
};

console.log(reverseString("hassan"));
