<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>Untitled Document</title>
</head>

<body>

    <?php



    session_start();



    if (isset($_SESSION["user"]) && isset($_SESSION["pwd"])) {
        echo "Welcome " . $_SESSION["user"];
        echo "<br>";
    } else {
        echo "Session is not set";
    }

    if (isset($_COOKIE["user"])) {
        echo "Welcome " . $_COOKIE["user"];
        echo "<br>";
    } else {
        echo "Cookie is not set";
    }

    if (isset($_COOKIE["me"])) {
        echo " Welcome " . $_COOKIE["me"];
        echo "<br>";
    } else {
        echo "Cookie is not set";
    }

    ?>


</body>

</html>