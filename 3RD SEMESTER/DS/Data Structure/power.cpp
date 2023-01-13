#include<iostream>

using namespace std;

int recursive(int number,int power);

int main()
{
	int num,pow;
	
	cout << "Enter Number : ";
	cin >> num;
	cout << "Enter Power :";
	cin >>pow;
	
	cout << "Answer : "<<recursive(num,pow);
}
int recursive(int number,int power)
{
	if(power==1)
	{
		return number;
	}
	else
	{
		return number*recursive(number,power-1);
	}
}
