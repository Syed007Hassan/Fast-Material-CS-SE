<?php
$servername = "localhost";
$username = "root";
$pass = "";
$db = "FastMedicos";
$conn = mysqli_connect($servername, $username, $pass, $db);

if ($conn) {
    $_SESSION['conn'] = true;
} else {
    $_SESSION['conn'] = false;
}
