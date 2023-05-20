<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.css" />
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.3.0/css/all.min.css" />
  <link rel="stylesheet" href="Check.css" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Document</title>
</head>

<body>
  <header class="header">
    <div id="menu-btn" class="fas fa-bars"></div>

    <a href="#" class="logo"><span>Fast</span>Medicos</a>
    <nav class="navbar">
      <a href="infromation.php">Home</a>
      <!-- <a href="Check.html">Package</a>
        <a href="Car.html">Rent Car</a>

        <a href="Infromation.html">Information</a> -->
      <a href="Form.php">SignUP</a>
    </nav>
    <div class="C" id="login-btn">
      <?php
      if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $UName = $_POST['UName'];
        //$UName="UK1";
        $FName = $_POST['FName'];
        $password = $_POST['password'];
        //$password1="123";
        $type = $_POST['r'];
        // print $UName;
        //print var_dump($password);
        $servername = "localhost";
        $username = "root";
        $pass = "";
        $db = "FastMedicos";
        $conn = mysqli_connect($servername, $username, $pass, $db);

        if ($conn) {






          $query = "Select * from `$type`";
          $result = mysqli_query($conn, $query);
          if ($result) {
            for ($i = 0; $i < mysqli_num_rows($result); $i++) {
              $row = mysqli_fetch_assoc($result);
              echo "<br>";

              //print $row["PName"];
              //print var_dump($row["Password"]);
              if ($type == 'patients') {
                if ($row["PName"] == $UName && $row["Password"] == $password) {
                  //print $FName;
                  $_SESSION["name"] = $UName;
                  $_SESSION["pass"] = $password;
                  //print $_SESSION["name"]=$UName;

                  header("Location: SearchDoctor.php");
                  break;
                } else {
                  //print $row["Password"];
                  //print $password;
                  // print "no";
                }
              }
              if ($type == 'doctors') {
                if ($row["DName"] == $UName && $row["Password"] == $password) {
                  print "success";
                  $_SESSION["name"] = $UName;
                  $_SESSION["name2"] = $row['Fullname'];
                  $_SESSION["pass"] = $password;
                  header("Location: profile.php");
                  break;
                } else {
                  //print $row["DName"];
                  //print $UName;
                  //print "no";
                }
              }
              if ($type == 'admins') {
                if ($row["AName"] == $UName && $row["Password"] == $password) {
                  print "success";
                  $_SESSION["name"] = $UName;
                  $_SESSION["pass"] = $password;
                  header("Location: AdminPage.php");
                  break;
                } else {
                  //print $row["Password"];
                  //print $password;
                  // print "no";
                }
              }
            }

            echo "<div class='alert alert-danger' role='alert'>
  UserName or Password incorrect
</div>";
          }
          // echo "<br>";
        } else {
          // print "noo";
        }
      }

      ?>
      <button class="btn">Login</button>
      <i class="far fa-user"></i>
    </div>
  </header>

  <div class="login-form-container">
    <span class="fas fa-times" id="close-login-form"></span>
    <form action="Infromation.php" method="post">

      <h3>Login</h3>
      <input type="text" placeholder="First Name" name="FName" id="FName" class="box" />

      <input type="text" placeholder="UserId" id="UName" name="UName" class="box" />
      <input type="text" placeholder="Password" id="password" name="password" class="box" />

      <div class="ff">
        <div>
          <input type="radio" id="r" name="r" value="doctors" checked />
          <label for="huey">Doctor</label>
        </div>

        <div>
          <input type="radio" id="r" name="r" value="patients" />
          <label for="dewey">Patient</label>
        </div>
        <div>
          <input type="radio" id="r" name="r" value="admins" />
          <label for="Admin">Admin</label>
        </div>
      </div>

      <input type="submit" value="Submit" class="btn" />
      <div id="search">
        <button type="button" class="btn" id="aaa">
          Signup
        </button>
      </div>
    </form>
  </div>

  <section class="home" id="home">
    <h1 class="home-parallax" data-speed="-2">Advance Medical Sciences</h1>
    <img src="./images/image41.jpg" class="home-parallax" data-speed="5" alt="" />
    <a href="#" class="btn home-parallax" data-speed="7">Explore More News</a>
  </section>

  <!-- home end -->

  <!-- icon -->

  <section class="vehicles" id="vehicles">
    <h1 class="heading">
      Popular
      <span> Researches </span>
    </h1>
    <div class="swiper vehicles-slider">
      <div class="swiper-wrapper">
        <div class="swiper-slide box">
          <img src="./images/image1.jpeg" alt="" />
          <div class="content">
            <h3>New Type Of COVID</h3>
            <div class="price">
              <span> Author </span>
              Yale Medicine
            </div>
            <p>
              Ratings
              <span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span>
            </p>
            <a href="" class="btn"> check Out</a>
          </div>
        </div>
        <div class="swiper-slide box">
          <img src="./images/images31.png" alt="" />
          <div class="content">
            <h3>Omicron Attack</h3>
            <div class="price">
              <span> Author: </span>
              HobNOb
            </div>
            <p>
              Ratings
              <span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span>
            </p>
            <a href="" class="btn"> check Out</a>
          </div>
        </div>
        <div class="swiper-slide box">
          <img src="./images/image30.jpg" alt="" />
          <div class="content">
            <h3>High Fever</h3>
            <div class="price">
              <span> Author </span>
              Mani Medicine
            </div>
            <p>
              Ratings
              <span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span>
            </p>
            <a href="" class="btn"> check Out</a>
          </div>
        </div>
        <div class="swiper-slide box">
          <img src="./images/image34.jpeg" alt="" />
          <div class="content">
            <h3>Maldives Viral</h3>
            <div class="price">
              <span> Author</span>
              H K Researchers
            </div>
            <p>
              new
              <span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fas fa-circle"></span><span class="fasfa-circle"></span><span class="fas fa-circle"></span>
            </p>
            <a href="" class="btn"> check Out</a>
          </div>
        </div>
      </div>
      <div class="swiper-pagination"></div>
    </div>
  </section>

  <section class="services" id="services">
    <h1 class="heading">Best <span> Researches </span></h1>
    <div class="box-container">
      <div class="swiper-slide box">
        <i class="fa-solid fa-notes-medical"></i>
        <h3>Indian Research</h3>
        <p>
          ► Indian Heitage Institute <br />
          ► 12 June<br />
          ► Archtiala<br />
          ► Mameactre<br />
        </p>
        <a href="" class="btn"> read more</a>
      </div>
      <div class="swiper-slide box">
        <i class="fa-solid fa-notes-medical"></i>
        <h3>Russia Research</h3>
        <p>
          ► Russia Rames Institute<br />
          ► 13 June<br />
          ► Memetret<br />
          ► Acidic esaete<br />
        </p>
        <a href="" class="btn"> read more</a>
      </div>
      <div class="swiper-slide box">
        <i class="fa-solid fa-notes-medical"></i>
        <h3>Maldives Research</h3>
        <p>
          ► Maldives Land Institute <br />
          ► 14 June<br />
          ► Viscosity Hemle<br />
          ► Viscous Liquids <br />
        </p>
        <a href="" class="btn"> read more</a>
      </div>
    </div>
  </section>

  <section class="featured">
    <h1 class="heading"><span>featured</span> Researchs</h1>
    <div class="swiper featured-slider">
      <div class="swiper-wrapper">
        <div class="swiper-slide box">
          <img src="./images/image35.jpeg" alt="" />
          <h3>Srilankan Research Institute</h3>
          <div class="stars">
            <i class="fas fa-cars"> </i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star-half-alt"></i>
          </div>
          <div class="price">G.Alam</div>
          <a href="" class="btn">check out</a>
        </div>
        <div class="swiper-slide box">
          <img src="./images/image36.jpeg" alt="" />
          <h3>PIA Institute</h3>
          <div class="stars">
            <i class="fas fa-cars"> </i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star-half-alt"></i>
          </div>
          <div class="price">Kashif M.Kareem</div>
          <a href="" class="btn">check out</a>
        </div>
        <div class="swiper-slide box">
          <img src="./images/images31.png" alt="" />
          <h3>Singpore Institute</h3>
          <div class="stars">
            <i class="fas fa-cars"> </i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star-half-alt"></i>
          </div>
          <div class="price">Hemen K</div>
          <a href="" class="btn">check out</a>
        </div>
      </div>
      <div class="swiper-pagination"></div>
    </div>

    <div class="swiper featured-slider">
      <div class="swiper-wrapper">
        <div class="swiper-slide box">
          <img src="./images/images31.png" alt="" />
          <h3>Emirates Institute</h3>
          <div class="stars">
            <i class="fas fa-cars"> </i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star-half-alt"></i>
          </div>
          <div class="price">Sheikh SD</div>
          <a href="" class="btn">check out</a>
        </div>
        <div class="swiper-slide box">
          <img src="./images/image35.jpeg" alt="" />
          <h3>Qatar Institute</h3>
          <div class="stars">
            <i class="fas fa-cars"> </i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star-half-alt"></i>
          </div>
          <div class="price">Harley</div>
          <a href="" class="btn">check out</a>
        </div>
        <div class="swiper-slide box">
          <img src="./images/image32.jpg" alt="" />
          <h3>Turkish Institute</h3>
          <div class="stars">
            <i class="fas fa-cars"> </i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star"></i>
            <i class="fas fa-star-half-alt"></i>
          </div>
          <div class="price">Avacanda</div>
          <a href="" class="btn">check out</a>
        </div>
      </div>
      <div class="swiper-pagination"></div>
    </div>
  </section>

  <script src="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.js"></script>
  <script src="script.js"></script>
</body>

</html>