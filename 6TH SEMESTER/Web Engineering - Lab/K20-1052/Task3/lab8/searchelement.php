<?php
$array = array(5, 4, 3, 2, 1, 6, 10, 9, 7, 8);
$element = 7;
$index = 0;
$found = false;

function search($array, $element, $index, $found)
{
  if ($index < count($array)) {
    if ($array[$index] == $element) {
      $found = true;
      echo "Element found at index: " . $index;
    } else {
      $index++;
      search($array, $element, $index, $found);
    }
  } else {
    echo "Element not found";
  }
}

search($array, $element, $index, $found);
?>

<!--
// take an array with some elements
$array = array('a','z','c','b');
// get the size of array
$count = count($array);
echo "
<pre>";
// Print array elements before sorting
print_r($array);
for ($i = 0; $i < $count; $i++) {
    for ($j = $i + 1; $j < $count; $j++) {
        if ($array[$i] > $array[$j]) {
            $temp = $array[$i];
            $array[$i] = $array[$j];
            $array[$j] = $temp;
        }
    }
}
echo "Sorted Array:" . "<br/>";
print_r($array); -->