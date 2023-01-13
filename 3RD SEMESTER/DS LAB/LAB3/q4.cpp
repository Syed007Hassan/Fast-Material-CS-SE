#include<iostream>
using namespace std;

int fun(int n){
	
	if( n > 100){              //1- fun(95) n was lesser than 100 so if part does not run 
	                          //3- fun(106) n greater than 100 so 106-10 = 96
	return n-10;             //5- fun(96)  n < 100 so else again
   }                         //7- fun(107) n > 100 so 107-10=97
                             //9- fun(97)  n < 100 so else again
                             //11- fun(108) n > 100 so 108-10=98
                             //13- fun(98)  n < 100 so else again
                             //15- fun(109) n > 100 so 109-10=99
                             //17- fun(99)  n < 100 so else again
                             //19- fun(110) n > 100 so 110-10=100
                             //21- fun(100)  n < 100 so else again
                             //23- fun(111) n > 100 so 111-10=101
                             
   
   else{
   	return fun(fun(n+11));    //2- fun(fun(95+11)) = fun(fun(106)) 
   }                          //4- fun(96) 
                              //6- fun((fun(96+11)) = fun(fun(107))
                              //8- fun(97) 
                              //10- fun((fun(97+11)) = fun(fun(108))
                              //12- fun(98) 
                              //14- fun((fun(98+11)) = fun(fun(109))
                              //16- fun(99) 
                              //18- fun((fun(99+11)) = fun(fun(110))
                              //20- fun(100) 
                              //22- fun((fun(100+11)) = fun(fun(111))
}                      

int main(){
	
	int r;
	
	r = fun(95);
	
	cout<<" "<<r;
	
	return 0;
}
