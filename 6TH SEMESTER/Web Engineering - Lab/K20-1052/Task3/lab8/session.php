<?php

session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {

  $name = $_POST["name"];
  $pwd = $_POST["pwd"];

  $_SESSION["user"] = $name;
  $_SESSION["pwd"] = $pwd;

  header("Location: scond.php");
}

?>
<!doctype html>
<html>

<head>
  <meta charset="utf-8">
  <title></title>
</head>

<body>
  <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post" enctype="multipart/form-data">
    <table border="2px solid black">


      <tr>
        <td>Name</td>
        <td><input type="text" name="name" required /> </td>
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



</body>

</html>