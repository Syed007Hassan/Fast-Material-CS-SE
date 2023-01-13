#include<iostream>

using namespace std;

void linearsearch(int a[],int n,int key)
{
	int i;
	for( i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			cout <<  key;
			return;
		}
	}
	if(i==n)
	{
		cout << "Key Not found";
	}
}
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	
	linearsearch(a,9,101);
	
	
}
