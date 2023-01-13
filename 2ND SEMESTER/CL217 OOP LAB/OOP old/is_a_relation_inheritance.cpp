#include<iostream>
using namespace std;

class A
{
	private:
		int x;
	protected:
		int y;
	public:
		int z;
	
	A()
	{
		cout<<endl<<endl<<"A created"<<endl<<endl;
	}
	
	~A()
	{
		cout<<endl<<endl<<"A destroyed"<<endl<<endl;
	}
	
	set_x(int a)
	{
		x = a;
	}
	
	int get_x()
	{
		return x;
	}
};

class B : public A
{
	//x is hidden from this class and it is not accessible
	//y becomes protected in this class and it is accessible
	//z becomes public in this class and and it is accessible
	
	public:
	
	display()
	{
		cout<<endl<<y<<endl<<z<<endl;
	}
		
	B()
	{
	//	x = 10; //error: x is private and it is hidden from class B
		y = 3;
		z = 5;
		cout<<endl<<endl<<"B created"<<endl<<endl;
	}
	
	~B()
	{
		cout<<endl<<endl<<"B destroyed"<<endl<<endl;
	}
};

class C : private A
{

	//x is hidden from this class and it is not accessible
	//y becomes private in this class and it is accessible
	//z becomes private in this class and it is accessbile
	//set_x becomes private in this class
	//get_x becomes private in this class
	
	public:
	int m;
	display()
	{
		//x = 10;
		y = 12;
		z = 15;
		cout<<endl<<y<<endl<<z<<endl;
	}
		
	C()
	{
		y = 10;
		z = 20;
		cout<<endl<<endl<<"C created"<<endl<<endl;
	}
	
	
	~C()
	{
		cout<<endl<<endl<<"C destroyed"<<endl<<endl;
	}
};

class D : protected B
{
	//x is hidden from this class and it is not accessible
	//y becomes protected in this class and it is accessible
	//z becomes protected in this class and it is accessible
	
	public:
	display()
	{
		cout<<endl<<y<<endl<<z<<endl;
	}
		
	D()
	{
		y = 10;
		z = 20;
		cout<<endl<<endl<<"D created"<<endl<<endl;
	}
	
	~D()
	{
		cout<<endl<<endl<<"D destroyed"<<endl<<endl;
	}
	
};

class E : public C
{
	//x is hidden from this class and it is not accessible
	//y is hidden from this class and it is not accessible
	//z is hidden from this class and it is not accessible
	
	public:
	display()
	{
		//cout<<endl<<y<<endl<<z<<endl; //Error y and z not accessible
	}
		
	E()
	{
		// y = 10; //Error 
		//z = 20; //Error
		cout<<endl<<endl<<"E created"<<endl<<endl;
	}
	
	~E()
	{
		cout<<endl<<endl<<"E destroyed"<<endl<<endl;
	}
	
};

creation()
{
//	B b;
//	b.z = 6;
//	
//	b.display();

//	C c;
//	c.display();
//	
	D d;
	d.display();
	
//	E e;
//	e.display();
}

main()
{
	creation();
	getchar();
}
