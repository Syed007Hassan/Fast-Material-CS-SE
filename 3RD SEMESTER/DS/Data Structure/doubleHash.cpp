#include<iostream>

using namespace std;
int hash2(int key)
{
	return (7-(key%7));
}
int hash1(int key)
{
	return key%10;
}
int hash(int key,int i)
{
	return ((hash1(key))+i*(hash2(key)))%10;	
}

int main()
{
	int a[10];
	int b[5]={35,87,19,20,16};
	
	for(int i=0;i<10;i++)
	{
		a[i]=-99999;
	}
	for(int i=0;i<5;i++)
	{
		int j=0;
		while(1)
		{
			if(a[hash(b[i],j)]==-99999)
			{
				a[hash(b[i],j)]=b[i];
				break;
			}
			else
			{
				j++;
			}
		}
	}
	
	cout<<a[5];
	
}
