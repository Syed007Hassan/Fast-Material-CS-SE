#include<iostream>
using namespace std;

bool susbsequence(string a,int x,int s,string b, int y,int ss){

    static int z = 0;
	
//	cout<<z<<endl;
	if(z == 3){
		
		return true;
	}
	
	else if(s > x){
		
		return false;
	}
	
	else if(a[s] == b[ss]){
		 
		 cout<<a[s]<<" "<<b[ss]<<endl;
	
		z++;
		susbsequence(a,x,s+1,b,y,ss+1);
	}
	
	else{
	
		susbsequence(a,x,s+1,b,y,ss);
		
	}
}


int main(){
	
	
	string a = "hassan";
	int x = a.length();
	string b = "asn";
	int y = b.length();
	
	
	cout<<susbsequence(a,x-1,0,b,y-1,0);
	
	
}
