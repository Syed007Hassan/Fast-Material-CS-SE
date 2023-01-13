#include<iostream>

using namespace std;

bool isopen(int **ptr,int row,int col,int size)
{
	if(row<size&&col<size&&ptr[row][col]==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool ratinmaze(int **ptr,int **path,int row,int col,int size)
{
	if(row==size)
	{
		return true;
	}
	for(int j=0;j<col;j++)
	{
		if(isopen(ptr,row,col,size))
		{
			path[row][j]=1;
			if(ratinmaze(ptr,path,row+1,col,size))
			{
				return true;
			}
			if(ratinmaze(ptr,path,row+1,col,size))
			{
				return true;
			}
			path[row][col]=0;
		}
	}
	return false;
	
}
int main()
{
	int **p = new int*[6];
	int **path=new int*[6];
	for(int i=0;i<6;i++)
	{
		p[i]=new int[6];
		path[i]=new int[6];
	}
	int array[6][6]=
	{
		{1, 0, 1, 0, 1, 1},
      	{1, 0, 1, 1, 1, 1},
      	{1, 0, 1, 1, 1, 1},
      	{1, 1, 1, 0, 1, 1},
      	{1, 1, 1, 1, 0, 1},
      	{1, 0, 0, 1, 1, 1}
	};
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			p[i][j]=array[i][j];
			path[i][j]=0;
		}
	}
	if(ratinmaze(p,path,0,0,6))
	{
		cout << "Path Found\n";
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				cout<<path[i][j]<<"   ";
			}
			cout <<endl;
		}
		
	}
	else
	{
		cout << "No Path Found\n";
	}
	
}
