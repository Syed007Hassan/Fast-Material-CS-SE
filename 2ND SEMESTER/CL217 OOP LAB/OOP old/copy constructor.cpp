#include<iostream>

using namespace std;

class A 
{
	public:
	int x;
	int y;
	int z;
	
	A()
	{
		x = 1;
		y = 2;
		z=5;
	}

	A(const A &a)
	{

		
		z = a.z;
		x = a.x;
		y = a.y;
	}
	
	set (int a)
	{
		z = a;
	}
	
	display()
	{
		cout<<z<<endl;
	}
};

int main()
{
	A a1;
	A a2 = a1;

	cout<<a1.x<<endl;
	cout<<a2.x<<endl;
	
	cout<<a1.z<<endl;
	cout<<a2.z<<endl;
	
	a1.set(3);
	
	a1.display();
	a2.display();
	
	getchar();
	
}
