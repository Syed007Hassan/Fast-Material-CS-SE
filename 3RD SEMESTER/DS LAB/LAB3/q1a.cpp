#include<iostream>
using namespace std;

 int pattern(int n){
   
   static int x = n;
   static int y=1;
     if(n<1 || y>x)
 {
     exit(0);
 }
 
 else if(y <= x)
 
 {      y++;
       cout<<((y*(y-1))/2)<<endl;	
       return pattern(n-1);
          
 }
 	
}

int main(){
	
	cout<<"Enter the value to generate pattern(1 , 3 , 6 , 10 , 15 , 21 , 28  . . .  n) "<<endl;
	
	int n;
	cin>>n;
	cout<<endl;
	pattern(n);
	
	
}
