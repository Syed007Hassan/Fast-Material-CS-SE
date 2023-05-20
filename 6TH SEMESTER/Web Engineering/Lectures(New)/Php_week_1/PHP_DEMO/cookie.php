<!DOCTYPE html>
<?php
setcookie("test_cookie", "test", time() + 10, '/');
?>
<html>
<body>

<?php
if(count($_COOKIE) > 0) {
    echo "Cookies are enabled.";
} else {
    echo "Cookies are disabled but why.";
}
?>

</body>
</html>