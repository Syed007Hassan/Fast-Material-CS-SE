#include<iostream>

using namespace std;

void swap(int &a,int &b)
{
	int temp;
	
	temp=a;
	a=b;
	b=temp;
}
int main()
{
	int a[6]={6,5,4,3,2,1};
	int i,j,minPos,min;
	
	for(i=0;i<6-1;i++)
	{
		min=a[i];
		for(j=i+1;j<6;j++)
		{
			if(min>a[j])
			{
				minPos=j;
			}
		}
		swap(a[minPos],a[i]);
	}
	
	for(i=0;i<6;i++)
	{
		cout << a[i]<<"  ";
	}
}
