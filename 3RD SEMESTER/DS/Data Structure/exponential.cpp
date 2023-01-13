#include<iostream>

using namespace std;
int binarysearch(int a[],int l,int h,int key)
{
	while(l<=h)
	{
		int mid=(l+h)/2;
		
		if(a[mid]==key)
		{
			return mid;
		}
		else if(a[mid]<key)
		{
			l=mid+1;
		}
		else
		{
			h=mid-1;
		}
	}
	return -1;
}
int exponentialSearch(int a[],int n,int key)
{
	int l=0;
	int h=n-1;
	
	if(a[0]==key)
	{
		return l;
	}
	int i=1;
	while(i<n&&a[i]<=key)
	{
		i=i*2;
	}
	return binarysearch(a,i/2,min(i,n-1),key);
}
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	
	
	int result=exponentialSearch(a,9,111);
	if(result==-1)
	{
		cout << "Not";
	}
	else
	{
		cout << "Found at index : "<<result;
	}
}
