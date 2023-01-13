/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: C++ Language Specification  (Examples)                          *
* Dated: August 28, 2007                                                   *
* Version: 1.2   updates on range and circular linked values               *                                                 
* Last modified: September 02, 2007                                        *
****************************************************************************/

#include<iostream>

#define EXIT_SUCESS 0

using namespace std;

int main()
{
	
	/****************************************************************************
	* OBJECTIVE: Data Types and sizes                                          *
	* Basic Data Types                                                         *
	* There are five basic data types in C++                                   *
	* char, int, float, double, void                                           *
	* We can midify these type by using type modifers                          *                                                 
	* signed, unsigned, long,short                                             *
	****************************************************************************/
  char c;
  signed char sc;
  unsigned char uc;
  
  int i;
  signed int si;
  unsigned int ui;
  short int shorti;
  short signed int ssi;
  short unsigned int sui;
  long int longi;
  long signed int lsi;
  long unsigned int lui;
  
  float f;
  double d;
  long double ld;
  
  bool b;
  
  
  /* Assignment to the character variables as per limits */ 
    c= 'c';    // -127 to 127
    sc = c +128;  // -127 to 127
    uc = -c-255;  // 0 to 255
   cout<< c <<endl;
   cout<< sc <<endl;
   cout<< uc <<endl;
   /* do the increment and see how the limits work */
   
    /* Assignment to the integer variables as per limits */ 
    i= -32767;   // -32767 to 32767 
    si = - 32767;
    ui = 65535;
   cout<< i <<endl;
   cout<< si <<endl;
   cout<< ui <<endl;
   /* do the increment and see how the limits work */
   
   
    /* Assignment to the integer variables as per limits */ 
    f= 2.3456789;   // six digits of precision 
    d = 0.0000000003478;   // ten digits of precision 
    ld = 0.00000000034785; 
   cout<< f <<endl;
   cout<< d <<endl;
   cout<< ld <<endl;
   /* do the increment and see how the limits work */
   
  
  
  return EXIT_SUCESS;
  }
