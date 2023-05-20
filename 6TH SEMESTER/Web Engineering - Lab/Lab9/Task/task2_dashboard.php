<?php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: task2_login.php");
    exit();
}

// CRUD operations go here
?>
<!DOCTYPE html>
<html>
<head>
    <title>Dashboard</title>
</head>
<body>
    <h1>Welcome <?php echo $_SESSION['username']; ?></h1>
    <a href="task2_logout.php">Logout</a>
</body>
</html>
