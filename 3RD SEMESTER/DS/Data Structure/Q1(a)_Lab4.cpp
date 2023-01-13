#include<iostream>

using namespace std;

void recursive(int number,int start);
int main()
{
	int n;
	cout << "Enter number : ";
	cin >> n;
	
	recursive(n,1);
}
void recursive(int number,int start)
{
	if(number==0)
	{
		return;
	}
	else
	{
		cout << (start*(start+1))/2<< " ";
		recursive(number-1,start+1);
	}
}
