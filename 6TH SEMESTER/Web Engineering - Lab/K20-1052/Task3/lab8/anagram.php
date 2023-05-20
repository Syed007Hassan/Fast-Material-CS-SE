<?php

$string = "heart";
$string2 = "earth";


// $arr1 = str_split($string);
// $arr2 = str_split($string2);

$arr1 = [];
$arr2 = [];

for ($i = 0; $i < strlen($string); $i++) {
  array_push($arr1, $string[$i]);
}

for ($i = 0; $i < strlen($string2); $i++) {
  array_push($arr2, $string2[$i]);
}



sort($arr1);
sort($arr2);

if ($arr1 == $arr2) {
  echo "Anagram";
} else {
  echo "Not anagram";
}
