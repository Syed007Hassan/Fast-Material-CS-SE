<?php

$host = 'localhost';
$user = 'root';
$pass = "";
$database = 'demo';


$link = mysqli_connect($host, $user, $pass, $database);


if (!$link) {
  die("Connection failed: " . mysqli_connect_error());
} else {
  // echo "Connected successfully";
  //alert message to display if connected successfully
  // echo "<script>alert('Connected successfully')</script>";
}
