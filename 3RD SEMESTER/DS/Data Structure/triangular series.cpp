#include<iostream>

using namespace std;

void recursive(int number,int start);

int main()
{
	int n;
	cin >> n;
	recursive(n,1);
}
void recursive(int num,int hehe )
{
	if(num==0)
	{
		return;
	}
	else
	{
		cout << ((hehe*(hehe+1))/2)<< " ";
		recursive(num-1,hehe+1);
	}
}
