#include<iostream>

using namespace std;

int main()
{
	int *p,*pp,*merge;
	int size1,size2,i,k;
	cout << "Enter the size of array 1 : ";
	cin >> size1;
	cout << "Enter the size of array 2 : ";
	cin >>size2;
	p =new int[size1];
	pp=new int[size2];
	merge= new int[size1+size2]	;
	cout << "Enter Elements array1 : ";
	for(i=0;i<size1;i++)
	{
		cin >> p[i];
		merge[i]=p[i];
	}
	k=i;
	
	

	cout << "Enter Elements array2 : ";
	for(int i=0;i<size2;i++)
	{
		cin >> pp[i];
		merge[k]=pp[i];
		k++;
	}
	for(int i=0;i<size1+size2;i++)
	{
		cout << merge[i];
	}
	
	
	
	
	
	
}
