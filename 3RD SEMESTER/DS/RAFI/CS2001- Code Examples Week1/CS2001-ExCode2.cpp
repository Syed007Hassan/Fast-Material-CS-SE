/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: C++ Language Specification  (Examples)                          *
* Dated: August 28, 2007                                                   *
* Version: 1.2   updates on range and circular linked values               *                                                 
* Last modified: September 02, 2007                                        *
****************************************************************************/

#include<iostream>

using namespace std;

int main()
{
	
	/****************************************************************************
	* OBJECTIVE: Data Types and sizes                                          *
	* Basic Data Types                                                         *
	* There are five basic data types in C++                                   *
	* char, int, float, double, void                                           *
	* We can midify these type by using type modifers                          *                                                 
	* signed, unsigned,long,short                                              *
	****************************************************************************/
  char c;   // character type vairable c
  int i;    // integer type variable i
  float f;   // floate type variable f
  double d;  // double type variable d
  bool b;   // boolean type not in standard c++
  
   
   /* size of basic types in term of bytes */
   cout<< sizeof(c)<< " Bytes" <<endl;
   cout<< sizeof(i)<< " Bytes" <<endl;
   cout<< sizeof(f)<< " Bytes" <<endl;
   cout<< sizeof(d)<< " Bytes" <<endl;
   cout<< sizeof(b)<< " Bytes" <<endl;
  
  
  return 0;
  }
