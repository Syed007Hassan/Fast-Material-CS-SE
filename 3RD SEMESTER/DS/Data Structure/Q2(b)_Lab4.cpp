#include<iostream>

using namespace std;

void recursive1(int number,int start,int increament);
void recursive2(int number,int start,int increament);


int main()
{
	int n;
	cout << "Enter number : ";
	cin >> n;
	
	 recursive1(n,1,0);
}
void recursive1(int number,int start,int increament)
{
	if(number==0)
	{
		return;
	}
	else
	{
		recursive2(number,start,increament);
	}
}
void recursive2(int number,int start,int increament)
{
	start = start + increament;
	cout << start <<" ";
	recursive1(number-1,start,increament+1);
}
