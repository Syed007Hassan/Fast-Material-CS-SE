<?php
session_start();
?>

<?php
    if(!isset($_SESSION['pass'])){

       header("Location: infromation.php");
    }
  ?>

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <link rel="stylesheet" href="Check.css" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link
      rel="stylesheet"
      href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css"
      integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65"
      crossorigin="anonymous"
    />
    <link
      rel="stylesheet"
      href="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.css"
    />
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.3.0/css/all.min.css"
    />
    <script
      src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.min.js"
      integrity="sha384-cuYeSxntonz0PPNlHhBs68uyIAVpIIOZZ5JqeqvYYIcEL727kskC66kF92t6Xl2V"
      crossorigin="anonymous"
    ></script>
    <title>Document</title>
  </head>
  <body>
    <header class="header">
      <div id="menu-btn" class="fas fa-bars"></div>

      <a href="#" class="logo"><span>Fast</span> Medicos</a>
      <nav class="navbar">
        <a href="profile.php">Profile</a>
        <a href="ModifyProfile.php">Add Details</a>
        

        <a href="Infromation.html">Information</a>
        
      </nav>
    </header>
    <?php
    include 'connection.php';
    $DN=$_SESSION['name'];
    $query="select * from doctors where `DName`='$DN'";
    $res=mysqli_query($conn,$query);

    for($i=0;$i<mysqli_num_rows($res);$i++)
    {
      $row=mysqli_fetch_assoc($res);

    }
    ?>
    <section style="background-color: #eee ">
      <div class="container py-5">
        <div class="row">
          <div class="col">
            <nav aria-label="breadcrumb" class="bg-light rounded-3 p-3 mb-4">
              <ol class="breadcrumb mb-0">
                <li class="breadcrumb-item"><a href="#">Home</a></li>
                <li class="breadcrumb-item"><a href="#">User</a></li>
                <li class="breadcrumb-item active" aria-current="page">
                  User Profile
                </li>
              </ol>
            </nav>
          </div>
        </div>

        <div class="row">
          <div class="col-lg-4">
            <div class="card mb-4">
              <div class="card-body text-center">
                <img
                  src="./images/doctor.png"
                  alt="avatar"
                  class="rounded-circle img-fluid"
                  style="width: 24.5rem"
                />
                
                <?php
                echo "<h5 class='my-3'>".$_SESSION['name2']."</h5>";
    ?>
    <?php
                echo "<p class='text-muted mb-1'>".$row['Expertise']."</p>";
                echo"<p class='text-muted mb-4'>".$row['City']."</p>";
    ?>
                <div class="d-flex justify-content-center mb-2">
                  <button type="button" class="btn btn-primary">Follow</button>
                  <button type="button" class="btn btn-outline-primary ms-1">
                    Message
                  </button>
                </div>
              </div>
            </div>
            <div class="card mb-4 mb-lg-0">
              <div class="card-body p-0">
                <ul class="list-group list-group-flush rounded-3">
                  <li
                    class="list-group-item d-flex justify-content-between align-items-center p-3"
                  >
                    <i class="fas fa-globe fa-lg text-warning"></i>
                    <p class="mb-0">Doctors.com</p>
                  </li>
                  <li
                    class="list-group-item d-flex justify-content-between align-items-center p-3"
                  >
                    <i class="fab fa-github fa-lg" style="color: #333333"></i>
                    <p class="mb-0">Doctors.com</p>
                  </li>
                  <li
                    class="list-group-item d-flex justify-content-between align-items-center p-3"
                  >
                    <i class="fab fa-twitter fa-lg" style="color: #55acee"></i>
                    <p class="mb-0">@Doctors.com</p>
                  </li>
                  <li
                    class="list-group-item d-flex justify-content-between align-items-center p-3"
                  >
                    <i
                      class="fab fa-instagram fa-lg"
                      style="color: #ac2bac"
                    ></i>
                    <p class="mb-0">Doctors.com</p>
                  </li>
                  <li
                    class="list-group-item d-flex justify-content-between align-items-center p-3"
                  >
                    <i
                      class="fab fa-facebook-f fa-lg"
                      style="color: #3b5998"
                    ></i>
                    <p class="mb-0">Doctors.com</p>
                  </li>
                </ul>
              </div>
            </div>
          </div>
          <div class="col-lg-8" >
            <div class="card mb-4" style=" height: 40rem;">
              <div class="card-body">
                <div class="row">
                  <div class="col-sm-3">
                    <p class="mb-5"  style='font-size: 1.77rem'>Full Name</p>
                  </div>
                  <div class="col-sm-9">
                    <?php
                    echo"<p class='text-muted mb-0'  style='font-size: 1.77rem'> ".$row['Fullname']."</p>";?>
                    
                  </div>
                </div>
                <hr />
                <div class="row">
                  <div class="col-sm-3">
                    <p class="mb-5"  style='font-size: 1.77rem'>Expertise</p>
                  </div>
                  <div class="col-sm-9">
                   <?php
                    echo"<p class='text-muted mb-0'  style='font-size: 1.77rem'> ".$row['Expertise']."</p>";?>
                  </div>
                </div>
                <hr />
                <div class="row">
                  <div class="col-sm-3">
                    <p class="mb-5"  style='font-size: 1.77rem'>ID</p>
                  </div>
                  <div class="col-sm-9">
                    <?php
                    echo"<p class='text-muted mb-0'  style='font-size: 1.77rem'> ".$row['DName']."</p>";?>
                  </div>
                </div>
                <hr />
                <div class="row">
                  <div class="col-sm-3">
                    <p class="mb-5"  style='font-size: 1.77rem'>Password</p>
                  </div>
                  <div class="col-sm-9">
                   <?php
                    echo"<p class='text-muted mb-0'  style='font-size: 1.77rem'> ".$row['Password']."</p>";?>
                  </div>
                </div>
                <hr />
                <div class="row">
                  <div class="col-sm-3">
                    <p class="mb-0"  style='font-size: 1.77rem'>City</p>
                  </div>
                  <div class="col-sm-9">
                    <?php
                    echo"<p class='text-muted mb-0'  style='font-size: 1.77rem'> ".$row['City']."</p>";?>
                  </div>
                </div>
              </div>
            </div>
            <div class="row" >
              <div class="col-md-12" >
                <div class="card mb-4 mb-md-0">
                  <div class="card-body">
                    <p class="mb-4" style='font-size: 2rem'>
                      <span class="text-primary font-italic me-1"
                         >Appointment</span
                      >
                       View
                    </p>

                    <?php
    
    $query1="select * from appoint where `DName`='$DN'";
    $res1=mysqli_query($conn,$query1);

    for($i=0;$i<mysqli_num_rows($res1);$i++)
    {
      $row1=mysqli_fetch_assoc($res1);
       echo "<p class='mb-1' style='font-size: 1.77rem'> Patient ID: ".$row1['PName']." <br>Date: ".$row1['Date']."</p>";
       echo"<div class='progress rounded' style='height: 5px'>
                      <div
                        class='progress-bar'
                        role='progressbar'
                        style='width: 80%'
                        aria-valuenow='80'
                        aria-valuemin='0'
                        aria-valuemax='100'
                      ></div>
                    </div>";
                    echo "<p class='mt-4 mb-1' style='font-size: 0.77rem'>
                      
                    </p>";

    }
    ?>
    

                    
    
                    
                    
                    
                    
                    
                    
                    </div>
                  </div>
                </div>
              </div>
              <!-- aaa -->
          </div>
        </div>
      </div>
    </section>
    <script src="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.js"></script>
    <script src="script.js"></script>
  </body>
</html>
