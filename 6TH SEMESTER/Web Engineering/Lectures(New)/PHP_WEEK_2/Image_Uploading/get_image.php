<?php
	require_once 'conn.php';
	
	$query=mysqli_query($conn, 'SELECT * FROM `image`') or die(mysqli_error());
	while($fetch=mysqli_fetch_array($query)){
		echo "<img src='".$fetch['location']."' style='float:left; margin:15px;' width='100' height='100'/>";
	}
?>