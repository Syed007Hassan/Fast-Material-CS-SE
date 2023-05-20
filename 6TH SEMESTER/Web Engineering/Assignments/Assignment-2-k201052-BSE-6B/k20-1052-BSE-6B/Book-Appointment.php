<?php
session_start();
?>
<?php
    if(!isset($_SESSION['pass'])){

       header("Location: infromation.php");
    }
  ?>
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
    <link rel="stylesheet" href="assets/css/datepicker.css">
    <link rel="stylesheet" href="assets/css/style.css">
     <link
      rel="stylesheet"
      href="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.css"
    />
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.3.0/css/all.min.css"
    />
     <link rel="stylesheet" href="Check.css" />
  </head>

  

    <body >
       <header class="header">
      <div id="menu-btn" class="fas fa-bars"></div>

      <a href="#" class="logo"><span>Fast</span>Medicos</a>
      <nav class="navbar">
        <a href="SearchDoctor.php">Search Doctor</a>
        <a href="BookAppointment.php">Book  Appointment</a>
        
      </nav>
    
      <!-- <div class="C" id="login-btn">
        <button class="btn">Login</button>
        <i class="far fa-user"></i>
      </div> -->
    </header>
      <div class="inner-layer"  style="background-image: url(./images/image41.jpg);">
          <div class="container" >
            <div class="row no-margin">
                <div class="col-sm-7">
                    <div class="content">
                        <h1 style="font-size: 7rem; ">Book You Slot Now and Save your time</h1>
                          <?php


      if($_SERVER['REQUEST_METHOD']=="POST")
      {

      
      include 'connection.php';
      if($conn){
        $date=$_POST['Date'];
        $PName=$_SESSION["name"];
        $DID=$_POST['DID'];
        $City=$_POST['City'];
       $dateF= date('Y-m-d', strtotime($date));

         $query1="select Date from `avail` where DName='$DID'";
         
         $res1=mysqli_query($conn,$query1);
        $arr=array();
        for($i=0;$i<mysqli_num_rows($res1);$i++)
        {
          $row = mysqli_fetch_assoc($res1);
          array_push($arr,$row['Date']);
          //echo $dateF . $row['Date'];
        }
        
         if(!in_array($dateF,$arr)){
       // $r=date('Y-m-d', strtotime($res1));
       // echo "<h1>".$date."</h2>";
        //$q=($dateF==$row['Date']);
        $i="UK1";
        //$query1="DELETE FROM `appoint` WHERE `PName` = '$i';";
          $query="INSERT INTO `appoint` (`Date`, `DName`, `PName`)  VALUES ('$dateF', '$DID', '$PName'); ";

       
       try{
        $res=mysqli_query($conn,$query);
        if($res)
        {
          //print in_array($dateF,$arr);
          //print_r ($arr);
           echo "<h1 style='background-color:red;'>Booked</h1>";
        }
       }  
       catch(exception $e)
       {
        
           //$error = mysqli_error($conn);
           echo "<h1 style='background-color:red;'>No Doctor Found</h1>";
           
        

       }

        
        
          
      }
    if(in_array($dateF,$arr)){

      echo "<h1 style='background-color:red;'>Not available</h1>";

    }}}
      ?>
                        
                        <h2>For Help Call : xxxxxxxxx</h2>
                    </div>
                </div>
                <div class="col-sm-5" style="font-size: 7rem; margin-top: 10rem; height: 20rem;">
                <form action="BookAppointment.php" method="POST">
                    <div class="form-data">
                        <div class="form-head">
                            <h2 >Book Appointemnt</h2>
                        </div>
                        <div class="form-body">
                            <div class="row form-row">
                              <input type="text" placeholder="Enter Patient's name" class="form-control" id="FName" name="">
                            </div>
                            
                          <div class="row form-row">
                              <input id="date" type="date" placeholder="Appointment Date" class="form-control" id="Date" name="Date">
                            </div>
                            
                            <h6>Doctor Details</h6>

                            <div class="row form-row">
                                <div class="col-sm-6">
                                  <input type="text" placeholder="Enter Doctor ID" class="form-control" id="DID" name="DID">
                                </div>
                                <div class="col-sm-6">
                                  <input type="text" placeholder="Enter City" class="form-control" id="City" name="City">
                                </div>
                            </div>
                            

                            <div class="row form-row">
                              <button class="btn btn-success btn-appointment">
                                Book Appointment
                              </button>
                              
                            </div>

                        </div>
                    </div>
                  </form>
                </div>
            </div>
          </div>
      </div>
      
    </body>
  
    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="assets/js/jquery-3.3.1.min.js"></script>
    <script src="assets/js/popper.min.js"></script>
    <script src="assets/js/bootstrap.min.js"></script>
    <script src="assets/js/bootstrap-datepicker.js"></script>

    <script>
      $(document).ready(function(){
          $("#dat").datepicker();
      })
    </script>
    
  </body>
</html>