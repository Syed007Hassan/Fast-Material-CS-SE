#include<iostream>
using namespace std;
class bank{
	protected:
		double balance;
	public:
		virtual float getbalance()=0;
		
};
class A:public bank{
	public:
		A(double b)
		{
			balance=b;
		}
		float getbalance()
		{
			return balance;
		}
};
class B:public bank{
	public:
			B(double b)
		{
			balance=b;
		}
		float getbalance()
		{
			return balance;
		}
};
class C:public bank{
	public:
			C(double b)
		{
			balance=b;
		}
		float getbalance()
		{
			return balance;
		}
};
int main()
{
	A a(100);
	B b(150);
	C c(200);
	cout<<"\n ACCOUNT A BALANCE IS "<<a.getbalance();
	cout<<"\n ACCOUNT B BALANCE IS "<<b.getbalance();
	cout<<"\n ACCOUNT C BALANCE IS "<<c.getbalance();
}
