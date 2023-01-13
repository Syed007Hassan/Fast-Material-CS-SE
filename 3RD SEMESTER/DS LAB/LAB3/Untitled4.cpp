#include<iostream>
using namespace std;

bool palind(string n, int e,int s){
	
	if(e-s == 0 || s == e){
	
	   return 1;
	}
	
	else{
		
	    if(n[s] == n[e]){
	    	
	    	palind(n,e-1,s+1);
		}
		else{
			return 0;
		}
		
	}
		
}




int main(){
	
	
	string n ="maham madam maam";
	int l = n.length();
	
	
cout<<palind(n,l-1,0);
	
	
	
	
}
