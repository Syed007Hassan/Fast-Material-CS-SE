<?php
require_once "config.php";
// Initialize the session
session_start();

// Check if the user is already logged in, if yes then redirect him to welcome page
if (isset($_SESSION["loggedin"]) && $_SESSION["loggedin"] === true) {
  header("location: welcome.php");
  exit;
}


$username = $password = "";
$username_err = $password_err = $login_err = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {


  if (empty(trim($_POST["username"]))) {
    $username_err = "Please enter username.";
  } else {
    $username = trim($_POST["username"]);
  }


  if (empty(trim($_POST["password"]))) {
    $password_err = "Please enter your password.";
  } else {
    $password = trim($_POST["password"]);
  }


  if (empty($username_err) && empty($password_err)) {

    $sql = "SELECT id, username, password FROM users WHERE username = ?";

    if ($stmt = mysqli_prepare($link, $sql)) {

      mysqli_stmt_bind_param($stmt, "s", $param_username);


      $param_username = $username;


      if (mysqli_stmt_execute($stmt)) {

        mysqli_stmt_store_result($stmt);


        if (mysqli_stmt_num_rows($stmt) == 1) {

          mysqli_stmt_bind_result($stmt, $id, $username, $hashed_password);
          if (mysqli_stmt_fetch($stmt)) {
            if (password_verify($password, $hashed_password)) {

              session_start();


              $_SESSION["loggedin"] = true;
              $_SESSION["id"] = $id;
              $_SESSION["username"] = $username;


              header("location: welcome.php");
            } else {

              $login_err = "Invalid username or password.";
            }
          }
        } else {

          $login_err = "Invalid username or password.";
        }
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
  <title>Login</title>

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
    <h2>Login</h2>
    <p>Please fill in your credentials to login.</p>

    <?php
    if (!empty($login_err)) {
      echo '<div class="alert alert-danger">' . $login_err . '</div>';
    }
    ?>

    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
      <div class="form-group">
        <label>Username</label>
        <input type="text" name="username" class="form-control <?php echo (!empty($username_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $username; ?>">
        <span class="invalid-feedback"><?php echo $username_err; ?></span>
      </div>
      <div class="form-group">
        <label>Password</label>
        <input type="password" name="password" class="form-control <?php echo (!empty($password_err)) ? 'is-invalid' : ''; ?>">
        <span class="invalid-feedback"><?php echo $password_err; ?></span>
      </div>
      <div class="form-group">
        <input type="submit" class="btn btn-primary" value="Login">
      </div>
      <p>Don't have an account? <a href="register.php">Sign up now</a>.</p>
    </form>
  </div>
</body>

</html>