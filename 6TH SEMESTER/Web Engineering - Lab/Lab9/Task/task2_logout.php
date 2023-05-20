<?php
session_start();
session_destroy();
header("Location: task2_login.php");
exit();
?>
