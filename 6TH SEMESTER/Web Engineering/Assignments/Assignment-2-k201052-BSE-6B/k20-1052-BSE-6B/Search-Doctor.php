<?php
session_start();
?>
<?php
if (!isset($_SESSION['pass'])) {

  header("Location: infromation.php");
}
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
      <a href="SearchDoctor.php">Search Doctor</a>
      <a href="BookAppointment.php">Book Appointment</a>

    </nav>
    <!-- <div class="C" id="login-btn">

        <button class="btn">Login</button>
        <i class="far fa-user"></i>
      </div> -->
  </header>

  <section class="home" id="home">
    <h1 class="home-parallax" data-speed="-2">Search Doctors</h1>
    <?php
    $servername = "localhost";
    $username = "root";
    $pass = "";
    $db = "ass";
    $conn = mysqli_connect($servername, $username, $pass, $db);


    // print $_SESSION['conn'];

    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
      $input = $_POST['in'];
      //$id=$_POST['in'];

      //print $input;
      $query = "select * from `doctors` where City='$input'";
      $query1 = "select * from `doctors` where `Expertise`='$input'";
      $res = mysqli_query($conn, $query);
      $res2 = mysqli_query($conn, $query1);
      $arr = array();
      $arr1 = array();
      $arr3 = array();
      $arr2 = array();
      if ($res) {
        // print mysqli_num_rows($res);
        for ($i = 0; $i < mysqli_num_rows($res); $i++) {
          $Row = mysqli_fetch_assoc($res);
          array_push($arr, $Row['Fullname']);
          array_push($arr1, $Row['DName']);
          array_push($arr2, $Row['City']);
          array_push($arr3, $Row['Expertise']);
          //print $arr[$i];
        }
      }
      if ($res2) {

        //print mysqli_num_rows($res2);
        for ($i = 0; $i < mysqli_num_rows($res2); $i++) {
          $Row = mysqli_fetch_assoc($res2);

          array_push($arr, $Row['Fullname']);
          array_push($arr1, $Row['DName']);
          array_push($arr2, $Row['City']);
          array_push($arr3, $Row['Expertise']);
          //print $arr[$i];
        }
      }
    }

    ?>
    <?php
    //print $input;
    ?>
    <img src="./images/image27.jpg" class="home-parallax" data-speed="5" alt="" />

    <form action="SearchDoctor.php" method="post">
      <input type="text" class="search1" name='in' autocorrect="off" autocapitalize="off" id='in' style="position: absolute; margin-top: -40rem;margin-left: -45rem;height: 5rem; width: 90rem; padding: 0px; font-size: 2rem; text-transform:none;" placeholder="search for doctors" />

      <button class="btn" style="width:10rem;position: absolute; margin-top: -40rem; margin-left: 43rem;height: 5rem;  padding: 0px; font-size: 2rem; text-transform: lowercase;"> Search</button>
    </form>

  </section>
  <section class="services" id="services">
    <h1 class="heading">Doctor <span> Details </span></h1>
    <div class="box-container">
      <?php
      if ($_SERVER['REQUEST_METHOD'] == 'POST') {


        for ($i = 0; $i < mysqli_num_rows($res); $i++) {

          echo '<div class="swiper-slide box">
         <i class="fas fa-user-md"></i> <h3>' . $arr[$i] . '</h3>
         <p>
            ► ID: ' . $arr1[$i] . '<br />
            ►Expertise: ' . $arr3[$i] . '<br />
            ►City: ' . $arr2[$i] . '<br />
          </p>
          <a href="" class="btn"> read more</a>
        </div>';
        }
        for ($i = 0; $i < mysqli_num_rows($res2); $i++) {

          echo '<div class="swiper-slide box">
         <i class="fas fa-user-md"></i> <h3>' . $arr[$i] . '</h3>
         <p>
            ► ID: ' . $arr1[$i] . '<br />
            ►Expertise: ' . $arr3[$i] . '<br />
            ►City: ' . $arr2[$i] . '<br />
          </p>
          <a href="" class="btn"> read more</a>
        </div>';
        }
      }
      ?>




  </section>
</body>

</html>