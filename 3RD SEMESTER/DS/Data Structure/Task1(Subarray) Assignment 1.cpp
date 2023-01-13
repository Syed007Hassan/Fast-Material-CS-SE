#include<iostream>

using namespace std;


void print(int *ptr,int *finalarray, int n,int sum,int size)
{
	
	if(sum==0)
	{
		for(int i=size-1;i>=0;i--)
		{
			cout << finalarray[i]<< " ";
		}
		return;
	}
	else
	{
		finalarray[size] = ptr[n];
		print(ptr,finalarray,n-1,sum-ptr[n],size+1);
	}
	
	
}
int main()
{
	int i,n,*p,*result;
	int prevSum,sum;
	
	cin >> n;
	
	p = new int[n];

	result=new int [1];
	
	for(i=0;i<n;i++)
	{
		cin >> p[i];
	}
	
	sum=0;
	prevSum=0;
	
	for(int i=0;i<n;i++)
	{	
		prevSum= max(prevSum+p[i],p[i]);
		sum=max(sum,prevSum);	
	}
	cout << "\nsum : "<<sum<<endl;
	
	int checkSum=0,chcekprevSum=0,capacity=0;
	
	cout << "Sub Array : ";
	for(i=0;i<n;i++)
	{
		chcekprevSum= max(chcekprevSum+p[i],p[i]);
		checkSum=max(checkSum,chcekprevSum);
		
		if(checkSum==sum)
		{
			print(p,result,i,sum,capacity);
			break;	
		}
		
	}
	
	
}
