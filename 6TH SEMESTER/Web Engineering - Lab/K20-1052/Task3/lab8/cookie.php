<?php



if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $name = $_POST["name"];
    $pwd = $_POST["pwd"];

    setcookie("user", $name, time() + (1 * 10), "/");

    header("Location: scond.php");
}


// if ($_SERVER["REQUEST_METHOD"] == "GET") {
//     $name = $_GET["name"];
//     $password = $_GET["password"];

//     setcookie("me", $name, time() + (1 * 10), "/");

//     header("Location: scond.php");
// }

?>
<!doctype html>
<html>

<head>
    <meta charset="utf-8">
    <title>Cookie</title>
    <link rel="stylesheet" href="./bootstrap-5.0.2-dist/css/bootstrap.min.css" />
</head>

<body>
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-6">
                <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post" enctype="multipart/form-data">
                    <div class="card mt-5">
                        <div class="card-header">
                            <h3 class="card-title">Cookie Post</h3>
                        </div>
                        <div class="card-body">
                            <div class="form-group mb-3">
                                <label for="name" class="form-label">Name</label>
                                <input type="text" name="name" id="name" class="form-control" required>
                            </div>
                            <div class="form-group mb-3">
                                <label for="pwd" class="form-label">Password</label>
                                <input type="password" name="pwd" id="pwd" class="form-control">
                            </div>
                        </div>
                        <div class="card-footer text-end">
                            <button type="submit" value="submit" class="btn btn-primary" required>Submit</button>
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>


    <div class="container mt-5">

        <div class="row justify-content-center">
            <div class="col-md-6">
                <form action="<?php $_SERVER['PHP_SELF'] ?>" method="get" enctype="multipart/form-data">

                    <div class="card mt-5">
                        <div class="card-header">
                            <h3 class="card-title">Cookie Get</h3>
                        </div>
                        <div class="card-body">
                            <div class="form-group">
                                <label class="form-label" for="name">Name</label>
                                <input type="text" class="form-control" name="name" id="name" aria-describedby="helpId" placeholder="Enter your name">
                                <small id="helpId" class="form-text text-muted">Help text</small>
                            </div>
                            <div class="form-group">
                                <label class="form-label" for="password">Password</label>
                                <input type="password" class="form-control" name="password" id="password" aria-describedby="helpId" placeholder="">
                                <small id="helpId" class="form-password_hash text-muted">Help text</small>
                            </div>

                        </div>
                        <div class="card-footer text-end">
                            <button class="btn btn-danger" type="submit">Submit</button>
                        </div>

                    </div>


                </form>
            </div>
        </div>

    </div>



</body>

</html>