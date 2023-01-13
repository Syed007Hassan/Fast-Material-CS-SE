#include<iostream>

using namespace std;


class A
{
	int x;
	int y;
	
	public:
		A()
		{}
		
		A(int i, int j)
		{
			x = i;
			y = j;	
		}
		
		display()
		{
			cout<<x<<endl<<y<<endl;
		}
		
		A operator +(A a)
		{
			A a3;
			a3.x = x + a.x;
			a3.y = y + a.y;
			return a3;
			//return x;	
		}
		
		A operator -(A a)
		{
			A a3;
			a3.x = x - a.x;
			a3.y = y - a.y;
			return a3;
			//return x;	
		}
		
		operator ++()
		{
			++x;
			++y;	
		}
		
		operator ++(int)
		{
			x++;
			y++;
		}
		
		operator --()
		{
			--x;
			--y;	
		}
		
		operator --(int)
		{
			x--;
			y--;
		}	
			
		
};



main()
{
	A a1(1,2);
	cout<<endl<<"Object a1"<<endl<<endl;
	//a1 //x=1 , y =2
	
	a1.display();
	A a2(3,4);
	cout<<endl<<"Object a2"<<endl<<endl;
	//a2 //x=3 , y = 4
	a2.display();
	
	A a3;
	
	a3 = a1+a2;
	
	A a4;
	a4 = a2 - a1;
	
	cout<<endl<<"Object a3"<<endl<<endl;
	a3.display();
	a4.display();
	
	a1++;
	
	
	//++a1;
	
	--a1;
	
	a1.display();
	
}









