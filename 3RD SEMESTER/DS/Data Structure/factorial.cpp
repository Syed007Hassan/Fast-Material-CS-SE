#include<iostream>

using namespace std;

int recursive(int n);
int main()
{
	int num;
	
	cout << "Enter any Number : ";
	cin >> num;
	cout << "The factorial of "<<num<< " : "<< recursive(num);
}
int recursive(int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		return n * recursive(n-1);
	}
}
