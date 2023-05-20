<?php
function operators_demo() {
  $a = 5;
  $b = "10";

  // Arithmetic operators
  echo "Arithmetic operators:\n";
  echo "Addition: " . ($a + $b) . "\n";
  echo "Subtraction: " . ($a - $b) . "\n";
  echo "Multiplication: " . ($a * $b) . "\n";
  echo "Division: " . ($a / $b) . "\n";
  echo "Modulus: " . ($a % $b) . "\n\n";

  // Comparison operators
  echo "Comparison operators:\n";
  echo "Equal: " . ($a == $b) . "\n";
  echo "Identical: " . ($a === $b) . "\n";
  echo "Not equal: " . ($a != $b) . "\n";
  echo "Not identical: " . ($a !== $b) . "\n";
  echo "Greater than: " . ($a > $b) . "\n";
  echo "Less than: " . ($a < $b) . "\n";
  echo "Greater than or equal to: " . ($a >= $b) . "\n";
  echo "Less than or equal to: " . ($a <= $b) . "\n\n";

  // Logical operators
  echo "Logical operators:\n";
  echo "And: " . ($a && $b) . "\n";
  echo "Or: " . ($a || $b) . "\n";
  echo "Not: " . (!$a) . "\n\n";

  // Bitwise operators
  $c = 10;
  echo "Bitwise operators:\n";
  echo "And: " . ($a & $c) . "\n";
  echo "Or: " . ($a | $c) . "\n";
  echo "Xor: " . ($a ^ $c) . "\n";
  echo "Not: " . (~$a) . "\n";
  echo "Left shift: " . ($a << 2) . "\n";
  echo "Right shift: " . ($a >> 1) . "\n\n";

  // Assignment operators
  echo "Assignment operators:\n";
  $a += $b;
  echo "Add and assign: " . $a . "\n";
  $a -= $b;
  echo "Subtract and assign: " . $a . "\n";
  $a *= $b;
  echo "Multiply and assign: " . $a . "\n";
  $a /= $b;
  echo "Divide and assign: " . $a . "\n";
  $a %= $b;
  echo "Modulus and assign: " . $a . "\n";
  $a &= $c;
  echo "Bitwise AND and assign: " . $a . "\n";
  $a |= $c;
  echo "Bitwise OR and assign: " . $a . "\n";
  $a ^= $c;
  echo "Bitwise XOR and assign: " . $a . "\n";
  $a <<= 2;
  echo "Left shift and assign: " . $a . "\n";
  $a >>= 1;
  echo "Right shift and assign: " . $a . "\n\n";

  // Increment and decrement operators
  echo "Increment and decrement operators:\n";
  $a = 5;
}

operators_demo();
?>