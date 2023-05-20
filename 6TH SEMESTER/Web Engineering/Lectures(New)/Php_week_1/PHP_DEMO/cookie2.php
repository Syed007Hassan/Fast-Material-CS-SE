<!DOCTYPE html>
<?php
$cookie_name = "user";
$cookie_value = "Alex Porter";
//array(key => value)
setcookie($cookie_name, $cookie_value, time() + (1 * 10), "/");

?>
<html>
<body>

<?php
if(!isset($_COOKIE[$cookie_name])) {
     echo "Cookie named '" . $cookie_name . "' is not set!";
} else {
     echo "Cookie '" . $cookie_name . "' is set!<br>";
     echo "Value is: " . $_COOKIE[$cookie_name];
}
?>

<p><strong>Note:</strong> You might have to reload the page to see the new value of the cookie.</p>

</body>
</html>