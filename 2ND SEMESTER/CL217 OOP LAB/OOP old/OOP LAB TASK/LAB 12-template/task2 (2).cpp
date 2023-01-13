#include<iostream>
using namespace std; 

template <class T>
void  swaping(T &a, T &b)
		{
	T temp; 
	temp = a;
	a = b;
	b = temp;
	cout<<"\n after swapping:"<<a<<" "<<b;
		}

int main()
{
	char a='f';
	char b='g';
	cout<<"before swapping:"<<a<<" "<<b;
		swaping(a,b);
	
}
