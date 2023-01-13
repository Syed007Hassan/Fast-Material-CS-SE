#include<iostream>
using namespace std;

class cricketer
{
	//int x;	
	public:	
		cricketer()
		{
//		x = y; 
//		cout<<"I am cric";
		}
		
//		hitasix()
//		{
//			x += 6;
//		}
		
//		virtual d()
//		{
//			cout<<"I am cricketer"<<endl;
//		}
		
		//virtual int abc(char) = 0;
		virtual team() = 0;
};

class batsman : public cricketer
{
	public:
		
		
		d()
		{
			cout<<"I am batsman"<<endl;
		}
		
		abc()
		{
		}
			
		team()
		{
			cout<<"I am batsman"<<endl;
		}
};

class bowler : public cricketer
{
	public:
		d()
		{
			cout<<"I am bowler"<<endl;
		}
		team()
		{
			cout<<"I am bowler"<<endl;
		}
};

int main()
{
//	cricketet *c;
//	cricketer c;
//	batsman b;
	bowler bo;
//	b.cricketer();
	bo.team();
	
}
