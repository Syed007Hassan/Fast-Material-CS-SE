#include<iostream>

using namespace std;

int binarysearch(int a[],int l,int r,int key)
{
	if(l<=r)
	{
		int mid=(l+r)/2;
		
		if(key==a[mid])
		{
			return mid;
		}
		if(key<a[mid])
		{
			return binarysearch(a,l,mid-1,key);
		}
		if(key>a[mid])
		{
			return binarysearch(a,mid+1,r,key);
		}
	}
	return -1;
}
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	
	
	int result= binarysearch(a,0,8,9);
	
	if(result==-1)
	{
		cout << "Not present";
	}
	else
	{
		cout << "Present at index "<<result;
	}
	
}
