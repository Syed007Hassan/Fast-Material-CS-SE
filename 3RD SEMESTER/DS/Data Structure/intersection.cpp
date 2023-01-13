#include<iostream>


using namespace std;

int main()
{
	int *p,*pp;
	int size1,size2,sizeOfin=0,i,j;
	cout << "Enter the size of array 1 : ";
	cin >> size1;
	
	p =new int[size1];
	cout << "Enter Elements array1 : ";
	for(i=0;i<size1;i++)
	{
		cin >> p[i];
	
	}
	cout << "Enter the size of array 2 : ";
	cin >>size2;
	pp=new int[size2];

	cout << "Enter Elements array2 : ";
	for(int i=0;i<size2;i++)
	{
		cin >> pp[i];	
	}
	int *m= new int[1];
	int duplicate=-1;
	for(i=0;i<size1;i++)
	{
		int counter=0;
		for(j=0;j<size2;j++)
		{
			if(p[i]==pp[j])
			{
				counter++;
				pp[j]=duplicate;
				duplicate--;			
			}	
		}
		if(counter!=0)
		{
			m[sizeOfin]=p[i];
			sizeOfin++;
		}	
	}
	cout << "Intersection of arrays : ";
	for(i=0;i<sizeOfin;i++)
	{
		cout << m[i]<< " ";
	}
	

}
