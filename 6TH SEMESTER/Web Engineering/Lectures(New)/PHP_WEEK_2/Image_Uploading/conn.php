<?php
	$conn = mysqli_connect('localhost', 'root', '', 'db_ajax_image');
	
	if(!$conn){
		die("Error: Failed to connect to database!");
	}
?>