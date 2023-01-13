#include<iostream>

using namespace std;

int main()
{
	int i,j,rows,column,check1=0,check2=0;
	int *p;
	
	cout << "Enter number of rows : ";
	cin >> rows;
	
	cout << "Enter number of column : ";
	cin >> column;
	
	p = new int[rows * column];
	
	cout << "Enter the elements in the array.\n";
	
	for(i=0; i<rows; i++)
	{
		for(j=0; j<column; j++)
		{
			cin >> *(p+i*column+j);
		}
	}
	cout << "The matrix is\n";
	for(i=0; i<rows; i++)
	{
		for(j=0; j<column; j++)
		{
			cout << *(p+i*column+j)<< "\t";
		}
		cout << "\n";
	}
	for(i=0; i<rows; i++)
	{
		for(j=0; j<column; j++)
		{
			if(i==j)
			{
				if (*(p+i*column+j)==1)
				{
					check1++;
				}
			}
			else
			{
				if (*(p+i*column+j)==0)
				{
					check2++;
				}	
			}
			
		}	
	}
	if(check1==column&&check2==(rows*column-check1))
	{
		cout << "Identity Matrix\n";
	}
	else
	{
		cout << "Not identity matrix";
	}
	
	
	
	
}
