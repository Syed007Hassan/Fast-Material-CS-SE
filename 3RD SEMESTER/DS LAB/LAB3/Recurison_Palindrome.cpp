#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


 int palindrome(string n, int s, int e){
 	
 	if(e-s == 1 || s==e){
 		return 1;
	 }
	 
	 else{
	 	if(n[s] == n[e]){
	 		return palindrome(n,s+1,e-1);
		 }
		 
		 else{
		 	
		 	return 0;
		 }
	 }
 	
 
 }
 
int main(){
	
	cout<<"Enter the string "<<endl;
	string name;
	cin>>name;
	
	int length = name.length();
	
	if(palindrome(name,0,length-1)){
		cout<<"Yes true "<<endl;
		
	}
	else{
		
		cout<<"No false "<<endl;
	}
	
	
return 0;	
}
