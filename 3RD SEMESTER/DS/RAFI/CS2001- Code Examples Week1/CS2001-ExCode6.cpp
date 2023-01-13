/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: C++ Language Specification  (Examples)                          *
* Dated: August 28, 2007                                                   *
* Version: 1.2   default parameters in functions                           *                                                 
* Last modified: September 02, 2007                                        *
****************************************************************************/

#include <iostream>

using namespace std;


int DoIt(int a, int b=5, int c=3)
{

  return a+b+c;
}




int main()
{
	int x=18, y=2, z=1;
	
	cout << DoIt(x)<< endl; 
	cout << DoIt(x,y)<< endl; 
	cout << DoIt(x,y,x)<< endl; 
	
	return 0;
}


