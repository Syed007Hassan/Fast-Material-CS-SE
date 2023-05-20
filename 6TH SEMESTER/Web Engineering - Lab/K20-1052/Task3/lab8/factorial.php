<!-- Task 03: Write a program which will find the factorial of a given number.
Exit the program if the input number is negative.

Example of Factorial: Input number = 5
Factorial is=5*4*3*2*1

Note: Justify your choice of loop answering two important points:
  why your choice is optimal? why other looping structure would not be suitable? -->

<?php
$number = fun(5);
echo $number;


function fun($n)
{
  if ($n == 0) {
    return 1;
  } else {
    return $n * fun($n - 1);
  }
}

?>

<?php
$number = 5;

$factorial = 1;
for ($x = $number; $x >= 1; $x--) {
  $factorial = $factorial * $x;
}
echo "Factorial of $number is $factorial";
?>