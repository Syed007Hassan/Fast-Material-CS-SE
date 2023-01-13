/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Multiple inheritance Constructor/Destructor order               *
* Dated: September 12, 2007                                                *
* Version: 1.2   ctor/dtor                                                 *                                                 
* Last modified: September 20, 2007                                        *
****************************************************************************/

#include<iostream>

using namespace std;

class Base1{
     private:
        int b1;
     public: 
         Base1():b1(0){cout<< "Constructor of Base1"<<endl;}
         ~Base1(){cout<< "Destructor of Base1"<<endl;}
};


class Base2{
     private:
        int b2;
     public: 
         Base2():b2(0){cout<< "Constructor of Base2"<<endl;}
        ~Base2(){cout<< "Destructor of Base2"<<endl;}
 
};

class Derived1: public Base1, public Base2{
      private:
        int d1;
     public: 
         Derived1():d1(0){cout<< "Constructor of Derived1"<<endl;}
         ~Derived1(){cout<< "Destructor of Derived1"<<endl;}
    
};

class Derived2: public Base2, public Base1{
      private:
        int d1;
     public: 
         Derived2():d1(0){cout<< "Constructor of Derived2"<<endl;}
         ~Derived2(){cout<< "Destructor of Derived2"<<endl;}
      
      
      
      
};

int main()
{
    cout<< "Derived One"<<endl;
	Derived1 *d1= new Derived1();
    delete d1;
    cout<< "Derived two"<<endl;
    Derived2 *d2= new Derived2();
    delete d2;
    system("pause");
    return 0;
     
}
