#include <iostream>

using namespace std;

bool isSafe(int **chessBoard, int row, int col, int n)
{
  int row_index=0, col_index=0;
  for (row_index = 0; row_index < row; row_index++)   //checking rows for a 1
  {
    if (chessBoard[row_index][col] == 1)
      return false;
  }

  row_index = row;
  col_index = col;
  while (row_index >= 0 && col_index >= 0)
  {
    if (chessBoard[row_index][col_index] == 1)   cross diagonal check
      return false;
    row_index--;
    col_index--;
  }

  row_index = row;
  col_index = col;

  while (row_index >= 0 && col_index < n)  //upward diagonal check
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

bool PlaceQueen(int **chessBoard, int row, int n)
{
  if (row >= n)        //base case
    return true;
  
  
  for (int col = 0; col < n; col++)
  {
    if (isSafe(chessBoard, row, col, n))     //recursive case
    {
      chessBoard[row][col] = 1;

      if (PlaceQueen(chessBoard, row + 1, n))
      {
        return true;
      }

      chessBoard[row][col] = 0;
    }
  }

  return false;
}

int main()
{
  int n = 6;

  int **chessBoard = new (nothrow) int *[n];
  for (int i = 0; i < n; i++)
  {
    chessBoard[i] = new (nothrow) int[n]{};
  }

  if (PlaceQueen(chessBoard, 0, n))
  {
    for (int row = 0; row < n; row++)
    {
      cout << endl;
      for (int col = 0; col < n; col++)
      {
        cout << chessBoard[row][col] << "\t";
      }
    }
  }
}
