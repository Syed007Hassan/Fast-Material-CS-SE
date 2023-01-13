#include<iostream>

using namespace std;

class A 
{
	
	public:
	set()
	{
		cout<<"I am in A"<<endl;
	}	
};

class B : public A
{	
	public:
	set()
	{
	cout<<"I am in B"<<endl;
	}
};

class D : public B
{
	public:
	set()
	{
	cout<<"I am in D"<<endl;
	}
};

class C : public A
{
	
};

main()
{
	A a;
	a.set();
	
	B b;
	b.set();
	
	C c;
	c.set();
	
	D d;
	d.set();
}
