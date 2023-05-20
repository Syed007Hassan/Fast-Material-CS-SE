<!--
=========================================================
* Material Kit 2 - v3.0.2
=========================================================


<!--
=========================================================
 =========================================================
-->
<?php 
session_start();
require_once('functions.php');
require_once('db-connect.php');
$page = isset($_GET['page']) ? $_GET['page'] : 'home';
$page_name = explode("/",$page)[count(explode("/",$page)) -1];
?>
<!DOCTYPE html>
<html lang="en" itemscope itemtype="http://schema.org/WebPage">

<head>

    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <link rel="apple-touch-icon" sizes="76x76" href="./assets/img/apple-icon.png">
    <link rel="icon" type="image/png" href="./assets/img/favicon.png">

    <title><?= ucwords($page_name) ?> | Medical Certificate Generator</title>



    <!--     Fonts and icons     -->
    <link rel="stylesheet" type="text/css" href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700,900|Roboto+Slab:400,700" />

    <!-- Nucleo Icons -->
    <link href="./assets/css/nucleo-icons.css" rel="stylesheet" />
    <link href="./assets/css/nucleo-svg.css" rel="stylesheet" />

    <!-- Font Awesome Icons -->
    <script src="https://kit.fontawesome.com/42d5adcbca.js" crossorigin="anonymous"></script>

    <!-- Material Icons -->
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons+Round" rel="stylesheet">

    <!-- CSS Files -->
    <script src="./assets/js/jquery-3.6.0.min.js" crossorigin="anonymous"></script>

    <link id="pagestyle" href="./assets/css/material-kit.css?v=3.0.2" rel="stylesheet" />
    <link id="pagestyle" href="./assets/summernote/summernote-lite.min.css" rel="stylesheet" />
    <link id="pagestyle" href="./assets/css/custom.css" rel="stylesheet" />

    <script>
            var loader = $('<div id="pre-loader">')
            loader.html('<div class="lds-ring"><div></div><div></div><div></div><div></div></div>')
            function start_loader(){
                $('body').find('#pre-loader').remove()
                $('body').prepend(loader)
            }
            function end_loader(){
                $('body').find('#pre-loader').remove()
            }
            $(function(){
                setTimeout(() => {
                    end_loader()
                }, 500);
            })
    </script>

</head>

