/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: C++ Language Specification  (Examples)                          *
* Dated: August 28, 2007                                                   *
* Version: 1.2   Commandline arguments via main                            *                                                 
* Last modified: September 02, 2007                                        *
****************************************************************************/

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // Check the number of parameters
    if (argc < 2) {
        // Tell the user how to run the program
        cerr << "Usage: " << argv[0] << " arguments" << std::endl;
        /* "Usage messages" are a conventional way of telling the user
         * how to run a program if they enter the command incorrectly.
         */
        return 1;
    }
    // Print the arguments 
   cout << argc << endl;
   for (int i=0; i< argc; i++)
   {
   	cout << argv[i] << endl;
   }
       
	return 0;
}


