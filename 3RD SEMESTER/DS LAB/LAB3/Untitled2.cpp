#include<iostream>
using namespace std;



int add(int n){
	
	int temp=0;
	static int sum = 0;
	if(n == 0){
		
		return sum;
	}
	
	
	else{
		

		temp = n % 10;	
		sum = sum + temp;
				
	    return add(n/10);
 }
	
	
}

int main(){
	
	
	int n;
//	cout<<n;
	
	cout<<add(55107);
	
	
}
