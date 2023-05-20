<!DOCTYPE html>

<head>

	<title>Untitled Document</title>
</head>

<body>


	<!--
<form action="Sent.php" method="post">

<input type="text" name="name"/> <br/>
<input type="text" name="age"/> <br/>
<input type="text" name="salary"/> <br/>

<input type="submit" name="Submit"/> <br/>

</form>

-->
	<?php

	$con = mysqli_connect('localhost', 'root', '', 'hussain');

	function ShowData()
	{
		global $con;
		$query = "SELECT * FROM `hussaintbl`";
		$run = mysqli_query($con, $query);
	?>
		<table border="1">
			<tr>
				<td>Name</td>
				<td>Age</td>
				<td>Salary</td>
			</tr>
			<?php
			if ($run) {
				while ($data = mysqli_fetch_assoc($run)) {

			?>
					<tr>
						<td style="border:2px solid red;"><?php echo $data['Name'] ?> </td>
						<td style="border:2px solid red;"><?php echo $data['Age'] ?> </td>
						<td style="border:2px solid red;"><?php echo $data['Salary'] ?> </td>
					</tr>

				<?php

				}
				?>
				</tr>

		</table>
<?php
			} else {
				echo "Error of Connection";
			}
		}


?>

<?php
ShowData();
?>

</body>

</html>