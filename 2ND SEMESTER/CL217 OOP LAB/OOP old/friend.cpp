#include<iostream>

using namespace std;

class A
{
		int x;

		public:
			display()
			{
				cout<<x<<endl;	
			}
		friend void set();
		friend void set2(A a);
};

void set()
{
	A a;
	a.x = 10;
	a.display();	
}

void set2(A a)
{
	a.x = 15;
	a.display();
}

void d()
{
	set();
}

main()
{
		set();
		A a;
		set2(a);
		d();
}





