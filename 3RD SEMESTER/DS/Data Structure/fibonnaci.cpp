#include<iostream>

using namespace std;

void recursive(int number,int first,int second);

int main()
{
	int num;
	
	cout << "Enter any number to produce fiboonaci series : ";
	cin >> num;
	
	recursive(num,0,1);
}
void recursive(int number,int first,int second)
{
	int temp,next;
	if(number==0)
	{
		return;
	}
	else
	{
		cout << first<<" ";
		next=first+second;
		first=second;
		second=next;
		return recursive(number-1,first,second);
	}
}

