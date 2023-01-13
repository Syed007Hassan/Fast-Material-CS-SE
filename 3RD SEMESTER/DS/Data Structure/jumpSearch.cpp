#include<iostream>
#include<math.h>

using namespace std;

void jumpsearch(int a[],int n,int key)
{
	int jump,i,r,l;
	l=0;
	jump=sqrt(n);
	
	r=jump;
	
	while(a[r]<=key&&r<n)
	{
		l=r;
		r=r+jump;
		
		if(r>n&&a[r]<key)
		{
			cout<<"not";
			return;
		}
		
	}
	for(i=l;i<r;i++)
	{
		if(a[i]==key)
		{
			cout << "Found";
			return;
		}
	}
	if(i==r)
	{
		cout <<"not ";
	}
	
	
	
	
}


int main()
{
	int a[11]={1,2,3,4,5,6,7,8,9,10,11};
	
	jumpsearch(a,11,12);
	
	
}
