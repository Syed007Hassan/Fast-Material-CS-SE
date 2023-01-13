#include<iostream>

using namespace std;

void recursive1(int number,int start);
void recursive2(int number,int start);
int main()
{
	int n;
	cout << "Enter number : ";
	cin >> n;
	
	recursive1(n,1);
}
void recursive1(int number,int start)
{
	if(number==0)
	{
		return ;
	}
	else
	{
		recursive2(number,start);
	}
}
void recursive2(int number,int start)
{
	cout << (start*(start+1)/2)<< " ";
	recursive1(number-1,start+1);
}
