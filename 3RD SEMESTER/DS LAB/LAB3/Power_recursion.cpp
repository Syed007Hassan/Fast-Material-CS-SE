#include<iostream>
using namespace std;

 power(int n, int p){
 	
 	if(p == 0){
 		return 1;
	 }
	 
	 else{
	 	
	 	return n*power(n,p-1);
	 }
 		
 }
 
 
 int main(){
 	
 	cout<<power(2,3);
 	
 	
 	
 }
