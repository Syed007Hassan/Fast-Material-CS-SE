
#include<iostream>
using namespace std;


class A
{
public :
    int a;
    A(){ cout<<"default constructor"<<endl;};
    A(const A& other){ cout<<"copy constructor"<<endl;};
    A& operator = (const A& other){cout <<"assignment operator"<<endl;}
};

int main()
{
    A sampleObj; //Calls default constructor
    sampleObj.a = 10;

    A copyConsObj  = sampleObj; //Initializing calls copy constructor

    A assignOpObj; //Calls default constrcutor
    assignOpObj = sampleObj; //Object Created before so it calls assignment operator
    
    return 0;
}
