<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Untitled Document</title>
</head>

<body>



<?php
$name = $_POST['name'];
$age = $_POST['age'];
$salary = $_POST['salary'];


$con = mysqli_connect('localhost','root','','hussain');

$query ="INSERT INTO `hussaintbl`(`Name`, `Age`, `Salary`) VALUES ('$name','$age','$salary')";

$run = mysqli_query($con, $query);


if($run)
{
	echo "Your data has been submitted sucessfully!";
}
else
{
	echo "Connection erro!!!";
}



?>
</body>
</html>