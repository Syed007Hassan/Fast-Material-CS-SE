#include<iostream>

using namespace std;
bool isopen(int **maze,int **path,int row,int column,int size)
{
	if(row<size && column<size && maze[row][column]==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool ratinmaze(int **maze,int **path,int row,int column,int size)
{
	if(row == (size-1) && column==(size-1)&&maze[row][column]==1)
	{
		path[row][column]=1;
		return true;
	}	
	
	if(isopen(maze,path,row,column,size))
	{
		path[row][column]=1;
		
		if(ratinmaze(maze,path,row+1,column,size))
		{
			return true;
		}
		else if(ratinmaze(maze,path,row,column+1,size))
		{
			return true;
		}
		else
		{
			path[row][column]=0;
		
		}
	}
	return false;
}
int main()
{
	int **Omaze = new int*[6];
	int **Opath=new int*[6];
	int array[6][6]={
					{1,0,0,0,0,0},
					{1,0,0,0,0,0},
					{1,0,0,0,0,0},
					{1,1,0,0,0,0},
					{1,1,1,0,0,0},
					{1,0,1,1,1,1}					
					};
	for(int i=0;i<6;i++)
	{
		Omaze[i]=new int [6];
		Opath[i]=new int[6];
	}
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			Omaze[i][j]=array[i][j];
			Opath[i][j]=0;
		}
	}
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout << Omaze[i][j]<< "  ";
		}
		cout <<endl;
	}
	if(ratinmaze(Omaze,Opath,0,0,6))
	{
		cout << "\n\nPATH FOUND\n\n";
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				cout << Opath[i][j]<< "  ";
			}
			cout <<endl;
		}	
	}
	else
	{
		cout << "\n\nNot found";
	}
}
