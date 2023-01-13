#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class person{
	string name;
	int age;
	public:
		person()
		{
		}
		person(string s,int a)
		{
			name=s;
			age=a;
		}
	void	display()
		{
			cout<<"\nNAME:"<<name;
			cout<<"\nAGE:"<<age;
		}
		
};
int main()
{
person	p("fizza",19);
fstream f;
f.open("person.txt",ios::out|ios::binary|ios::in);
if(f)
{
	cout<<"file opened"<<endl;
	f.write((char*)&p,sizeof(p));
	f.close();
	
}
else
{
	cout<<"file didnt open..!";
}
f.open("person.txt",ios::out|ios::binary|ios::in);
{
if(f)
{
//	cout<<"file opened"<<endl;
	if(f.read((char*)&p,sizeof(p)))
	{
		cout<<"\n\ndata extracted from file :\n";
		p.display();
	}
	
	f.close();
	
}
else
{
	cout<<"file didnt open..!";
}	
}
//p.display();
}
