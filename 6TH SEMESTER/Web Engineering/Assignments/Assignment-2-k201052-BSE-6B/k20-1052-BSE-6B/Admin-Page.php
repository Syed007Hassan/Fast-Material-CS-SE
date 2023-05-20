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
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <link
      rel="stylesheet"
      href="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.css"
    />
    <link
      rel="stylesheet"
      href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css"
      integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh"
      crossorigin="anonymous"
    />
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.3.0/css/all.min.css"
    />
    <link rel="stylesheet" href="Check.css" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>
  </head>
  <body>
    <header class="header">
      <div id="menu-btn" class="fas fa-bars"></div>

      <a href="#" class="logo"><span>Fast</span>Medicos</a>
      <nav class="navbar">
        

        
      </nav>
     
    </header>
    <section class="home" id="home">
      <h1 class="home-parallax" data-speed="-2">Admin Panel</h1>
      <img
        src="./images/image0.jpg"
        class="home-parallax"
        data-speed="5"
        alt=""
      />
     
    </section>

    <section class="services" id="services">
      <h1 class="heading">Admin <span> Details </span></h1>
      <div class="box-container">
        <div class="swiper-slide box">
          <i class="fas fa-user-md"></i>
          <h3>Modify Doctors</h3>
          <p>
            ► Doctor Name <br />
            ► Doctor ID<br />
            ► Doctor City<br />
            ► Doctor Password<br />
          </p>
            <a
            href=""
            class="btn"
            data-toggle="modal"
            data-target="#exampleModal"
            data-whatever="@mdo"
          >
            Modify Doctors</a
          >

          <?php

          if($_SERVER['REQUEST_METHOD']=="POST")
          {
            include 'connection.php';
            
            
            if (isset($_POST['MPID'])) {
              $MPID=$_POST['MPID'];
              $MPName=$_POST['MPName'];
              $MPPassword=$_POST['MPPassword'];
              $query="Update `patients` SET `FullName`='$MPName',`Password`='$MPPassword'where `PName`='$MPID' ";

              $res=mysqli_query($conn,$query);

              if($res)
              {
                echo "<div class='alert alert-success' role='alert'>
 Added
</div>";
              }else{
                 echo "<div class='alert alert-danger' role='alert'>
 Not Deleted
</div>";

              }
              
                } 
           if (isset($_POST['MDID'])) {
              
              $MDID=$_POST['MDID'];
              $MDName=$_POST['MDName'];
              $MExpertise=$_POST['MExpertise'];
              $MDPassword=$_POST['MDPassword'];
              $MDcity=$_POST['MDcity'];
              $query="Update `doctors` SET `Password`='$MDPassword',Expertise='$MExpertise',`Fullname`='$MDName',City='$MDcity'where `DName`='$MDID'; ";

              $res=mysqli_query($conn,$query);

              if($res)
              {
                echo "<div class='alert alert-success' role='alert'>
 Added
</div>";
              }else{
                 echo "<div class='alert alert-danger' role='alert'>
 Not Deleted
</div>";

              }
              
                } 

            if(isset($_POST['DCityname']))
            {
            
              $DCityname=$_POST['DCityname'];
              $query="Delete from `city` where Cname='$DCityname'";

              $res=mysqli_query($conn,$query);

              if($res)
              {
                echo "<div class='alert alert-success' role='alert'>
 Deleted
</div>";
              }else{
                 echo "<div class='alert alert-success' role='alert'>
 Not Deleted
</div>";

              }
            }  
            if(isset($_POST['DDID']))
            {
              
              $DDID=$_POST['DDID'];
              $query="Delete from `doctors` where `DName`='$DDID'";

              $res=mysqli_query($conn,$query);

              if($res)
              {
                echo "<div class='alert alert-success' role='alert'>
 Deleted
</div>";
              }else{
                 echo "<div class='alert alert-success' role='alert'>
 Not Deleted
</div>";
              
            }}
            if(isset($_POST['DPID']))
            {
              // echo"umer";
              $DPID=$_POST['DPID'];
              $query="Delete from `patients` where `PName`='$DPID'";

              $res=mysqli_query($conn,$query);

              if($res)
              {
                echo "<div class='alert alert-success' role='alert'>
 Added
</div>";
              }
              
              else{
                 echo "<div class='alert alert-success' role='alert'>
 Not Added
</div>";

              }
              // echo"umer";
              
            } 
             if(isset($_POST['ADID']))
            {
              
              $AFName=$_POST['AFName'];
              $ADID=$_POST['ADID'];
              $AExpertise=$_POST['AExpertise'];
              $APassword=$_POST['APassword'];
              $ACity=$_POST['ACity'];

               $query="Insert into `doctors`(DName,Fullname,Password,Expertise,City) values ('$ADID','$AFName','$APassword','$AExpertise',' $ACity')";

              $res=mysqli_query($conn,$query);
               if($res)
              {
                echo "<div class='alert alert-success' role='alert'>
 Added
</div>";
              }
              
              else{
                 echo "<div class='alert alert-success' role='alert'>
 Not Added
</div>";

              }
              
              
            }   
             if(isset($_POST['APID']))
            {
              
              $APID=$_POST['APID'];
              $ADname=$_POST['ADname'];
              $APPassword=$_POST['APPassword'];

              $query="Insert into `patients`(PName,FullName,Password) values ('$APID','$ADname',' $APPassword')";

              $res=mysqli_query($conn,$query);


               if($res)
              {
                echo "<div class='alert alert-success' role='alert'>
                Deleted
                </div>";
              }
              
              else{
                 echo "<div class='alert alert-success' role='alert'>
                  Not Deleted
                      </div>";

              }
              
              
            }    
            if(isset($_POST['ACName']))
            {
              
              $ACName=$_POST['ACName'];
              $query="Insert into `city`(`Cname`) values ('$ACName')";

              $res=mysqli_query($conn,$query);

              if($res)
              {
                echo "<div class='alert alert-success' role='alert'>
 Deleted
</div>";
              }else{
                 echo "<div class='alert alert-danger' role='alert'>
 Not Deleted
</div>";

              }
              
          
              
            }  
           
          }
          
          ?>

          <div
            class="modal fade"
            id="exampleModal"
            tabindex="-1"
            role="dialog"
            aria-labelledby="exampleModalLabel"
            aria-hidden="true"
          >
            <div class="modal-dialog" role="document">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">
                    Modify Doctors
                  </h5>
                  <button
                    type="button"
                    class="close"
                    data-dismiss="modal"
                    aria-label="Close"
                  >
                    <span aria-hidden="true">&times;</span>
                  </button>
                </div>
                <div class="modal-body">
                  <form action="AdminPage.php" method="post">
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Full Name</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="MDName"
                        name="MDName"
                      />
                    </div>
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Doctor ID</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="MDID"
                        name="MDID"
                      />
                    </div>
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Expertise</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="MExpertise"
                        name="MExpertise"
                      />
                    </div>
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Password</label
                      >
                      <input
                        type="password"
                        class="form-control"
                        id="MDPassword"
                        name="MDPassword"
                      />
                    </div>
                    <!-- <div class="form-group">
                      <label for="message-text" class="col-form-label"
                        >Message:</label
                      >
                      <textarea
                        class="form-control"
                        id="message-text"
                      ></textarea>
                    </div> -->
                     <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >City</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="MDcity"
                        name="MDcity"
                      />
                    </div>
                    <button type="submit" class="btn btn-primary">
                    Update Details
                  </button>
                  </form>
                </div>
                <div class="modal-footer">
                  <button
                    type="button"
                    class="btn btn-secondary"
                    data-dismiss="modal"
                  >
                    Close
                  </button>
                  
                </div>
              </div>
            </div>
          </div>
        </div>
         <div class="swiper-slide box">
          <i class="fa-solid fa-user-nurse"></i>
          <h3>Modify Patients</h3>
          <p>
           ► Patients Name <br />
            ► Patients ID<br />
            ► Patients City<br />
            ► Patients Password<br />
          </p>
            <a
            href=""
            class="btn"
            data-toggle="modal"
            data-target="#exampleModal1"
            data-whatever="@mdo"
          >
            Modify Patients</a
          >

          <div
            class="modal fade"
            id="exampleModal1"
            tabindex="-1"
            role="dialog"
            aria-labelledby="exampleModalLabel"
            aria-hidden="true"
          >
            <div class="modal-dialog" role="document">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">
                    Update Patient Records
                  </h5>
                  <button
                    type="button"
                    class="close"
                    data-dismiss="modal"
                    aria-label="Close"
                  >
                    <span aria-hidden="true">&times;</span>
                  </button>
                </div>
                <div class="modal-body">
                  <form action="AdminPage.php" method="post">
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >FullName</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="MPName"
                        name="MPName"
                      />
                    </div>
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Patient ID</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="MPID"
                        name="MPID"
                      />
                  
                    </div>
                     <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Password</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="MPPassword"
                        name="MPPassword"
                      />
                    </div>
                     
                     
                    <!-- <div class="form-group">
                      <label for="message-text" class="col-form-label"
                        >Message:</label
                      >
                      <textarea
                        class="form-control"
                        id="message-text"
                      ></textarea>
                    </div> -->
                     <button type="submit" class="btn btn-primary">
                    Update Details
                  </button>
                  </form>
                </div>
                <div class="modal-footer">
                  <button
                    type="button"
                    class="btn btn-secondary"
                    data-dismiss="modal"
                  >
                    Close
                  </button>
                 
                </div>
              </div>
            </div>
          </div>
        </div>
         <div class="swiper-slide box">
          <i class="fa-solid fa-city"></i>
          <h3>Delete Cities</h3>
          <p>
           
          </p>
            <a
            href=""
            class="btn"
            data-toggle="modal"
            data-target="#exampleModal2"
            data-whatever="@mdo"
          >
            Delete Cities</a
          >

          <div
            class="modal fade"
            id="exampleModal2"
            tabindex="-1"
            role="dialog"
            aria-labelledby="exampleModalLabel"
            aria-hidden="true"
          >
            <div class="modal-dialog" role="document">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">
                    Delete City
                  </h5>
                  <button
                    type="button"
                    class="close"
                    data-dismiss="modal"
                    aria-label="Close"
                  >
                    <span aria-hidden="true">&times;</span>
                  </button>
                </div>
                <div class="modal-body">
                  <form action="AdminPage.php" method="post">
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >City Name</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="DCityname"
                        name="DCityname"
                      />
                    </div>
                    <!-- <div class="form-group">
                      <label for="message-text" class="col-form-label"
                        >Message:</label
                      >
                      <textarea
                        class="form-control"
                        id="message-text"
                      ></textarea>
                    </div> -->
                     <button type="submit" class="btn btn-primary">
                    Delete
                  </button>
                  </form>
                </div>
                <div class="modal-footer">
                  <button
                    type="button"
                    class="btn btn-secondary"
                    data-dismiss="modal"
                  >
                    Close
                  </button>
                 
                </div>
              </div>
            </div>
          </div>
        </div>
         <div class="swiper-slide box">
          <i class="fas fa-user-md"></i>
          <h3>Delete Doctors</h3>
          <p>
          
          </p>
            <a
            href=""
            class="btn"
            data-toggle="modal"
            data-target="#exampleModal3"
            data-whatever="@mdo"
          >
            Delete Doctors</a
          >

          <div
            class="modal fade"
            id="exampleModal3"
            tabindex="-1"
            role="dialog"
            aria-labelledby="exampleModalLabel"
            aria-hidden="true"
          >
            <div class="modal-dialog" role="document">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">
                    Delete Doctor
                  </h5>
                  <button
                    type="button"
                    class="close"
                    data-dismiss="modal"
                    aria-label="Close"
                  >
                    <span aria-hidden="true">&times;</span>
                  </button>
                </div>
                <div class="modal-body">
                  <form action="AdminPage.php" method="post">
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Doctor ID:</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="DDID"
                        name="DDID"
                      />
                    </div>
                    <!-- <div class="form-group">
                      <label for="message-text" class="col-form-label"
                        >Message:</label
                      >
                      <textarea
                        class="form-control"
                        id="message-text"
                      ></textarea>
                    </div> -->
                    <button type="submit" class="btn btn-primary">
                    Delete Doctors
                  </button>
                  </form>
                </div>
                <div class="modal-footer">
                  <button
                    type="button"
                    class="btn btn-secondary"
                    data-dismiss="modal"
                  >
                    Close
                  </button>
                  
                </div>
              </div>
            </div>
          </div>
        </div>
         <div class="swiper-slide box">
          <i class="fa-solid fa-user-nurse"></i>
          <h3>Delete Patients</h3>
          <p>
           
          </p>
            <a
            href=""
            class="btn"
            data-toggle="modal"
            data-target="#exampleModal4"
            data-whatever="@mdo"
          >
            Delete Patients</a
          >

          <div
            class="modal fade"
            id="exampleModal4"
            tabindex="-1"
            role="dialog"
            aria-labelledby="exampleModalLabel"
            aria-hidden="true"
          >
            <div class="modal-dialog" role="document">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">
                    Delete Patients
                  </h5>
                  <button
                    type="button"
                    class="close"
                    data-dismiss="modal"
                    aria-label="Close"
                  >
                    <span aria-hidden="true">&times;</span>
                  </button>
                </div>
                <div class="modal-body">
                  <form action="AdminPage.php" method="post">
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Patient ID:</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="DPID"
                        name="DPID"
                      />
                    </div>
                    <!-- <div class="form-group">
                      <label for="message-text" class="col-form-label"
                        >Message:</label
                      >
                      <textarea
                        class="form-control"
                        id="message-text"
                      ></textarea>
                    </div> -->
                    <button type="submit" class="btn btn-primary">
                    Delete 
                  </button>
                  </form>
                </div>
                <div class="modal-footer">
                  <button
                    type="button"
                    class="btn btn-secondary"
                    data-dismiss="modal"
                  >
                    Close
                  </button>
                  
                </div>
              </div>
            </div>
          </div>
        </div>
         <div class="swiper-slide box">
          <i class="fas fa-user-md"></i>
          <h3>Add Doctors</h3>
          <p>
             ► Doctor Name <br />
            ► Doctor ID<br />
            ► Doctor City<br />
            ► Doctor Password<br />
          </p>
            <a
            href=""
            class="btn"
            data-toggle="modal"
            data-target="#exampleModal5"
            data-whatever="@mdo"
          >
            Add Doctors</a
          >

          <div
            class="modal fade"
            id="exampleModal5"
            tabindex="-1"
            role="dialog"
            aria-labelledby="exampleModalLabel"
            aria-hidden="true"
          >
            <div class="modal-dialog" role="document">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">
                    Add Doctor
                  </h5>
                  <button
                    type="button"
                    class="close"
                    data-dismiss="modal"
                    aria-label="Close"
                  >
                    <span aria-hidden="true">&times;</span>
                  </button>
                </div>
                <div class="modal-body">
                  <form action="AdminPage.php" method="post">
                   <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Full Name</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="AFName"
                        name="AFName"
                      />
                    </div>
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Doctor ID</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="ADID"
                        name="ADID"
                      />
                    </div>
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Expertise</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="AExpertise"
                        name="AExpertise"
                      />
                    </div>
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Password</label
                      >
                      <input
                        type="password"
                        class="form-control"
                        id="APassword"
                        name="APassword"
                      />
                    </div>
                    <!-- <div class="form-group">
                      <label for="message-text" class="col-form-label"
                        >Message:</label
                      >
                      <textarea
                        class="form-control"
                        id="message-text"
                      ></textarea>
                    </div> -->
                     <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >City</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="ACity"
                        name="ACity"
                      />
                    </div>
                    <button type="submit" class="btn btn-primary">
                    Add Doctor
                  </button>
                  </form>
                </div>
                <div class="modal-footer">
                  <button
                    type="button"
                    class="btn btn-secondary"
                    data-dismiss="modal"
                  >
                    Close
                  </button>
                  
                </div>
              </div>
            </div>
          </div>
        </div>
        <div class="swiper-slide box">
          <i class="fa-solid fa-user-nurse"></i>
          <h3>Add Patients</h3>
          <p>
            ► Patients Name <br />
            ► Patients ID<br />
            ► Patients City<br />
            ► Patients Password<br />
          </p>
           <a
            href=""
            class="btn"
            data-toggle="modal"
            data-target="#exampleModal6"
            data-whatever="@mdo"
          >
            Add Patients</a
          >

          <div
            class="modal fade"
            id="exampleModal6"
            tabindex="-1"
            role="dialog"
            aria-labelledby="exampleModalLabel"
            aria-hidden="true"
          >
            <div class="modal-dialog" role="document">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">
                    Add Doctor
                  </h5>
                  <button
                    type="button"
                    class="close"
                    data-dismiss="modal"
                    aria-label="Close"
                  >
                    <span aria-hidden="true">&times;</span>
                  </button>
                </div>
                <div class="modal-body">
                  <form action="AdminPage.php" method="post">
                   <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >FullName</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="ADname"
                        name="ADname"
                      />
                    </div>
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Patient ID</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="APID"
                        name="APID"
                      />
                      
                    </div>
                     
                     <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >Password</label
                      >
                      <input
                        type="password"
                        class="form-control"
                        id="password"
                         name="APPassword"
                      />
                    </div>
                     
                    <!-- <div class="form-group">
                      <label for="message-text" class="col-form-label"
                        >Message:</label
                      >
                      <textarea
                        class="form-control"
                        id="message-text"
                      ></textarea>
                    </div> -->
                     <button type="submit" class="btn btn-primary">
                    Add Patients
                  </button>
                  </form>
                </div>
                <div class="modal-footer">
                  <button
                    type="button"
                    class="btn btn-secondary"
                    data-dismiss="modal"
                  >
                    Close
                  </button>
                 
                </div>
              </div>
            </div>
          </div>
        </div>
        <div class="swiper-slide box">
          <i class="fa-solid fa-city"></i>
          <h3>Add Cities</h3>
          <p>
            ► Ciy Name <br />
            
          </p>
          <a
            href=""
            class="btn"
            data-toggle="modal"
            data-target="#exampleModal7"
            data-whatever="@mdo"
          >
            Add Cities</a
          >

          <div
            class="modal fade"
            id="exampleModal7"
            tabindex="-1"
            role="dialog"
            aria-labelledby="exampleModalLabel"
            aria-hidden="true"
          >
            <div class="modal-dialog" role="document">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">
                    Add City
                  </h5>
                  <button
                    type="button"
                    class="close"
                    data-dismiss="modal"
                    aria-label="Close"
                  >
                    <span aria-hidden="true">&times;</span>
                  </button>
                </div>
                <div class="modal-body">
                  <form action="AdminPage.php" method="post">
                    <div class="form-group">
                      <label for="recipient-name" class="col-form-label"
                        >City Name</label
                      >
                      <input
                        type="text"
                        class="form-control"
                        id="ACName"
                        name="ACName"
                      />
                    </div>
                     
                    <!-- <div class="form-group">
                      <label for="message-text" class="col-form-label"
                        >Message:</label
                      >
                      <textarea
                        class="form-control"
                        id="message-text"
                      ></textarea>
                    </div> -->
                    <button type="submit" class="btn btn-primary">
                    Add City
                  </button>
                  </form>
                </div>
                <div class="modal-footer">
                  <button
                    type="button"
                    class="btn btn-secondary"
                    data-dismiss="modal"
                  >
                    Close
                  </button>
                  
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </section>

    <script
      src="https://code.jquery.com/jquery-3.4.1.slim.min.js"
      integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n"
      crossorigin="anonymous"
    ></script>
    <script
      src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js"
      integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo"
      crossorigin="anonymous"
    ></script>
    <script
      src="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/js/bootstrap.min.js"
      integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6"
      crossorigin="anonymous"
    ></script>
  </body>
</html>
