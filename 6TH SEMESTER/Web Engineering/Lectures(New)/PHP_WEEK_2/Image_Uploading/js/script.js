$(document).ready(function(){
	display_image();
	
	function display_image(){
		$.ajax({
			url: 'get_image.php',
			type: 'POST',
			data: {res: 1},
			success: function(data){
				$('#result').html(data);
			}
		});
	}
	
	$('#upload').on('click', function(){
		var image = $('#image');
		var image_data = image.prop('files')[0];
 
		var formData = new FormData();
		formData.append('image', image_data);
		$.ajax({
			url: "upload.php",
			type: "POST",
			data: formData,
			contentType:false,
			cache: false,
			processData: false,
			success: function(data){
				if(data == "success"){
					alert('Image Uploaded');
					display_image();
				}else if(data == "error1"){
					alert("Please upload file first!");
				}else if(data == "error2"){
					alert('Wrong Image format');
				}else if(data == "error3"){
					alert('File too large to upload');
				}
			}
		});
	});
});