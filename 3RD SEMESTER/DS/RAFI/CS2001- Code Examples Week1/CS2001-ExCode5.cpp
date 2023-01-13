/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: C++ Language Specification  (Examples)                          *
* Dated: August 28, 2007                                                   *
* Version: 1.2   Parameter passing byVal, byRef and byPtr                  *                                                 
* Last modified: September 02, 2007                                        *
****************************************************************************/

#include <iostream>

using namespace std;


void Exchange( int a, int b)
{
	int temp;
	
	temp =a;
	a=b;
	b=temp;

}

void Exchange( int & a, int & b)
{
	int temp;
	
	temp =a;
	a=b;
	b=temp;

}

void Exchange( int * a, int * b)
{
	int temp;
	
	temp =*a;
	*a=*b;
	*b=temp;

}

int main()
{
	int x=18, y=2;
	
	cout << x << "   " << y << endl;
	Exchange(x,y);
	cout << x << "   " << y << endl;
	
	
	
	
	return 0;
}
