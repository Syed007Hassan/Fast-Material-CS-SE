#include<iostream>
using namespace std;
int series1(int);
int series(int n){
	
   static int x = n;
   static int y=0,s=1,i=0;
     if(n<=1 || y >= x)
 {
     exit(0);
 
 }
 
 else if(y < x)
 
 {      y++;
        s=s+i;
        cout<<s<<endl;
	    ++i;	  
        return series1(n);
        
   
 }
 		
}

int series1(int n){
	
	return series(n+1);
}

int main(){
	
	cout<<"Enter the value to generate pattern(1 , 2 , 4 , 7 , 11 , 16 , 22 . . . . n) "<<endl;
	int n;
	cin>>n;
	cout<<endl;
	cout<<series(n);
	
}
