#include<iostream>
using namespace std;

template <class T1, class T2>
void add(T1 x, T2 y)
{
	//int a;
	cout<<"\nADDITION F TOW NUM:"<<x+y<<endl;
	//return a;
}
template <class T1, class T2>
void sub(T1 x, T2 y)
{
	//int a;
	cout<<"\nSUBTRACTION OF TWO NUM:"<<x-y<<endl;
	//return a;
}
template <class T1, class T2>
void div(T1 x, T2 y)
{
	//int a;
	cout<<"\nDIVISION OF TWO NUM:"<<x/y<<endl;
	//return a;
}template <class T1, class T2>
void multiply(T1 x, T2 y)
{
	//int a;
	cout<<"\nMULTIPLICATION OF TWO NUM:"<<x*y<<endl;
	//return a;
}
int main()
{
	int a=3,b=4;
	float c=4.9, d=5.5;
	add(a,b);
	sub(a,b);
	multiply(c,d);
	div(c,d);
	
	
}







