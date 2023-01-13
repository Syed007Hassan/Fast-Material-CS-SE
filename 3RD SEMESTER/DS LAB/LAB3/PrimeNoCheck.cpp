#include<iostream>
using namespace std;

bool primeno(int n, int i ){
	
	if( n <= i){
		return false;
	}
	else if( n % i == 0 ){
		return false;
	}
	
	else if( i*i > n){
		return true;
	}
	
	else{
		return primeno(n,i+1);
	}
	
}

int main(){
	
 //cout<<primeno(23,21);
 
 cout<< 501 %10<<endl;
 cout<<501/10;
 	
	
}
