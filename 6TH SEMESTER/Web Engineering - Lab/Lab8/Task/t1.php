<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Form Example</title>
</head>

<body>

  <form action="" method="post">

    <label for="name">Name:</label>
    <input type="text" name="name" id="">

    <label for="email">Email:</label>
    <input type="email" name="email" id="">

    <input type="submit" value="Submit">
  </form>


</body>

</html>


<?php

echo "<h1>Form Data</h1>";

$name = $_POST['name'];
$email = $_POST['email'];

echo "Name: " . $name . "<br>";
echo " Email: " . $email . "<br>";
?>