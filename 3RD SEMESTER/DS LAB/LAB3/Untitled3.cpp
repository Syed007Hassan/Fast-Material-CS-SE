#include<iostream>
using namespace std;

void reverse(string s, int n){
	
	if(n < 0){
		exit(0);
	}
	
	else{
		
		cout<<s[n];
		
		return reverse(s,n-1);
		
	}
		
}




int main(){
	
	
	string s ="Hassan";
	int n = s.length();
	
	
	reverse(s,n-1);
	
	
	
	
}
