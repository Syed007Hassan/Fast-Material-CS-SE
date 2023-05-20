<?php

if (isset($_POST["name"])) {
  $name = $_POST["name"];
  $pwd = $_POST["pwd"];

  echo "Name: " . $name . "<br>";
  echo "Post request<br>";
}

if (isset($_GET["name"])) {
  $name = $_GET["name"];
  $pwd = $_GET["pwd"];

  echo "Name: " . $name . "<br>";
  echo "Get request<br>";
}


?>
<!doctype html>
<html>

<head>
  <meta charset="utf-8">
  <title>Connect Us</title>
  <link rel="stylesheet" href="./bootstrap-5.0.2-dist/css/bootstrap.min.css" />
</head>

<body>
  <div class="container">
    <div class="row justify-content-center">
      <div class="col-md-6">
        <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="" enctype="multipart/form-data">
          <div class="card mt-5">
            <div class="card-header">
              <h3 class="card-title text-center">Sign Up Form</h3>
            </div>
            <div class="card-body">
              <div class="form-group mb-3">
                <label for="name" class="form-label">Name</label>
                <input type="text" name="name" id="name" class="form-control" required>
              </div>
              <div class="form-group mb-3">
                <label for="email" class="form-label">Email</label>
                <input type="email" name="email" id="email" class="form-control" required>
              </div>
              <div class="form-group mb-3">
                <label for="pwd" class="form-label">Password</label>
                <input type="password" name="pwd" id="pwd" class="form-control">
              </div>
            </div>
            <div class="card-footer text-end">
              <button formmethod="post" type="submit" value="submit" class="btn btn-primary" required>Submit (Post)</button>
              <button formmethod="get" type="submit" value="submit" class="btn btn-primary" required>Submit (GET)</button>
            </div>
          </div>
        </form>
      </div>
    </div>
  </div>

</body>

</html>