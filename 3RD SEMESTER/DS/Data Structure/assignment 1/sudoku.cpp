#include<iostream>

using namespace std;
#define unassign 0
bool rowcheck(int **ptr,int row,int num)
{
	for(int col=0;col<9;col++)
	{
		if(ptr[row][col]==num)
		{
			return false;
		}
	}
	return true;
}
bool colcheck(int **ptr,int col,int num)
{
	for(int row=0;row<9;row++)
	{
		if(ptr[row][col]==num)
		{
			return false;
		}
	}
	return true;
}
bool boxcheck(int **ptr,int boxstRow,int boxstCol,int num)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (ptr[row + boxstRow][col + boxstCol] ==	num)
			{
				return false;
			}
		}
	}
	return true;
}
bool isSafe(int **ptr,int row,int col,int num,int n)
{
	return rowcheck(ptr,row,num)&&colcheck(ptr,col,num)&&boxcheck(ptr,row-row%3,col-col%3,num);	
}
bool solvesudoku(int **ptr,int row,int col,int n)
{
	if(row==n)
	{
		return true;
	}
	if(ptr[row][col]!=unassign)
	{
		if(col==n-1)
		{
			solvesudoku(ptr,row+1,0,n);
		}
		else
		{
			solvesudoku(ptr,row,col+1,n);
		}
	}
	else
	{

		if(col==n-1)
		{
			for(int i=0;i<=9;i++)
			{
				if(isSafe(ptr,row,col,i,n))
				{
					ptr[row][col]=i;
					
					if(solvesudoku(ptr,row+1,0,n))
					{
						return true;
					}
				}
			}
			return false;	
		}
		else
		{
			for(int i=0;i<=9;i++)
			{
				if(isSafe(ptr,row,col,i,n))
				{
					ptr[row][col]=i;
					
					if(solvesudoku(ptr,row,col+1,n))
					{
						return true;
					}
				}
			}
			return false;
		}
	}	
}
void print(int **ptr)
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << ptr[i][j]<< " ";
		}
		cout <<endl;
	}
}
int main()
{
	int **p=new int*[8];
	
	for(int i=0;i<8;i++)
	{
		p[i]=new int[8];
	};
	int array [8][8]={
		5, 3, 4, 6, 7, 8, 9, 1,
		6, 7, 2, 1, 9, 5, 3, 4,
		1, 9, 8, 3, 4, 2, 5, 6,
		8, 5, 9, 7, 6, 1, 4, 2,
		4, 2, 6, 8, 5, 3, 7, 9,
		7, 1, 3, 9, 2, 4, 8, 5,
		9, 6, 1, 5, 3, 7, 2, 8,
		2, 8, 7, 4, 1, 9, 6, 3
	};
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
		p[i][j]=array[i][j];
		}
	}
	
	int **temp=new int*[9];
	for(int i=0;i<9;i++)
	{	
		temp[i]=new int[9];
	}
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(j==8)
			{
				temp[i][j]=0;
			}
			else
			{
				temp[i][j]=p[i][j];
			}
		}
	}
	for(int i=8;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			temp[i][j]=0;
		}
	}
	for(int i=0;i<8;i++)
	{
		delete[]p[i];
	}
	delete[]p;

	p=temp;
	temp=NULL;
	
	solvesudoku(p,0,0,9);
	
	print(p);
	
}
