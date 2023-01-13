#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	
	fstream o;
	o.open("task1.txt",ios::out|ios::in|ios::app);
	if(o)
	{
		char line[100];
		cout<<"file opened!!";
		{
			cout<<"\nenter anything to enter something in file:";
			cin.getline(line,sizeof(line));
			o<<line<<endl;
			cout<<"\nwriten content in file\n";
			o>>line;
			cout<<line<<endl;
			o.close();
			
		}
	}
	else 
	{
		cout<<"\nfile didnot open!!";
	}
}
