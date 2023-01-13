#include<iostream>

using namespace std;

int recursive(int *p,int start,int end);
int main()
{
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	
	cout << recursive(array,0,9);
	
	
	
}
int recursive(int *p,int start,int end)
{
	if(start>=end)
	{
		return p[start];
	}
	else
	{
		cout << p[start]<< " ";
		return recursive(p,start+1,end);
	}
}

