<?php

include_once("config.php");

if (isset($_POST['submit'])) {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $password = $_POST['password'];


    // Validate inputs
    if (empty($name) || empty($email) || empty($password)) {
        $error = "Please fill in all fields";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $error = "Invalid email format";
    } else {
        // Check if email already exists in database
        $sql = "SELECT * FROM users WHERE email='$email'";
        $result = mysqli_query($conn, $sql);

        if (mysqli_num_rows($result) > 0) {
            $error = "Email already exists";
        } else {
            // Insert user into database
            $sql = "INSERT INTO users (name, email, password) VALUES ('$name', '$email', '$password')";

            if (mysqli_query($conn, $sql)) {
                $message = "User created successfully";
            } else {
                $error = "Error creating user: " . mysqli_error($conn);
            }
        }
    }

    mysqli_close($conn);
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Registration</title>
</head>
<body>
    <?php if (isset($error)) { echo $error . "<br>"; } ?>
    <?php if (isset($message)) { echo $message . "<br>"; } ?>
    <form method="post">
        Name: <input type="text" name="name"><br>
        Email: <input type="text" name="email"><br>
        Password: <input type="password" name="password"><br>
        <input type="submit" name="submit" value="Register">
    </form>
</body>
</html>
