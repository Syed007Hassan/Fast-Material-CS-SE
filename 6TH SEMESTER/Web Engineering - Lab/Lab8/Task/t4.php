<!-- Task 04: Write a program which will generate the Fibonacci series up to 1000.
Also find the sum of the generated Fibonacci numbers divisible by 3, 5 and 7 only.

Example of Fibonacci series is: 1 1 2 3 5 8 13 25..........
Note: Do this task by using for loop and while loop. Also identify which one is more efficient? -->

<?php
$max = 1000;

// initialize the first two Fibonacci numbers
$first = 0;
$second = 1;
$sum = 0;

// loop to generate the Fibonacci series up to 1000
while ($first + $second <= $max) {
  $third = $first + $second;
  $first = $second;
  $second = $third;

  // check if the current Fibonacci number is divisible by 3, 5 and 7
  if ($third % 3 == 0 || $third % 5 == 0 || $third % 7 == 0) {
    $sum += $third;
    // echo $sum . " ";
  }
}

$first = 0;
$second = 1;


echo "Fibonacci series up to 1000: 0 1 ";
for ($i = 1; $i <= $max; $i = $first + $second) {
  $third = $first + $second;
  echo $third . " ";
  $first = $second;
  $second = $third;
}
echo "<br>Sum of Fibonacci numbers divisible by 3, 5 and 7 only: " . $sum;
?>