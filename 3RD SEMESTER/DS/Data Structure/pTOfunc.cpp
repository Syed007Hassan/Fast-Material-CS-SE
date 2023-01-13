#include<iostream>

using namespace std;

int Addition(int a,int b);

int main()
{
	int (*p) (int,int);
	
	p=Addition;
	cout << p(5,5);
}
int Addition(int a,int b)
{
	
	return (a+b);
}
