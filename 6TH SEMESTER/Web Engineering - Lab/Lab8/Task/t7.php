<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>

</head>

<body>
  <h1>Signup Form</h1>
  <form action="" method="get">
    <label for="name">Name</label>
    <input type="text" name="name" id="name">
    <br>
    <label for="email">Email</label>
    <input type="email" name="email" id="email">
    <br>
    <label for="phone">Phone</label>
    <input type="number" name="phone" id="phone">
    <br>
    <input type="submit" value="Submit">
  </form>

  <?php
  $name = $_GET['name'];
  $email = $_GET['email'];
  $phone = $_GET['phone'];

  echo "<br>Name: " . $name . "<br>";
  echo "Email: " . $email . "<br>";
  echo "Phone: " . $phone . "<br>";
  ?>
</body>

</html>