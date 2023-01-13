#include<iostream>
using namespace std;
class employee{
	protected:
	string name;
	string code;
	public:
		employee(string n,string c)
		{
			name=n;
			code=c;
		}
		
};
class consultant:virtual public employee
{
		protected:
	int yearofexp;
	public:
	consultant(int year,string n,string c):employee(n,c)
	{
		yearofexp=year;
	}
};
class manager:virtual public employee{
	protected:
	int noofteam;
	public:
		manager(int team,string n,string c):employee(n,c)
		{
			noofteam=team;
		}
};
class cm:public consultant,public manager
{
	public:
		cm(int team,int year,string n,string c):manager(team,n,c),consultant(year,n,c),employee(n,c)
		{	
		}
		void display()
		{
		    cout<<"\nNAME:"<<name;
			cout<<"\nCODE:"<<code;
			cout<<"\nNO OF TEAM:"<<noofteam;
			cout<<"\nEXPERIENCE:"<<yearofexp;
		}
};
int main()
{
 cm obj(10,20,"fizza","111");
 obj.display();
 
 return 0;
}

