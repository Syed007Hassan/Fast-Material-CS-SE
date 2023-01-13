#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;

int main(){
	
	string a;
	
	cout<<"Enter the string: ";
	getline(cin,a);
	
	int len= a.length();
	
	cout<<"The length of string is: "<<len<<endl;
	
	fstream file;
	
	file.open("q1.txt",ios::out);
	
	if(!file){
		cout<<"File not created\n\n "<<endl;
	}
	else{
		cout<<"file has been created\n\n";
	}
	
	file<<a;
	
	file.close();
	
	file.open("q1.txt",ios::in);
	
	string aa;
	
	while(1){
		
		getline(file,aa);
		if(file.eof()){
			break;
		}
	}
	cout<<"The retreived data from file is: ";
	cout<<aa;
	
	file.close();	
	
}
