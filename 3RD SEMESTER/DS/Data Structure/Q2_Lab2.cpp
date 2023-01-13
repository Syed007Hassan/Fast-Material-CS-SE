#include<iostream>

using namespace std;

int main()
{
	int i,j,size=10,temp;
	int *p=new int[10];
	
	cout << "Enter 10 elements in the array\n";
	for(int i=0; i<size; i++)
	{
		cin >> p[i];
	}
	for(i=0; i<size; i++)
	{
		for(j=0; j<size-1; j++)
		{
			if(p[j]>p[j+1])
			{
				temp = p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	cout << "Ascending Array: ";
	for(int i=0; i<size; i++)
	{
		cout <<  p[i]<< "  ";
	}
	for(i=0; i<size; i++)
	{
		for(j=0; j<size-1; j++)
		{
			if(p[j]<p[j+1])
			{
				temp = p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	cout << "\nDescending Array: ";
	for(int i=0; i<size; i++)
	{
		cout <<  p[i]<< "  ";
	}
	
	
	
}
