
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
    if ($found == false) {
      echo "Element not found";
    }
  }
}

search($array, $element, $index, $found);
?>