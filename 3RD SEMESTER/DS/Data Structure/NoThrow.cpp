#include<iostream>

using namespace std;

int main()
{
// program to make sure whether the desired memory is alloacted or not BY nothrow keyword
// without crashing the program
// if nothrow keyword is not used the program will crash with std::bad_alloc exception
	int *p= new (nothrow) int[-10];
	
	if(!p)
	{
		cout << "Failed";
	}
	else
	{
		cout << "Success";
	}
	delete[]p;
}
