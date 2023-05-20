<?php
$a = 8;
$b = 9;
$c = 3;

// calculate the value of b2 - 4ac
$discriminant = $b * $b - 4 * $a * $c;

// find the roots of the quadratic equation
switch ($discriminant) {
  case $discriminant > 0:
    $root1 = (-$b + sqrt($discriminant)) / (2 * $a);
    $root2 = (-$b - sqrt($discriminant)) / (2 * $a);
    echo "The roots are $root1 and $root2";
    break;
  case $discriminant == 0:
    $root1 = $root2 = -$b / (2 * $a);
    echo "The roots are $root1 and $root2";
    break;
  case $discriminant < 0:
    $realPart = -$b / (2 * $a);
    $imaginaryPart = sqrt(-$discriminant) / (2 * $a);
    echo "The roots are $realPart + $imaginaryPart i and $realPart - $imaginaryPart i";
    break;
}
echo "<br>";
// with if else

if ($discriminant > 0) {
  $root1 = (-$b + sqrt($discriminant)) / (2 * $a);
  $root2 = (-$b - sqrt($discriminant)) / (2 * $a);
  echo "The roots are $root1 and $root2";
} else if ($discriminant == 0) {
  $root1 = $root2 = -$b / (2 * $a);
  echo "The roots are $root1 and $root2";
} else {
  $realPart = -$b / (2 * $a);
  $imaginaryPart = sqrt(-$discriminant) / (2 * $a);
  echo "The roots are $realPart + $imaginaryPart i and $realPart - $imaginaryPart i";
}
