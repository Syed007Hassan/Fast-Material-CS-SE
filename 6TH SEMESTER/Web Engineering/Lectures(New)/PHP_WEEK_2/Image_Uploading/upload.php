<?php
	require_once 'conn.php';
	
	if(!empty($_FILES['image'])){
		
		$image_name = $_FILES['image']['name'];
		$image_temp = $_FILES['image']['tmp_name'];
		$image_size = $_FILES['image']['size'];
		
		$exp = explode(".", $image_name);
		$ext = end($exp);
		$allowed_ext = array('jpg', 'jpeg', 'png','PNG');
			
		if(in_array($ext, $allowed_ext)){
			$image = time().'.'.$ext;
			$location = "upload/".$image;
			if($image_size < 5242880){
				move_uploaded_file($image_temp, $location);
				mysqli_query($conn, "INSERT INTO `image` VALUES('', '$image', '$location')") or die(mysqli_error());
				echo "success";
			}else{
				echo "error3";
			}
		}else{
			echo "error2";
		}
	}else{
		echo "error1";
	}	

?>