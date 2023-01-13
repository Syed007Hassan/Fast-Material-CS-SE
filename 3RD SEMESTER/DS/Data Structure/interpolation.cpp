#include<iostream>

using namespace std;

int interpolationsearch(int a[],int n,int key)
{
	int l=0;
	int h=n-1;
	
	while(l<=h&&key>=a[l]&&key<=a[h])
	{
		if(l==h)
		{
			if(a[l]==key) 
			{
				return l;
			}
			
			return -1;
		}
		int p= l+ (( (double) (h-l) /(a[h]-a[l])) * (key-a[l]));
		
		if(a[p]==key)
		{
			return p;
		}
		if(a[p]<key)
		{
			l=p+1;
		}
		else
		{
			h=p-1;
		}
	}
	return -1;
	
}
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	
	int result=interpolationsearch(a,9,10);
	
	if(result==-1)
	{
		cout << "Not";
	}
	else
	{
		cout << "Found at index : "<<result;
	}
	
	
	
	
}
