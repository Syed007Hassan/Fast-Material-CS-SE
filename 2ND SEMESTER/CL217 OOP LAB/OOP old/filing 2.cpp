#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	
	ifstream i;
	ofstream o;
	
	//fstream o;
	
	o.open("C:/Users/basit/Desktop/file4.txt", ios::app);
	
	if(o.is_open())
	{
		cout<<"File opened"<<endl;
		o<<"I am xyz";
	}
	
	else
	{
		cout<<"File didn't open"<<endl;
	}
	
	return 0;
}
