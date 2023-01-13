/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Problem of Magic Square                                         *
* Dated: August 28, 2007                                                   *
* Version: 1.7   Up -> Right approache (for odd n )                        *                                                 
* Last modified: September 12, 2009                                        *
****************************************************************************/

#include<iostream>


using namespace std;

const int N=3;


void Print_MagicSqr(int[N][N], int);

int main()
{
	
	
	int data[N][N]={0};	
	int n=1;
	int i=0;
	int j =N/2;
	
	data[i][j]=n;
	
	while (n <= N*N){
		
		n++;
		i--;
		j++;
		// Boundary conditions for row
		if(i<0)	{
			i= (i+ N);
		}
		else if ( i > N-1)
		{
		  	i=0;
		}
		
		// Boundary Condition for column
		if(j<0)	{
			
		 j= (j+N);
		}
	    else if (j > N-1) {
			
		 j=0;	
		}
		
		// If  row and colum are within grid check for already filled cell.
		if (data[i][j] > 0){
			
			i++;
			if ( i >= N ) i=i-N;
			j=j-1;
			if (j < 0) j=j+N;
			i++;
		}
		
		// empty fill the cell
		data[i][j]=n;  // current n is succesfully places
	
	} // end while (not done till n^2)
	
	Print_MagicSqr(data, N);
	
	return 0;
	
}


void Print_MagicSqr(int d[N][N], int N){
	
	for (int i=0; i< N; i++){
	
	  for (int j=0; j< N; j++)
	  {
	  	   cout <<(d[i][j])<<" " ;
	  	  
      }
       cout<<endl;
   }
}

