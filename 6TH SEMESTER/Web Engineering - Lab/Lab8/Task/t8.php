<?php
$txt = "Hello world!";
$x = 5;
$y = 10.5;

echo $txt;
echo "<br>";
echo $x;
echo "<br>";
echo $y;

// operators in php

// arithmetic operators
// + - * / % **
$x = 10;
$y = 6;
echo $x + $y;
echo "<br>";
echo $x - $y;
echo "<br>";
echo $x * $y;
echo "<br>";
echo $x / $y;
echo "<br>";
echo $x % $y;
echo "<br>";
echo $x ** $y;
echo "<br>";

// assignment operators
// = += -= *= /= %= **=

$x = 10;
$x += 5;
echo $x;
echo "<br>";

$x = 10;
$x -= 5;
echo $x;
echo "<br>";

$x = 10;
$x *= 5;
echo $x;
echo "<br>";

$x = 10;
$x /= 5;
echo $x;
echo "<br>";

$x = 10;
$x %= 5;
echo $x;
echo "<br>";

$x = 10;
$x **= 5;
echo $x;
echo "<br>";

// comparison operators

// == != > < >= <= === !==

$x = 10;
$y = 10;
var_dump($x == $y);
echo "<br>";
var_dump($x != $y);
echo "<br>";
var_dump($x > $y);
echo "<br>";
var_dump($x < $y);
echo "<br>";
var_dump($x >= $y);
echo "<br>";
var_dump($x <= $y);
echo "<br>";
var_dump($x === $y);
echo "<br>";
var_dump($x !== $y);
echo "<br>";

// increment and decrement operators

// ++ --
$x = 10;
echo ++$x;
echo "<br>";
echo $x++;
echo "<br>";
echo $x;
echo "<br>";
echo --$x;
echo "<br>";
echo $x--;
echo "<br>";
echo $x;
echo "<br>";

// logical operators

// and && or || xor !

$x = 10;
$y = 20;
var_dump($x < 20 and $y > 10);
echo "<br>";
var_dump($x < 20 && $y > 10);
echo "<br>";
var_dump($x < 20 or $y > 10);
echo "<br>";
var_dump($x < 20 || $y > 10);
echo "<br>";
var_dump($x < 20 xor $y > 10);
echo "<br>";
var_dump(!($x < 20 and $y > 10));
echo "<br>";

// string operators

// . .=

$x = "Hello";
$y = "World";
echo $x . $y;
echo "<br>";
echo $x .= $y;
echo "<br>";

// array operators

// + == === != !==

$x = array("a" => "red", "b" => "green");
$y = array("c" => "blue", "d" => "yellow");
var_dump($x + $y);
echo "<br>";
var_dump($x == $y);
echo "<br>";
var_dump($x === $y);
echo "<br>";
var_dump($x != $y);
echo "<br>";
var_dump($x !== $y);
echo "<br>";

// conditional statements

// if else elseif

$t = date("H");

if ($t < "20") {
  echo "Have a good day!";
}

// switch

$favcolor = "red";

switch ($favcolor) {
  case "red":
    echo "Your favorite color is red!";
    break;
  case "blue":
    echo "Your favorite color is blue!";
    break;
  case "green":
    echo "Your favorite color is green!";
    break;
  default:
    echo "Your favorite color is neither red, blue, nor green!";
}

// loops

// while

$x = 1;

while ($x <= 5) {
  echo "The number is: $x <br>";
  $x++;
}

// do while

$x = 1;

do {
  echo "The number is: $x <br>";
  $x++;
} while ($x <= 5);

// for

for ($x = 0; $x <= 10; $x++) {
  echo "The number is: $x <br>";
}

// foreach

$colors = array("red", "green", "blue", "yellow");

foreach ($colors as $value) {
  echo "$value <br>";
}
