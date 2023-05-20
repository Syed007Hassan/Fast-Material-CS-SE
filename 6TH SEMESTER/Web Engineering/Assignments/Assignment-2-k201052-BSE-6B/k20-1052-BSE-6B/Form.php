<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <link
      rel="stylesheet"
      href="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.css"
    />
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.3.0/css/all.min.css"
    />
    <link rel="stylesheet" href="Check.css" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
     <header class="header">
      <div id="menu-btn" class="fas fa-bars"></div>

      <a href="#" class="logo"><span>Fast</span>Medicos</a>
      <nav class="navbar">
        <a href="Infromation.php">Home</a>
        
        
        
        
    <?php 

    if($_SERVER['REQUEST_METHOD']=="POST"){
    include 'connection.php';

    $type=$_POST['type'];

    
     
    if($type=='patients'){
   $ID=$_POST['UName'];
              $name=$_POST['FName'];
              $password=$_POST['password'];
              $City=$_POST['City'];

              $query="Insert into `patients`(PName,FullName,Password) values ('$ID','$name',' $password')";
              
      $res=mysqli_query($conn,$query);
      if($res)
      {
        header("Location: infromation.php");
      }
      else{
         $error = mysqli_error($conn);
         echo "<div class='alert alert-danger' role='alert'>
  UserName or Password incorrect
</div>";
      }
      

    
    

       


  

    }
    if($type=='admins'){
      $ID=$_POST['UName'];
              $name=$_POST['FName'];
              $password=$_POST['password'];
              $City=$_POST['City'];
                    $query="Insert into `admins`(AName,FullName,Password) values ('$ID','$name',' $password')";
                    $res=mysqli_query($conn,$query);
      if($res)
      {
        header("Location: infromation.php");
      }
      else{
         $error = mysqli_error($conn);
         echo "<div class='alert alert-danger' role='alert'>
  UserName or Password incorrect
</div>";
      }
      
    }
    if($type=='doctors'){
      $ID=$_POST['UName'];
              $name=$_POST['FName'];
              $password=$_POST['password'];
              $City=$_POST['City'];
              $Ex=$_POST['Expertise'];

      $query="Insert into `doctors`(DName,Fullname,Password,Expertise,City) values ('$ID','$name','$password','$Ex',' $City')";
      $res=mysqli_query($conn,$query);
      if($res)
      {
        header("Location: infromation.php");
      }
      else{
         $error = mysqli_error($conn);
         echo "<div class='alert alert-danger' role='alert'>
  UserName or Password incorrect
</div>";
      }
      
    }
    
    

   } ?>
        
      </nav>

      <div class="C" id="login-btn">
        <button class="btn">Login</button>
        <i class="far fa-user"></i>
      </div>
      
    </header>


    


    <section class="contact">
        <h1 class="heading"> 
            
        </h1>
         <div class="row">
        <form action="Form.php" method="post">
            <h3>Sign Up</h3>
            <input class="box" id="FName" name="FName" type="text" placeholder="First Name">
            <input class="box" id="City" name="City" type="text" placeholder="City">
            <input class="box"id="password" name="password" type="password"placeholder="Password">
            <input class="box"id="Expertise" name="Expertise" type="text "placeholder="Doctor Expertise">
            <input class="box" type="text"id="UName" name="UName" placeholder="User_Id">
            <!-- <input class="box" type="text"placeholder="Rental Car Or Package">
            <textarea class="box" name="" id="" cols="30" rows="10"></textarea> -->
            <select name="type" class="form-select" aria-label="Default select example">
           
           <option id="type" name="type" value="admins">Administrator</option>
          <option id="type" name="type" value="doctors" selected>Doctor</option>
          <option id="type" name="type" value="patients">Patient</option>
          </select>
            <input type="submit" value="Submit" class="btn">
        </form>
    </div>
    </section>
   



     <script src="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.js"></script>
    <script src="script.js"></script>
</body>
</html>