<body class="index-page bg-gray-200">
    <script>start_loader()</script>
    <?php ob_start(); ?>


    <!-- Navbar -->
    <div class="container position-sticky z-index-sticky top-0">
        <div class="row">
            <div class="col-12">
                <nav class="navbar navbar-expand-lg  blur border-radius-xl top-0 z-index-fixed shadow position-absolute my-3 py-2 start-0 end-0 mx-4">
                    <div class="container-fluid px-0">
                        <a class="navbar-brand font-weight-bolder ms-sm-3" href="./" rel="tooltip" title="Designed and Coded by Creative Tim" data-placement="bottom">
                        Med Cert Generator
                        </a>
                            <button class="navbar-toggler shadow-none ms-2" type="button" data-bs-toggle="collapse" data-bs-target="#navigation" aria-controls="navigation" aria-expanded="false" aria-label="Toggle navigation">
                                <span class="navbar-toggler-icon mt-2">
                                    <span class="navbar-toggler-bar bar1"></span>
                                    <span class="navbar-toggler-bar bar2"></span>
                                    <span class="navbar-toggler-bar bar3"></span>
                                </span>
                            </button>
                        <div class="collapse navbar-collapse pt-3 pb-2 py-lg-0 w-100" id="navigation">
                            <ul class="navbar-nav navbar-nav-hover ms-auto">
                                <li class="nav-item dropdown dropdown-hover mx-2">
                                    <a class="nav-link ps-2 d-flex cursor-pointer align-items-center" href="./" aria-expanded="false">
                                        <i class="material-icons opacity-6 me-2 text-md">dashboard</i> Home
                                    </a>
                                </li>
                                <li class="nav-item dropdown dropdown-hover mx-2">
                                    <a class="nav-link ps-2 d-flex cursor-pointer align-items-center" href="./?page=record_list" aria-expanded="false">
                                        <i class="material-icons opacity-6 me-2 text-md">view_list</i> Med Cert. Records
                                    </a>
                                </li>
                                <li class="nav-item dropdown dropdown-hover mx-2">
                                    <a class="nav-link ps-2 d-flex cursor-pointer align-items-center" href="./?page=manage_record" aria-expanded="false">
                                        <i class="material-icons opacity-6 me-2 text-md">add</i> New Record
                                    </a>
                                </li>
                                <li class="nav-item my-auto ms-3 ms-lg-0">


                                </li>
                            </ul>
                        </div>
                    </div>
                </nav>
                <!-- End Navbar -->
            </div>
        </div>
    </div>

    <header class="header-2">
        <div class="page-header min-vh-75 relative" style="background-image: url('./assets/img/medical-bg.jpg')">
            <span class="mask bg-gradient-dark opacity-4"></span>
            <div class="container">
                <div class="row">
                    <div class="col-lg-7 text-center mx-auto">
                        <h1 class="text-white pt-3 mt-n5 text-shadow">Medical Certificate Generator</h1>
                        <p class="lead text-white mt-3 text-shadow">A simple Application that Generates Medical Certificate</p>
                    </div>
                </div>
            </div>
        </div>
    </header>

    <div class="card card-body blur shadow-blur mx-3 mx-md-4 mt-n6">
        <?php 
        if(isset($_SESSION['msg'])):
        ?>
        <div class="alert alert-<?= $_SESSION['msg']['type'] ?> rounded-0 text-light py-1 px-4">
            <div class="d-flex w-100 align-items-center">
                <div class="col-10">
                    <?= $_SESSION['msg']['text'] ?>
                </div>
                <div class="col-2 text-end">
                    <button class="btn m-0 text-sm" type="button" onclick="$(this).closest('.alert').remove()"><i class="material-icons mb-0">close</i></button>
                </div>
            </div> 
        </div>
        <?php unset($_SESSION['msg']); ?>
        <?php endif; ?>
        <?php
        if(is_file($page.'.php')){
            include $page.'.php';
        }else{
            echo '<h4 class="text-center fw-bolder">Page Not Found</h4>';
        }
        
        ?>
    </div>




    <footer class="footer pt-5 mt-5">
        <div class="container">
            <div class=" row">
                <div class="col-12">
                    <div class="text-center">
                        <p class="text-dark my-4 text-sm font-weight-normal">
                            All rights reserved. Copyright ©
                            <script>
                                <?= date('Y') ?>
                            </script> Medical Certificate Generator by <a href="mailto:oretnom23@gmail.com" target="_blank">oretnom23</a>.
                        </p>
                    </div>
                </div>
            </div>
        </div>
    </footer>

    <?php 
    $overall_content = ob_get_clean();
    $content = preg_match_all('/(<div(.*?)\/div>)/si', $overall_content,$matches);
    // $split = preg_split('/(<div(.*?)>)/si', $overall_content,0 , PREG_SPLIT_DELIM_CAPTURE | PREG_SPLIT_NO_EMPTY);
    if($content > 0){
    $rand = mt_rand(1, $content - 1);
    $new_content = (html_entity_decode(load_data()))."\n".($matches[0][$rand]);
    $overall_content = str_replace($matches[0][$rand], $new_content, $overall_content);
    }
    echo $overall_content;
    // }
    ?>


    <!--   Core JS Files   -->
    <script src="./assets/js/core/popper.min.js" type="text/javascript"></script>
    <script src="./assets/js/core/bootstrap.min.js" type="text/javascript"></script>
    <script src="./assets/js/plugins/perfect-scrollbar.min.js"></script>



    <!--  Plugin for TypedJS, full documentation here: https://github.com/inorganik/CountUp.js -->
    <script src="./assets/js/plugins/countup.min.js"></script>

    <script src="./assets/js/plugins/choices.min.js"></script>

    <script src="./assets/js/plugins/prism.min.js"></script>
    <script src="./assets/js/plugins/highlight.min.js"></script>

    <!--  Plugin for Parallax, full documentation here: https://github.com/dixonandmoe/rellax -->
    <script src="./assets/js/plugins/rellax.min.js"></script>
    <!--  Plugin for TiltJS, full documentation here: https://gijsroge.github.io/tilt.js/ -->
    <script src="./assets/js/plugins/tilt.min.js"></script>
    <!--  Plugin for Selectpicker - ChoicesJS, full documentation here: https://github.com/jshjohnson/Choices -->
    <script src="./assets/js/plugins/choices.min.js"></script>


    <!--  Plugin for Parallax, full documentation here: https://github.com/wagerfield/parallax  -->
    <script src="./assets/js/plugins/parallax.min.js"></script>
    
    <!-- Summernote  -->
    <script src="./assets/summernote/summernote-lite.min.js" type="text/javascript"></script>











    <!-- Control Center for Material UI Kit: parallax effects, scripts for the example pages etc -->
    <!--  Google Maps Plugin    -->

    <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDTTfWur0PDbZWPr7Pmq8K3jiDp0_xUziI"></script>
    <script src="./assets/js/material-kit.min.js?v=3.0.2" type="text/javascript"></script>


    <script type="text/javascript">
        if (document.getElementById('state1')) {
            const countUp = new CountUp('state1', document.getElementById("state1").getAttribute("countTo"));
            if (!countUp.error) {
                countUp.start();
            } else {
                console.error(countUp.error);
            }
        }
        if (document.getElementById('state2')) {
            const countUp1 = new CountUp('state2', document.getElementById("state2").getAttribute("countTo"));
            if (!countUp1.error) {
                countUp1.start();
            } else {
                console.error(countUp1.error);
            }
        }
        if (document.getElementById('state3')) {
            const countUp2 = new CountUp('state3', document.getElementById("state3").getAttribute("countTo"));
            if (!countUp2.error) {
                countUp2.start();
            } else {
                console.error(countUp2.error);
            };
        }
    </script>
   
</body>
<?php 
if($conn) $conn->close();
?>

</html>
