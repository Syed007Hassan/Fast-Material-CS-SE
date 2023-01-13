#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int main()
{
//	 program to copy the contents of one file to another
	char ch,file1[20],file2[20];
	cout<<"\nenter source file name with extension:";
	cin>>file1;
	ifstream f;
	ofstream o;
	f.open(file1,ios::in|ios::out|ios::app);
	if(!f)
	{
		cout<<"invalid file"<<endl;
		exit(1);
	}
	cout<<"\nenter destination file name with extension:";
	cin>>file2;
	o.open(file2,ios::in|ios::out|ios::app);
	if(!o)
	{
		cout<<"invalid file"<<endl;
		exit(1);
	}
	while(f.eof()==0)
	{
		f>>ch;
		o<<ch;
	}
	cout<<"\n copied sucessfully!";
	f.close();
	o.close();
	getch();
	
	 
}
