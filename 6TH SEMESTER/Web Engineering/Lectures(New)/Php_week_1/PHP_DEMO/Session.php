<?php
session_start();
?>
<!doctype html>
<html>

<head>
  <meta charset="utf-8">
  <title></title>
</head>

<body>
  <form action="scond.php" method="post" enctype="multipart/form-data">
    <table border="2px solid black">


      <tr>
        <td>Email </td>
        <td><input type="text" name="email" required /> </td>
      </tr>
      <tr>
        <td>Password </td>
        <td><input type="password" name="pwd" /> </td>
      </tr>
      <tr>
        <td colspan="2"><button type="submit" value="submit" required> Submit </button> </td>
      </tr>

    </table>
  </form>




  <?php

  if (isset($_SESSION["user"])) {
    header("Location:http://localhost/Hussain/session.php");
  }
  $email = "fahad@gmail.com";
  $password = "admin";


  if ($_SERVER['REQUEST_METHOD'] == "POST") {
    if ($email === $_POST['email'] || $password === $_POST['pwd']) {
      $_SESSION["user"] = "Fahad Hussain";
      header("Location:http://localhost/Hussain/session.php");
    } else {
      echo "<p style='color:red'>Invalid ID or Password..... </p>";
    }
  }

  ?>



</body>

</html>