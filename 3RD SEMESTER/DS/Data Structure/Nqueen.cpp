#include<iostream>

using namespace std;


bool issafe(int **chessBoard,int row,int col,int n)
{
	int row_index, col_index;
  for (row_index = 0; row_index < row; row_index++)
  {
    if (chessBoard[row_index][col] == 1)
      return false;
  }

  row_index = row;
  col_index = col;
  while (row_index >= 0 && col_index >= 0)
  {
    if (chessBoard[row_index][col_index] == 1)
      return false;
    row_index--;
    col_index--;
  }

  row_index = row;
  col_index = col;

  while (row_index >= 0 && col_index < n)
  {
    if (chessBoard[row_index][col_index] == 1)
    {
      return false;
    }
    row_index--;
    col_index++;
  }

  return true;
}
bool chess(int **board,int row,int size)
{
	if(row==size)
	{
		return true;
	}
	for(int j=0;j<size;j++)
	{
		if(issafe(board,row,j,size))
		{
			board[row][j]=1;
			
			if(chess(board,row+1,size))
			{
				return true;
			}
			
			board[row][j]=0;
		}
	}
	return false;
}
int main()
{
	int size;
	
	cout << "Enter Size of Chess Board to Place Queens : ";
	cin >> size;
	
	int **board=new int*[size];
	for(int i=0;i<size;i++)
	{
		board[i]=new int [size];
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			board[i][j]=0;
		}
	}
	if(chess(board,0,size))
	{
		cout << "Solution Found\n";
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<< board[i][j]<<"   ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout << "No Solution Found\n";
	}
}
