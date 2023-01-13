/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: C++ Language Specification  (Examples)                          *
* Dated: August 28, 2007                                                   *
* Version: 1.2   Parameter passing byVal, byRef and byPtr                  *                                                 
* Last modified: September 02, 2007                                        *
****************************************************************************/

#include <iostream>

using namespace std;

// addOne function with parameter as value 
int addOne( int a)
{ 
  return ++a;
}

// addOne function with parameter as reference ( a constant Pointer) 
int addOne(int &a)
{
	return a++;
}


//addone function with parameter as Pointer 
int addOne(int * a)
{
  return *a++;
}



	/****************************************************************************
	* OBJECTIVE: Parameter Passing by Value, by Ref, by Pointer                *
	* Functions and Parameter                                                  *
	* The value is passed as copy and does not change the actual parameter     *
	* The reference is passed as original variable                             *
	* The pointer is passed as original variables but note the access          *                                                 
	*  This is very important concept, try these three functions 1 by 1        *
	****************************************************************************/

int main()
{
 int x=0;
 int y= addOne(x);
 cout << x << endl;
 cout << y << endl;	
	
	
	return 0;
}
