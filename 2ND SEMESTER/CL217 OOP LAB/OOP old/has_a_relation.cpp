#include<iostream>
using namespace std;

class A
{
	public:
	
	A()
	{
		cout<<endl<<endl<<"A created"<<endl<<endl;
	}
	
	~A()
	{
		cout<<endl<<endl<<"A destroyed"<<endl<<endl;
	}
	
		int x;
};

class B
{
	A a;
	
	public:
	
	A a2;
	int y;
	
	B()
	{
		cout<<endl<<endl<<"B created"<<endl<<endl;
		A a3;
	}
	
	~B()
	{
		cout<<endl<<endl<<"B destroyed"<<endl<<endl;
	}
};

creation()
{
	B b;
}

main()
{
	creation();
	getchar();
}
