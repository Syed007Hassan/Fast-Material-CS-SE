<?php
session_start();

require_once('config.php');

$user_id = 2;
$query = "SELECT * FROM users WHERE id = ?";
$stmt = $pdo->prepare($query);
$stmt->execute([$user_id]);
$user = $stmt->fetch();

if (isset($_POST['submit'])) {

    $name = $_POST['name'];
    $email = $_POST['email'];

    $query = "UPDATE users SET name = ?, email = ? WHERE id = ?";
    $stmt = $pdo->prepare($query);
    $stmt->execute([$name, $email, $user_id]);

    $file_name = $_FILES['profile_picture']['name'];
    $file_size = $_FILES['profile_picture']['size'];
    $file_tmp = $_FILES['profile_picture']['tmp_name'];
    $file_type = $_FILES['profile_picture']['type'];

    $file_ext = strtolower(end(explode('.', $file_name)));
    $allowed_exts = array('jpg', 'jpeg', 'png', 'gif');
    if (!in_array($file_ext, $allowed_exts)) {
        $error_msg = 'File must be an image (JPG, JPEG, PNG, or GIF).';
    } else {

        $upload_dir = 'profile_pictures/';
        $file_new_name = uniqid() . '.' . $file_ext;
        $upload_path = $upload_dir . $file_new_name;
        
        move_uploaded_file($file_tmp, $upload_path);

        $query = "UPDATE users SET profile_picture = ? WHERE id = ?";
        $stmt = $pdo->prepare($query);
        $stmt->execute([$upload_path, $user_id]);

        header('Location: profile.php?success=1');
        exit();
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>My Profile</title>
</head>
<body>
    <h1>My Profile</h1>
    <?php if (isset($_GET['success'])): ?>
        <p class="success">Profile updated successfully.</p>
    <?php endif; ?>
    <form method="POST" enctype="multipart/form-data">
        <p>
            <label>Name:</label>
            <input type="text" name="name" value="<?php echo $user['name']; ?>">
        </p>
        <p>
            <label>Email:</label>
            <input type="email" name="email" value="<?php echo $user['email']; ?>">
        </p>
        <p>
            <label>Profile Picture:</label>
            <?php if ($user['profile_picture']): ?>
            <img src="<?php echo $user['profile_picture']; ?>" alt="Profile Picture">
            </p>
            <p>
                <label>Upload New Picture:</label>
                <input type="file" name="profile_picture">
            </p>
            <?php if (isset($error_msg)): ?>
                <p class="error"><?php echo $error_msg; ?></p>
            <?php endif; ?>
            <p>
                <button type="submit" name="submit">Save Changes</button>
            </p>
            <?php endif; ?>
        </p>
    </form>
</body>
</html>
                

<style>
    img{
        width: 70px;
        height: 70px;
    }
</style>