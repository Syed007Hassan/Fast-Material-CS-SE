#include<iostream>
using namespace std;
class complex{
public:
    int real;
    int imag;
     void setvalue()
    {
        cin>>real;
        cin>>imag;
    }
    void display()
    {
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    complex operator+(complex c1)
    {
    	complex c2;
        c2.real=real+c1.real;
       c2.imag=imag+c1.imag;
       return c2;
    }
    };
int main()
    {
        complex c1,c2,c3;
        cout<<"Enter real and imaginary part of first complex number"<<endl;
        c1.setvalue();
        cout<<"Enter real and imaginary part of second complex number"<<endl;
        c2.setvalue();
        cout<<"Sum of two complex numbers is"<<endl;
        c3=c1+c2;
        c3.display();
    return 0;
    }
