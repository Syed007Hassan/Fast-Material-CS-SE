#include<iostream>
using namespace std;

 template <class T>
void swapargs (T &a, T &b)
{
	T temp; 
	temp = a;
	a = b;
	b = temp;
}

template <class T1, class T2>
void add(T1 x, T2 y)
{
	//int a;
	cout<<x+y<<endl;
	//return a;
}


template<>
void add(char x, char y)
{
	cout<<x<<"+"<<y<<endl;
	//cout<<x+y;
}

template<class T>
void add(T x)
{
	cout<<x<<endl;
	//cout<<x+y;
}
main()
{
	//float z;
	int a=5, b=10;
	float c=5.7, d=10.5;
	char e='x', f='y';
	
	swap(a,b);
	swap(c,d);
	swap(e,f);
//	
	cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
	
	add(c,a);
	add(b,c);
	add(e);
	add(e,f);
}

