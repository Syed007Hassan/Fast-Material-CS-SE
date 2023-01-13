#include<iostream>
using namespace std;

class Calc{
	
	public:
		float h1;
		
		
		func(float r){
			
			h1=r*r*r;
		cout<<"The Volume of Cylinder is: "<<h1<<endl;
		}
		
		func(float r,float h){
			
			h1=3.142*r*r*h;
			cout<<"The Volume of Cylinder is: "<<h1<<endl;
			
		}
	
	    func(float l,float b,float h){
			
			h1=3.142*l*l*h;
			cout<<"The Volume of Rectangular Box is: "<<h1<<endl;
			
		}
		
};

int main(){
	
	Calc a;
	a.func(5.5);
	a.func(3.2,8,9);
	a.func(4,6.7,4.3);
	
}

