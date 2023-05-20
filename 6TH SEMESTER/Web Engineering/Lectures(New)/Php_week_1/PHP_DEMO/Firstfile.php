<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Untitled Document</title>
</head>

<body>

<?php

// What is variable, string ('' ,"") , 
// print statements(echo , print)


// int a =12;
$a="Fahad";
$b=" Hussain";
$d=' Fahad Hussain';

//. indicate concatenation in variable or string... 
//$c=$a + $b;
//echo "Fahad Hussain Free Computer Education", $a."value of b: $b";
//print "Fahad Hussain Free Computer Education 123";

//echo $c."<br/>";
//print $c."<br/>";


//echo "Fahad Hussain  $a <br/>";
//echo 'Fahad Hussain  $a';


/// echo (no return) whereas print (1 return)
// echo (more than one parameter), print (only 1 parameters)
// echo faster than print

echo "F","A","H","A","D";
print "F"."A"."H"."A"."D";



//Operator in PHP

//a = 3 + 6;









//Arithematic Operator in Php

// +, -, *, / , %



//logical Operator ( &&, ||, !, and, or, not ,xor)


$x=12;
$y=122;
$z= ($x>=12 && $y<=122);
echo "Compare using ==: ", $z."<br/>";
$za= ($x!=12 && $y<=122);
echo "Compare using ==: ", $za."<br/>";
$zb= ($x!=12 || $y<=122);
echo "OR using ==: ", $zb."<br/>";
$zc= !($y<=122);
echo "Compare using ==: ", $zc."<br/>";
$zd= ($x==12 xor $y<=122);
echo "XOR using ==: ", $zd."<br/>";




//Bitwise operator ( &, |, ~, ^, >>, <<)
//2 binary 0010
//3 binary 0011

$a=4;
$b=3;

echo "And Bitwise Operator Result: ",$a | $b;
echo "<br/>";
echo "And Bitwise Operator Result: ",$a & $b."<br/>";
echo "<br/>";
echo "And Bitwise Operator Result: ",$a ^ $b."<br/>";
echo "<br/>";
echo "And Bitwise Operator Result: ",~$a."<br/>";
echo "<br/>";
echo "And Bitwise Operator Result: ",$a << $b."<br/>";
echo "<br/>";
echo "And Bitwise Operator Result: ",$a >> $b."<br/>";




//Assignment Operator  (=, +=, -=, *=, /=, %=)
$zz= $a+1;
$a += 1;
echo "<br/>".$a;




//Ind/Dec Oprator 


//++= 1, -- = -1
echo "<br/><br/>";
$t=1;
echo $t--;
echo $t;
?>






































</body>
</html>