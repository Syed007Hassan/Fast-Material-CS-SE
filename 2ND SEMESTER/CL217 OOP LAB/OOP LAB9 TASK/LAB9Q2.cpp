#include <iostream>
using namespace std;

class Shape{
	int a,b;
	
	public:
		Shape(int i, int j):a(i),b(j){}
		
		func(){
			cout<<" Area is: "<<a*b<<endl<<endl;
		}
		
		Shape operator+(Shape s){
			
			s.a=s.a+a;
			s.b=s.b+b;
			
			return s;
		}
		
};

int main(){
	
	Shape shape1(3,5),shape2(6,10);
	cout<<"Shape1 ";
	shape1.func();
	
	cout<<"Shape2 ";
	shape2.func();
	
	
	
   Shape shape3=shape1+shape2;
	cout<<"Shape1 + Shape2 ";
	shape3.func();
		
	
}
