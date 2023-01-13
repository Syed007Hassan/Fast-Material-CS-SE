#include<iostream>
using namespace std;
void print (int a)
{
cout<<a<<" ";
}
int main()
{  
static int t=0;
cout<<"test case:";
    cin>>t;
    while(t<100)
    {   int n;
    cout<<"\nvalue of n:";
    cin>>n;
     int k = n+1;
   
    for (int i=1; i<=n; i++)
    {
        int temp = k;
        while (temp <= n)
        {
            print(temp);
            temp++;
        }
 
        for (int j=1; j<k; j++)
            print(j);
 
        k--;
        cout<<endl;
    }
    }
    }
