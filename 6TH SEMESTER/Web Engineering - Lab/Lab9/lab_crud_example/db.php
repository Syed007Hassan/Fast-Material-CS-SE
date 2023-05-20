<?php
//server with default setting (user 'root' with no password)
$host = 'localhost';  // server
$user = 'root';
$pass = "";
$database = 'demo';   //Database Name

// establishing connection
$link = mysqli_connect($host, $user, $pass, $database);

// for displaying an error msg in case the connection is not established
if (!$link) {
  die("Connection failed: " . mysqli_connect_error());
} else {
  // echo "Connected Successfully";
}
