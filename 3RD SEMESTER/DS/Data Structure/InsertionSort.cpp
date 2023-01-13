#include<iostream>

using namespace std;

int main()
{
	int a[6]={6,5,4,3,2,1};
	
	int i,j,temp;
	
	for(i=1;i<6;i++)
	{
		temp=a[i];
		
		for(j=i;j>0&&temp<a[j-1];j--)
		{
			a[j]=a[j-1];
		}
		a[j]=temp;
	}
	
	for(i=0;i<6;i++)
	{
		cout << a[i]<<"  ";
	}
}
