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
	int a[6]={7,1,9,6,0,2};
	int gap,i,j;
	
	for(gap=6/2;gap>0;gap=gap/2)
	{
		for(j=gap;j<6;j++)
		{
			for(i=j-gap;i>=0;i=i-gap)
			{
				if(a[i+gap]>a[i])
				{
					break;
				}
				else
				{
					swap(a[i+gap],a[i]);
				}
			}
		}
	}	
	for(i=0;i<6;i++)
	{
		cout << a[i]<<"  ";
	}
}
