<?php

include_once("config.php");

if (isset($_POST['submit'])) {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $phone = $_POST['phone'];

    $sql = "INSERT INTO users (name, email, phone) VALUES ('$name', '$email', '$phone')";

    if (mysqli_query($conn, $sql)) {
        echo "New user created successfully";
        $sql = "SELECT * FROM users";
        $result = mysqli_query($conn, $sql);

        if (mysqli_num_rows($result) > 0) {
            while ($row = mysqli_fetch_assoc($result)) {
                echo "ID: " . $row["id"] . "<br>";
                echo "Name: " . $row["name"] . "<br>";
                echo "Email: " . $row["email"] . "<br>";
                echo "Phone: " . $row["phone"] . "<br>";
                echo "<br>";
            }

            $id = 1;
            $name = 'anjiya';

            $sql = "UPDATE users SET name='$name' WHERE id='$id'";

            if (mysqli_query($conn, $sql)) {
                echo "User updated successfully";
            } else {
                echo "Error: " . $sql . "<br>" . mysqli_error($conn);
            }
        } else {
            echo "0 results";
        }
    } else {
        echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    }
}
?>

<form method="post">
    Name: <input type="text" name="name"><br>
    Email: <input type="text" name="email"><br>
    Phone: <input type="text" name="phone"><br>
    <input type="submit" name="submit" value="Submit">
</form>

<?php



$id = 1;
$sql = "DELETE FROM users WHERE id='$id'";

if (mysqli_query($conn, $sql)) {
    echo "User deleted successfully";
} else {
    echo "Error deleting user: " . mysqli_error($conn);
}
