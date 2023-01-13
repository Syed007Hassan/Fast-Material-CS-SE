#include<iostream>

using namespace std;

int main()
{
	int i,j,k,size,temp;
	
	cout << "Enter number of elements : ";
	cin >> size;
	
	int *p = new int[size];
	int *final= new int[size];
	
	
	cout << "Enter elements\n";
	for(i=0;i<size;i++)
	{
		cin >> p[i];
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(p[j]<p[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}

	for(i=0,j=0,k=size-1;i<size;i++)
	{
		if(size%2==0)
		{
			if(i%2==0)
			{
				final[i]=p[j];
				j++;
			}
			else
			{
				final[i]=p[k];
				k--;
			}		
		}
		else
		{
			if(i%2==0)
			{
				final[i]=p[j];
				j++;
			}
			else
			{
				final[i]=p[k];
				k--;
			}	
		}
		
	}
	cout << "\nFinal Array : ";
	for(i=0;i<size;i++)
	{
		cout << final[i] << " ";
	}
	delete []p;
	delete []final;
	
	
}
