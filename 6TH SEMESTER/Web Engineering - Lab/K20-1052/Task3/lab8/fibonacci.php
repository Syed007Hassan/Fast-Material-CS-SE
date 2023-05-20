<!-- Task 04: Write a program which will generate the Fibonacci series up to 1000.
Also find the sum of the generated Fibonacci numbers divisible by 3, 5 and 7 only.

Example of Fibonacci series is: 1 1 2 3 5 8 13 25..........
Note: Do this task by using for loop and while loop. Also identify which one is more efficient? -->

<?php
$max = 250000;

$first = 0;
$second = 1;
$sum = 0;


while ($first + $second <= $max) {
  $third = $first + $second;
  $first = $second;
  $second = $third;


  if ($third % 3 == 0 || $third % 5 == 0 || $third % 7 == 0) {
    echo "No div by 3,5 or 7: " . $third . "<br>";
    $sum += $third;
  }
}

$first = 0;
$second = 1;


echo "Fibonacci series up to 1000: 0 1 ";

for ($i = 0; $i <= $max; $i = $first + $second) {
  $third = $first + $second;
  echo $third . " ";
  $first = $second;
  $second  = $third;
}


echo "<br>Sum of Fibonacci numbers divisible by 3, 5 and 7 only: " . $sum;
?>