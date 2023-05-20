<?php 
$host = 'localhost';
$user = 'root';
$pw = '';
$dbname = 'mcg_db';

$conn = new mysqli($host, $user, $pw, $dbname);
if(!$conn){
    die("Database connection failed. Error: ".$conn->error);
}
