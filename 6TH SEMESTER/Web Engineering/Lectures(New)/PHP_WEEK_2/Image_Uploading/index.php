<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8" name="viewport" content="width=device-width, initial-scale=1"/>
		<link rel="stylesheet" type="text/css" href="css/bootstrap.css" />	
	</head>
<body>
	<nav class="navbar navbar-default">
		<div class="container-fluid">
		</div>
	</nav>
	<div class="col-md-3"></div>
	<div class="col-md-6 well">
		<h3 class="text-primary">PHP - Ajax Image Upload</h3>
		<hr style="border-top:1px dotted #ccc;"/>
		<div class="col-md-4">
			<form>
				<div class="form-group">
					<input type="file" id="image" class="form-control"/>
				</div>
				<br />
				<center><button type="button" class="btn btn-primary" id="upload">Upload</button></center>
			</form>
		</div>
		<div class="col-md-8" id="result" style="padding:10px; border:1px solid #000;"></div>
	</div>
<script src="js/jquery-3.2.1.min.js"></script>
<script src="js/script.js"></script>
</body>
</html>