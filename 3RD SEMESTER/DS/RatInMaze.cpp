#include <iostream>

using namespace std;

// Reading the Current Index if it is Open or Blocked
bool isOpen(int **maze, int row, int col, int n)
{
  if (row < n && col < n && maze[row][col] == 1)
    return true;

  return false;
}

bool RatInMaze(int **maze, int row, int col, int n, int **path)
{
  if ((row == (n - 1)) && (col == (n - 1)))
  {
    path[row][col] = 1;
    
    return true;
  }

  if (isOpen(maze, row, col, n))
  {

    path[row][col] = 1; // Take the Step

    if (RatInMaze(maze, row, col + 1, n, path))
    {
      return true;
    }

    if (RatInMaze(maze, row + 1, col, n, path))
    {
      return true;
    }

    path[row][col] = 0; // Backtrack your Step
    return false;
  }

  return false;
}

int main()
{
  int n = 6, row, col;
  int **maze = new (nothrow) int *[n];

  for (row = 0; row < n; row++)
  {
    maze[row] = new (nothrow) int[n]{};
  }

  int **path = new (nothrow) int *[n];
  for (row = 0; row < n; row++)
  {
    path[row] = new (nothrow) int[n]{};
  }

  int maze_5[5][5] = {{1, 0, 1, 0, 1},
                      {1, 1, 1, 1, 1},
                      {0, 1, 0, 1, 1},
                      {1, 0, 0, 1, 1},
                      {1, 1, 1, 0, 1}};

  int maze_5_1[5][5] = {{1, 0, 1, 0, 1},
                        {1, 0, 1, 1, 1},
                        {1, 1, 1, 0, 1},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1}};

  int maze_5_2[5][5] = {{1, 1, 1, 1, 1},
                        {0, 0, 1, 0, 1},
                        {1, 1, 1, 0, 1},
                        {1, 0, 1, 0, 1},
                        {0, 1, 0, 0, 1}};

  int maze_5_3[5][5] = {{1, 1, 1, 1, 1},
                        {1, 0, 1, 0, 1},
                        {1, 1, 1, 0, 1},
                        {1, 0, 1, 0, 1},
                        {1, 1, 1, 1, 1}};

  int maze_6[6][6] = {{1, 0, 1, 0, 1, 1},
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
      maze[row][col] = maze_6[row][col];   //sending maze6 in maze
      cout << maze[row][col] << "\t";
    }
  }
  if (RatInMaze(maze, 0, 0, n, path))
  {
    cout << "\n\n\t\t<<<<<<<<<<<<<<<<<<<<<\tPATH FOUND\t>>>>>>>>>>>>>>>\n\n";
    for (row = 0; row < n; row++)
    {
      cout << endl;
      for (col = 0; col < n; col++)
      {
        cout << path[row][col] << "\t";
      }
    }
  }
  else
  {
    cout << "No path FOund";
  }
  return 0;
}
