<?php
// Include config file
require_once "config.php";


$username = $password = $confirm_password = "";
$username_err = $password_err = $confirm_password_err = "";
$image_name = $location = "";


if ($_SERVER["REQUEST_METHOD"] == "POST") {


  if (empty(trim($_POST["username"]))) {
    $username_err = "Please enter a username.";
  } elseif (!preg_match('/^[a-zA-Z0-9_]+$/', trim($_POST["username"]))) {
    $username_err = "Username can only contain letters, numbers, and underscores.";
  } else {

    $sql = "SELECT id FROM users WHERE username = ?";

    if ($stmt = mysqli_prepare($link, $sql)) {

      mysqli_stmt_bind_param($stmt, "s", $param_username);


      $param_username = trim($_POST["username"]);


      if (mysqli_stmt_execute($stmt)) {

        mysqli_stmt_store_result($stmt);

        if (mysqli_stmt_num_rows($stmt) == 1) {
          $username_err = "This username is already taken.";
        } else {
          $username = trim($_POST["username"]);
        }
      } else {
        echo "Oops! Something went wrong. Please try again later.";
      }


      mysqli_stmt_close($stmt);
    }
  }



  if (empty(trim($_POST["password"]))) {
    $password_err = "Please enter a password.";
  } elseif (strlen(trim($_POST["password"])) < 6) {
    $password_err = "Password must have atleast 6 characters.";
  } else {
    $password = trim($_POST["password"]);
  }


  if (empty(trim($_POST["confirm_password"]))) {
    $confirm_password_err = "Please confirm password.";
  } else {
    $confirm_password = trim($_POST["confirm_password"]);
    if (empty($password_err) && ($password != $confirm_password)) {
      $confirm_password_err = "Password did not match.";
    }
  }


  if (!empty($_FILES['image'])) {

    $image_name = $_FILES['image']['name'];
    $image_temp = $_FILES['image']['tmp_name'];
    $image_size = $_FILES['image']['size'];

    $exp = explode(".", $image_name);
    $ext = end($exp);
    $allowed_ext = array('jpg', 'jpeg', 'png', 'PNG');

    if (in_array($ext, $allowed_ext)) {
      $image = time() . '.' . $ext;
      $location = "upload/" . $image;
      if ($image_size < 5242880) {
        move_uploaded_file($image_temp, $location);
        echo "success";
      }
    } else {
      echo "error2";
    }
  } else {
    echo "error1";
  }


  if (empty($username_err) && empty($password_err) && empty($confirm_password_err)) {

    $sql = "INSERT INTO users (username, password, image_name, location) VALUES (?, ?, ?, ?)";

    if ($stmt = mysqli_prepare($link, $sql)) {

      mysqli_stmt_bind_param($stmt, "ssss", $param_username, $param_password, $image_name, $location);


      $param_username = $username;
      $param_password = password_hash($password, PASSWORD_DEFAULT);


      if (mysqli_stmt_execute($stmt)) {

        header("location: login.php");
      } else {
        echo "Oops! Something went wrong. Please try again later.";
      }


      mysqli_stmt_close($stmt);
    }
  }


  mysqli_close($link);
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>Sign Up</title>

  <link href="./bootstrap-5.0.2-dist/css/bootstrap.min.css" rel="stylesheet" />
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.min.js"></script>

  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.bundle.min.js"></script>
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.esm.js"></script>
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.esm.min.js"></script>
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.js"></script>
  <script type="text/javascript" src="./bootstrap-5.0.2-dist/js/bootstrap.bundle.js"></script>
  <style>
    body {
      font: 14px sans-serif;
      /* centre whole body content */
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
  <div class="wrapper">
    <h2>Sign Up</h2>
    <p>Please fill this form to create an account.</p>
    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post" enctype="multipart/form-data">

      <div class="form-group">
        <label>Username</label>
        <input type="text" name="username" class="form-control <?php echo (!empty($username_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $username; ?>">
        <span class="invalid-feedback"><?php echo $username_err; ?></span>
      </div>
      <div class="form-group">
        <label>Password</label>
        <input type="password" name="password" class="form-control <?php echo (!empty($password_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $password; ?>">
        <span class="invalid-feedback"><?php echo $password_err; ?></span>
      </div>
      <div class="form-group">
        <label>Confirm Password</label>
        <input type="password" name="confirm_password" class="form-control <?php echo (!empty($confirm_password_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $confirm_password; ?>">
        <span class="invalid-feedback"><?php echo $confirm_password_err; ?></span>
      </div>
      <div class="form-group">
        <label>Profile Picture</label>
        <input type="file" name="image" id="image" class="form-control" />
        <span class="invalid-feedback"></span>
      </div>

      <div class="form-group">
        <input type="submit" class="btn btn-primary" value="Submit">
        <input type="reset" class="btn btn-secondary ml-2" value="Reset">
      </div>
      <p>Already have an account? <a href="login.php">Login here</a>.</p>
    </form>
  </div>
  <script src="js/bootstrap.bundle.js"></script>
  <script src="js/bootstrap.js"></script>
  <script src="js/bootstrap.min.js"></script>

</body>

</html>