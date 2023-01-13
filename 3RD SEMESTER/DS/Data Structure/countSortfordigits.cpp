#include<iostream>
#include<queue>

using namespace std;

int getmax(int a[],int n)
{
    int max=a[0];

    for (int i = 1; i < n; i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}
void countsort(int a[],int n)
{
    int maxsize;
    maxsize=getmax(a,n);
    int count[maxsize+1];
    int output[n];

    for(int i=0;i<maxsize+1;i++)
    {
        count[i]=0;
    } 
    for(int i=0;i<n;i++)
    {
        ++count[a[i]];
    }
    for(int i=1;i<=n;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        output[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}

int main()
{
    int a[9]={5,3,1,1,6,0,7,8,1};
    


    countsort(a,9);
    for(int i=0;i<9;i++)
    {
        cout <<a[i]<<"  " ;
    }
}
