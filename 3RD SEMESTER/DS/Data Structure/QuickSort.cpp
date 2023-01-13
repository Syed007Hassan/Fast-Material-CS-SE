#include<iostream>

using namespace std;

void swap(int &a,int &b)
{
	int temp;
	
	temp=a;
	a=b;
	b=temp;
}
int partition(int a[],int l,int h)
{
	int pivot=a[l];
	int i=l,j=h;
	
	while(i<j)
	{
		while(a[i]<=pivot)
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			swap(a[i],a[j]);
		}
	}
	swap(a[l],a[j]);
	return j;
}
void QuickSort(int a[],int l,int h)
{
	if(l<h)
	{
		int pivot=partition(a,l,h);
		QuickSort(a,l,pivot-1);
		QuickSort(a,pivot+1,h);
	}
}

int main()
{
	int n=10;
	int a[n]={7,3,1,8,2,4,5,0,9,6};
	
//	QuickSort(a,0,n-1);
	partition(a,0,n-1);
	
	for(int i=0;i<n;i++)
	{
		cout << a[i]<<"  ";
	}
	
	
	
}
