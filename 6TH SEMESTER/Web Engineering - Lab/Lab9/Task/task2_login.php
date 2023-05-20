<?php

include_once("config.php");

session_start();

if (isset($_POST['submit'])) {
    $username = $_POST['username'];
    $password = $_POST['password'];

  
    $sql = "SELECT * FROM users WHERE name='$username' AND password='$password'";
    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result) == 1) {
        // Login successful
        $_SESSION['username'] = $username;
        header("Location: task2_dashboard.php");
        exit();
    } else {
        // Login failed
        $error = "Invalid username or password";
    }

    mysqli_close($conn);
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Login</title>
</head>
<body>
    <?php if (isset($error)) { echo $error . "<br>"; } ?>
    <form method="post">
        Username: <input type="text" name="username"><br>
        Password: <input type="password" name="password"><br>
        <input type="submit" name="submit" value="Login">
    </form>
</body>
</html>
