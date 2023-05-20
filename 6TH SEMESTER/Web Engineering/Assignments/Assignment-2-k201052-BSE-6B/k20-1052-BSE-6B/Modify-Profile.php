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
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    <link rel="stylesheet" href="Check.css">
    <title>Document</title>
  </head>
  <body>
    <header class="header">
      <div id="menu-btn" class="fas fa-bars"></div>

      <a href="#" class="logo"><span>Fast</span> Medical Services</a>
      <nav class="navbar">
         
      <nav class="navbar">
        <a href="profile.php">Profile</a>
        <a href="ModifyProfile.php">Add Details</a>
        

        <a href="Infromation.php">Information</a>
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
                  <button type="button" class="btn" style="max-height:5rem;" data-toggle="modal" data-target="#exampleModal" data-whatever="@mdo">Appointment</button>
                  <div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabelq" aria-hidden="true">
                  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="exampleModalLabel">Book Apointment</h5>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>
      <div class="modal-body">
        <form>
          <div class="form-group">
            <label for="recipient-name" class="col-form-label">Patitent ID</label>
            <input type="text" class="form-control" id="PID">
          </div>
          <div class="form-group">
            <label for="recipient-name" class="col-form-label">Date</label>
            <input type="text" class="form-control" id="Date">
          </div>
          <!-- <div class="form-group">
            <label for="message-text" class="col-form-label">Message:</label>
            <textarea class="form-control" id="message-text"></textarea>
          </div> -->
        </form>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
        <button type="button" class="btn btn-primary">Book</button>
      </div>
    </div>
  </div>
</div>
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
            <div class="card mb-4" style=" height: 40rem; ">
            <form action="ModifyProfile.php" method="post">
              <div class="card-body">
                <div class="row">
                  <div class="col-sm-2">
                    <p class="mb-5">Full Name</p>
                    <?php
                    if($_SERVER['REQUEST_METHOD']=="POST")
                    {
                      if(isset($_POST['DName'])){
                      $Fullname=$_POST['Fullname'];
                      $DID=$_POST['DName'];
                      $Expertise=$_POST['Expertise'];
                      $City=$_POST['City'];
                      $password=$_POST['password'];

                      $query2="UPDATE doctors
                      SET DName='$DID',Fullname='$Fullname',Password='$password', Expertise = '$Expertise', City = '$City'
                      WHERE DName = '$DN';";
                      try{$res=mysqli_query($conn,$query2);}
                      catch(Exception $e) {
                           echo"<div class='alert alert-danger' role='alert'>
  No Update!
</div>";
  
}
                      if($res)
                      {
                        $_SESSION['name']=$DID;
                        echo"<div class='alert alert-success' role='alert'>
  This is a success alert—check it out!
</div>";
                      }else{
                        echo"<div class='alert alert-danger' role='alert'>
  No Update!
</div>";

                      }}
                      if(isset($_POST['avail'])){
                        $date=$_POST['avail'];
                        $dateF= date('Y-m-d', strtotime($date));
                        
                        $query2="Insert into `avail`(Date,DName) values('$dateF','$DN');";

                        $res2=mysqli_query($conn,$query2);
                        if($res)
                        {
                          echo "<div class='alert alert-danger' role='alert'>
 Updated
</div>";
                        }


                      }

                    }
                     ?>
                  </div>
                  <div class="col-sm-5">
                     <input name="Fullname" id="Fullname" type="text" class="form-control" aria-label="Large" aria-describedby="inputGroup-sizing-sm">
                  </div>
                </div>
                <hr />
                <div class="row">
                  <div class="col-sm-2">
                    <p class="mb-5">Doctor's ID</p>
                  </div>
                  <div class="col-sm-5">
                    <input type="text" name="DName" id="DName" class="form-control" aria-label="Large" aria-describedby="inputGroup-sizing-sm">
                  </div>
                </div>
                <hr />
                <div class="row">
                  <div class="col-sm-2">
                    <p class="mb-5">Expertise</p>
                  </div>
                  <div class="col-sm-5">
                    <input type="text" name="Expertise" id="Expertise" class="form-control" aria-label="Large" aria-describedby="inputGroup-sizing-sm">
                  </div>
                </div>
                <hr />
                <div class="row">
                  <div class="col-sm-2">
                    <p class="mb-5">City</p>
                  </div>
                  <div class="col-sm-5">
                    <input type="text" name="City" id="City" class="form-control" aria-label="Large" aria-describedby="inputGroup-sizing-sm">
                  </div>
                </div>
                <hr />
                <div class="row">
                  <div class="col-sm-2">
                    <p class="mb-5">Password</p>
                  </div>
                  <div class="col-sm-5">
                    <input type="text" name="password" id="password" class="form-control" aria-label="Large" aria-describedby="inputGroup-sizing-sm">
                  </div>
                </div>
                <hr/>
                 <div class="row">
                    <div class="col-sm-5"></div>
                  <div class="col-sm-6">
                   <button type="submit" class="btn btn-primary btn-lg">Submit</button>
                  </div>
                </div>
                <hr />
              </div> 
              </form>
              <!-- aa -->
            </div>
            <div class="row" >
              <div class="col-md-12" >
                <div class="card mb-4 mb-md-0">
                  <div class="card-body">
                    <p class="mb-4">
                      <span class="text-primary font-italic me-1"
                        >Update</span
                      >
                       Availability
                    </p>
                    
                    <p class="mt-4 mb-1" style="font-size: 0.77rem">
                      Day
                    </p>
                    <form action="ModifyProfile.php" method="post">
                    <input type="date" name="avail" id="avail">
                  <input type="submit"  value="Update"></form>
                    <p class="mt-4 mb-1" style="font-size: 0.77rem">Customer5</p>
                    <div class="progress rounded" style="height: 5px">
                      <div
                        class="progress-bar"
                        role="progressbar"
                        style="width: 89%"
                        aria-valuenow="89"
                        aria-valuemin="0"
                        aria-valuemax="100"
                      ></div>
                    </div>
                    <p class="mt-4 mb-1" style="font-size: 0.77rem">
                      Total Checkups
                    </p>
                    <div class="progress rounded" style="height: 5px">
                      <div
                        class="progress-bar"
                        role="progressbar"
                        style="width: 55%"
                        aria-valuenow="55"
                        aria-valuemin="0"
                        aria-valuemax="100"
                      ></div>
                    </div>
                    <p class="mt-4 mb-1" style="font-size: 0.77rem">
                      Best Services
                    </p>
                    <div class="progress rounded mb-2" style="height: 5px">
                      <div
                        class="progress-bar"
                        role="progressbar"
                        style="width: 66%"
                        aria-valuenow="66"
                        aria-valuemin="0"
                        aria-valuemax="100"
                      ></div>
                    </div>
                  </div>
                </div>
              </div>
              <!-- aaa -->
          </div>
        </div>
      </div>
    </section>
    
      <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
   
  </body>
</html>
