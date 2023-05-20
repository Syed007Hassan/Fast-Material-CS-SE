<?php
if (isset($_COOKIE['last_page'])) {
    echo "Welcome back! You have visited again ";
} else {
    echo "Welcome! This is your first visit.";
}

if (isset($_SERVER['HTTP_REFERER'])) {
    $last_page = $_SERVER['HTTP_REFERER'];
} else {
    $last_page = "";
}

setcookie("last_page", $last_page, time() + (86400 * 30), "/"); // cookie lasts for 30 days

?>

<!DOCTYPE html>
<html>
<head>
    <title>Page 1</title>
</head>
<body>
    <h1>Welcome to Page 1</h1>
    <p>Click the button below to visit Page 2.</p>
    <a href="task4_page2.php">Go to Page 2</a>
</body>
</html>
