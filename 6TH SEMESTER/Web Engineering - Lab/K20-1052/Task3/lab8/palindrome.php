<?php

$string = "madam";




function palindrome($string)
{

  for ($i = 0; $i < strlen($string) / 2; $i++) {
    if ($string[$i] != $string[strlen($string) - $i - 1]) {
      echo "not a palindrome";
      return;
    }
  }


  return $string . " is palindrome";
}




echo palindrome($string);
