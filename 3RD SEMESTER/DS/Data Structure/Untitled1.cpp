#include<iostream>
#include<string.h>

using namespace std;

bool right(char **p,int row,int col,int nrows,int ncol,string line)
{
	int count=0;
	for(int j=col;j<ncol;j++)
	{
		if(p[row][j]==line[count])
		{
			count++;
		}
		if(p[row][j]=='+')
		{
			count++;
		}
		if(p[row][j]=='*')
		{
			int check1=line.length();
			if(p[row][j+1]==line[check1-1])
			{
				count=line.length();
				break;
			}
		}
	}
	if(count==line.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool down(char **p,int row,int col,int nrows,int ncol,string line)
{
	int count=0;
	for(int j=row;j<nrows;j++)
	{
		if(p[j][col]==line[count])
		{
			count++;
		}
		if(p[j][col]=='+')
		{
			count++;
		}
		if(p[j][col]=='*')
		{
			int check1=line.length();
			if(p[j+1][col]==line[check1-1])
			{
				count=line.length();
				break;
			}
		}
	}
	if(count==line.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool left(char **p,int row,int col,int nrows,int ncol,string line)
{
	int count=0;
	for(int j=col;j>=0;j--)
	{
		if(p[row][j]==line[count])
		{
			count++;
		}
		if(p[row][j]=='+')
		{
			count++;
		}
		if(p[row][j]=='*')
		{
			int check1=line.length();
			if(p[row][j+1]==line[check1-1])
			{
				count=line.length();
				break;
			}
		}
	}
	if(count==line.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool up(char **p,int row,int col,int nrows,int ncol,string line)
{
	int count=0;
	for(int j=row;j>=0;j--)
	{
		if(p[j][col]==line[count])
		{
			count++;
		}
		if(p[j][col]=='+')
		{
			count++;
		}
		if(p[j][col]=='*')
		{
			int check1=line.length();
			if(p[j+1][col]==line[line.length()-1])
			{
				count=line.length();
				break;
			}
		}
		
	}
	if(count==line.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkindex(int row,int col,int noofrow,int noofcol)
{
	if(row<noofrow&&col<noofcol)
	{
		return true;
	}
	return false;
}
bool wordfinder(char **ptr,string line,int length,int n_rows,int n_columns,int i,int j) 
{
	
	if(i==n_rows)
	{
		return true;
	}
	if (j==n_rows-1)
	{
	
		if(line[0]==ptr[i][j])
		{
			if(right(ptr,i,j,n_rows,n_columns,line))
			{
				cout << i << " "<< j<< " R\n";
			}
			if(down(ptr,i,j,n_rows,n_columns,line))
			{
				cout << i << " "<< j<< " D\n";
			}
			if(up(ptr,i,j,n_rows,n_columns,line))
			{
				cout << i << " "<< j<< " U\n";
			}
			if (left(ptr,i,j,n_rows,n_columns,line))
			{
				cout << i << " "<< j<< " L\n";
			}
			
		}
		wordfinder(ptr,line,length,n_rows,n_columns,i+1,0);
		
	}
	else
	{

		if(line[0]==ptr[i][j])
		{
			
			if(right(ptr,i,j,n_rows,n_columns,line)==true)
			{
				cout << i << " "<< j<< " R\n";
			}
			if(down(ptr,i,j,n_rows,n_columns,line))
			{
				cout << i << " "<< j<< " D\n";
			}
			 if(up(ptr,i,j,n_rows,n_columns,line))
			{
				cout << i << " "<< j<< " U\n";
			}
			if (left(ptr,i,j,n_rows,n_columns,line))
			{
				cout << i << " "<< j<< " L\n";
			}
			
		}
		wordfinder(ptr,line,length,n_rows,n_columns,i,j+1);
	
	}

}
int main()
{
	int row,column,i,j,numberOfwords;
	
	cout << "Enter number of rows : ";
	cin >> row;
	cout <<"Enter number of Column ";
	cin >>column;
	
	char **p = new char* [row];
	
	for(i=0;i<row;i++)
	{
		p[i] = new char [column];
	}
	
	for(i=0;i<row;i++)
	{
		cout << "Enter elements of row "<<i+1<< " : ";
		for(j=0;j<column;j++)
		{
			cin >> p[i][j];
		}
	}
	cout << "Enter number of word to find : ";
	cin >> numberOfwords;
	
	string array[numberOfwords];
	
	for(i=0;i<numberOfwords;i++)
	{
		cout << "Enter Word "<<i+1<<" : ";
		fflush(stdin);
		cin >> array[i];
	}
	
// Logic
	int rowI,colI;
	
	for(i=0;i<numberOfwords;i++)
	{
		wordfinder(p,array[i],array[i].length(),row,column,0,0);
		
		

	}		
}
