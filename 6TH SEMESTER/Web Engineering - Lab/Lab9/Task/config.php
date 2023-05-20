<?php

$host = 'localhost';
$dbname = 'lab9';
$user = 'root';
$password = '';

$conn = mysqli_connect($host, $user, $password, $dbname);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Path: config.php
