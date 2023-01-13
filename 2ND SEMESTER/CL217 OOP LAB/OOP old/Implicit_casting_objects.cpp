#include<iostream>
using namespace std;

class A
{
	public:
		int x;
		float y;
	A()
	{
	x = 3;
	y = 4.5647;
	}	
};

class B
{
	public:
		int y;
	B(A a)
	{
		y = a.y;
	}	
};


int main()
{
	A a;
	B b = a;
	
	cout<<a.x<<endl;
	cout<<b.y<<endl;
	
	system("Pause");
	getchar();
}


