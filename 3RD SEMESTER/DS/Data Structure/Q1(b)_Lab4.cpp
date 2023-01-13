#include<iostream>

using namespace std;

void recursive(int number,int start,int increament);

int main()
{
	int n;
	cout << "Enter number : ";
	cin >> n;
	
	 recursive(n,1,0);
}
void recursive(int number,int start,int increament)
{
	if(number==0)
	{
		return;
	}
	else
	{
		start = start + increament;
		cout << start <<" ";
		recursive(number-1,start,increament+1);
	}
}
