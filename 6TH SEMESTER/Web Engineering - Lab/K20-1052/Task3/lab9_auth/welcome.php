<?php
require_once "config.php";
session_start();
$name = "";
if (isset($_SESSION["loggedin"]) && $_SESSION["loggedin"] === true) {
  $name = $_SESSION["username"];

  $sql = "SELECT image_name, location FROM users WHERE username = '$name'";
  $result = mysqli_query($link, $sql);
  $row = mysqli_fetch_array($result);
  $image_name = $row['image_name'];
  $location = $row['location'];
} else {
  header("location: login.php");
  exit;
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>Welcome</title>

  <link href="./bootstrap-5.0.2-dist/css//bootstrap.min.css" rel="stylesheet" />
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.min.js"></script>

  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.bundle.min.js"></script>
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.esm.js"></script>
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.esm.min.js"></script>
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.js"></script>
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.bundle.js"></script>

  <style>
    body {
      font: 14px sans-serif;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
    }

    .wrapper {
      width: 360px;
      padding: 20px;
    }
  </style>
</head>

<body>

  <body>

    <div class="wrapper d-flex justify-content-center align-items-center flex-column">
      <h2 class="mb-4">You are logged in</h2>
      <div class="card" style="width: 20rem;">
        <img src="<?php echo $location; ?>" class="card-img-top" alt="...">
        <div class="card-body">
          <h5 class="card-title">Welcome <?php echo $name; ?></h5>
        </div>
        <div class="card-footer bg-transparent d-flex justify-content-center">
          <?php if (isset($_SESSION["loggedin"]) && $_SESSION["loggedin"] === true) : ?>
            <a href="logout.php" class="btn btn-danger">Sign Out</a>
          <?php endif; ?>
        </div>
      </div>
    </div>

  </body>

</body>

</html>