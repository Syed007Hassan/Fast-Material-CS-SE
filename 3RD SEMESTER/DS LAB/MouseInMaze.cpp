#include<iostream>
using namespace std;

bool isSafe(int **arr, int r, int c, int n){
	
	 if(r < n && c < n && arr[r][c] == 1 ){
	 	return true;
	 }
	 
	 return false;
	 
}
	 
bool rateinMaze(int **arr, int r, int c, int n, int **solArr){
	
	if( (r == (n - 1)) && (c == (n - 1)) )
	{
		solArr[r][c] == 1;
		return true;
	}
	
	if(isSafe(arr, r, c, n))
	{
		
		solArr[r][c] == 1;
		
		if(rateinMaze(arr, r, c+1, n, solArr)){
			return true;
		}
		
		if(rateinMaze(arr, r+1, c, n, solArr)){
			return true;
		}
		
		solArr[r][c] == 0; //backtracking occurs here
		
		return false;
		
	}
	
	    return false;
	
}

int main(){
	
	int n = 6, row, col;
  int **arr = new (nothrow) int *[n];

  for (row = 0; row < n; row++)
  {
    arr[row] = new (nothrow) int[n]{};
  }

  int **solArr = new (nothrow) int *[n];
  for (row = 0; row < n; row++)
  {
    solArr[row] = new (nothrow) int[n]{};
  }


  int maze[6][6]    = {{1, 0, 1, 0, 1, 1},
                      {1, 0, 1, 1, 1, 1},
                      {1, 0, 1, 1, 1, 1},
                      {1, 1, 1, 0, 1, 1},
                      {1, 0, 1, 1, 0, 1},
                      {1, 0, 0, 1, 1, 1}};

  for (int row = 0; row < n; row++)
  {
    cout << endl;
    for (int col = 0; col < n; col++)
    {
      arr[row][col] = maze[row][col];   //sending maze6 in maze
      cout << maze[row][col] << "\t";
    }
  }
  if (rateinMaze(arr, 0, 0, n, solArr))
  {
    cout << "\n\n\t\t<<<<<<<<<<<<<<<<<<<<<\tPATH FOUND\t>>>>>>>>>>>>>>>\n\n";
    for (row = 0; row < n; row++)
    {
      cout << endl;
      for (col = 0; col < n; col++)
      {
        cout << solArr[row][col] << "\t";
      }
    }
  }
  else
  {
    cout << "No path FOund";
  }
  return 0;
}
