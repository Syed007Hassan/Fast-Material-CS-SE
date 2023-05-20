<?php
	include 'database.php';
	$name=$_POST['name'];
	$email=$_POST['email'];
	$phone=$_POST['phone'];
	$city=$_POST['city'];
	$sql = "INSERT INTO `user_data`( `name`, `email`, `phone`, `city`)
	VALUES ('$name','$email','$phone','$city')";
/*
The post request works by sending data through variables
 in form of parameter to the other file and the other file
  take the parameters and run the insert or update query
   through it. The if the query run successfully it returns
    the variable in the name of status_code.
     If status_code is 200 it means query ran successfully
      if status code is 201 it means it failed.
*/


	if (mysqli_query($conn, $sql)) {
		echo json_encode(array("statusCode"=>200));
	}
	else {
		echo json_encode(array("statusCode"=>201));
	}
	mysqli_close($conn);
