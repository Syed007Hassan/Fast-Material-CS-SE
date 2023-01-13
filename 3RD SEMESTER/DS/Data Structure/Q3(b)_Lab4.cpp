#include<iostream>

using namespace std;

int recursive(int *p,int size);
int getmax(int *p,int size);

int main()
{
	int n;
	cout << "Enter the size of array : ";
	cin>> n;
	int *ptr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> ptr[i];
	}
	recursive(ptr,n);
	
	for(int i=0;i<n;i++)
	{
		cout << ptr[i]<< " ";
	}
}
int recursive(int *p,int size)
{
	int temp,maxPos;
	if(size==0)
	{
		return p[0];
	}
	else
	{
		maxPos=getmax(p,size);
		temp=p[size-1];
		p[size-1]=p[maxPos];
		p[maxPos]=temp;
		return recursive(p,size-1);
	}
}
int getmax(int *p,int size)
{
	int i,max,maxIndex;
	
	max=p[0];
	
	for(i=1;i<size;i++)
	{
		if(max<p[i])
		{
			max=p[i];
			maxIndex=i;
		}
	}
	return maxIndex;
}
