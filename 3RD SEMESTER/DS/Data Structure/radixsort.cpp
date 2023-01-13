#include<iostream>

using namespace std;

int getmax(int a[],int n)
{
    int max=a[0];

    for(int i=1;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}
void countsort(int a[],int n,int pos)
{
	int count[10]={0};
	int output[n];
	
	for(int i=0;i<n;i++)
	{
		++count[(a[i]/pos)%10];
	}
	for(int i=1;i<10;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		output[--count[(a[i]/pos)%10]]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		a[i]=output[i];
	}
}
void radixsort(int a[],int n)
{
	int max=getmax(a,n);
	
	for(int pos=1;max/pos>0;pos=pos*10)
	{
		countsort(a,n,pos);
	}
	
	
}


int main()
{
    int a[9]={53,133,145,1,63,670,1671,986,100};

    radixsort(a,9);
    for(int i=0;i<9;i++)
    {
        cout <<a[i]<<"  " ;
    }
}
