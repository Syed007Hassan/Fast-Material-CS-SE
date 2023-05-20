<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php
$a="Fahad";
$b=" Hussain";
//Indicate concatenation in variable or string...

$c=$a.$b;
echo "Fast University <br/>";
print "<h1>NUCES Karachi</h1>";

echo $c."<br/>";
print $c."<br/>";


$x=12;
$y=122;

echo "<br/>";
echo "<br/>";
echo "<br/>";


$z= ($x==$y);
echo "Compare using ==: ", $z." <br/> <br/> <br/>";
$za= ($x!=$y);
echo "Compare using ==: ", $za."<br/>";
$zb= ($x>$y);
echo "Compare using ==: ", $zb."<br/>";
$zc= ($x<$y);
echo "Compare using ==: ", $zc."<br/>";
$zd= ($x===$y);
echo "Compare using ==: ", $zd."<br/>";

// make a break line to get space
echo "<br/>";
echo "<br/>";
//working Exmaple
if($x==$y)
{
 echo "Compare using if";
}
else
{
 echo "Compare using else";
}



//logical Operator (&&, ||, !, and, or, xor)
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



//Bitwise Operator in Php (&, |, ^, ~, >>, <<)
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


//if Statement (if, if-else, if elseif, if elseif else)

$a=1;
if($a==1)
{
 echo "The value of a is: ".$a;
}
else if($a ==10)
{
 echo "else if Body : ".$a;
}
else if($a ==2)
{
 echo "else if Body : ".$a;
}
else if($a ==3)
{
 echo "else if Body : ".$a;
}
else
{
 echo "Default";
}


$a=1;
$b=2;
$c=3;
if($a==1)
{
 echo "The value of a is: <br/>".$a;

 if($b==6)
 {
  echo "The value of b is: <br/>".$b;

  if($c==3)
  {
   echo "The value of c is: <br/>".$c;
  }
 }
}













//for Loop including nested loop

for($a=5;$a>=1;$a--)
{
 echo "The Value of a is: ".$a;
 echo "<br/>";
 for($b=5;$b>=1;$b--)
 {
  echo "The Value of b is: ".$b;
 echo "<br/>";
 }
}


// while loop, nested loop
$a=1;
while($a<=10)
{
 echo "Value of a is: ".$a; echo "<br/>";
 $a++;

 $b=1;
 while($b<=10)
 {
 echo "Value of b is: ".$b; echo "<br/>";
 $b++;
 }
}

// Do-While Loop
$a =100;
do
{
 echo "Value of a is: ".$a; echo "<br/>";
 $a++;
}while($a<=10);

// Jump Statements in php

for($a=1; $a<=10; $a++)
{
if($a==5)
{
exit;   //Continue , also use break
}
echo "The value of a is: ".$a;
echo "<br/>";
}


// Array 1D and 2D (key value concept)

$arr = array (11,12,13,14,15,16,17,18,19);
for($i=0; $i<=8; $i++)
{
echo $arr[$i];
}


$arr = array(
array(1,2,3,4,5),
array(11,12,13,14,15),
array(21,22,23,24,25)
);

echo $arr[0][0];

$arr = array(11 => 'Fahad', 22 =>'Hussain', 33 => 'php', 44 => 'tutorial');
echo $arr[11];


// user define function and built in function in php

function addTwoNumber()
{
echo "The function name by AddTow number<br/>";
$a =1;
$b=2;
$c = $a+$b;
echo $c;
}
addTwoNumber();

function addTwoNumbers($a, $b)
{
$c = $a+$b;
echo $c;
}
// addTwoNumbers(10,20);

// echo round(12.10);
// echo floor(12.10);
// echo ceil(12.10);
// echo abs(-10);
// echo sqrt(81);
// echo strlen("Fahad Hussain");
// echo strcmp("Fahad","Fahad");
// */
?>
</body>
</html>