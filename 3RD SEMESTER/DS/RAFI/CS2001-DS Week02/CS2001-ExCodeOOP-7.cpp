/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Virtual Destructor                                              *
* Dated: September 18, 2007                                                *
* Version: 1.2   ctor/dtor                                                 *                                                 
* Last modified: September 28, 2007                                        *
****************************************************************************/

#include<iostream>

using namespace std;

class Base{
     private:
        int *b;
     public: 
         Base(){
		 b = new int;
		 *b=0;
		 cout<< "Constructor of Base"<<endl;}
         virtual ~Base() {cout<< "Destructor of Base"<<endl;}
};

class Derived : public Base{
	
	private:
        int *d;
     public: 
         Derived(){
		 d = new int;
		 *d=0;
		 cout<< "Constructor of Derived "<<endl;}
         ~Derived(){cout<< "Destructor of Derived"<<endl;}
	
	
};

// driver program 

int main(){
	
	// base class pointer 
	Base *b ;
	// a derived class object pointed wth a base class pointer -legitimate
	b= new Derived();
	
	// pointer b deleted - see the treatment of object pointed here..
	delete b;
	
	
	// Objective: make the base class destructor as virtual and see the output once again
	
	
	
}

