#include <iostream>
using namespace std;

class shape
{
	public:
		double length;
		double breadth,a;
		shape(double a , double b){
			length= a;
			breadth= b;
		}
		area(){
			a= breadth * length;
			cout<<" shape class"<<endl<<"Area of rectangle is "<<a<<endl;
		}
};
class rectangle : public shape{
	public:
		rectangle (double a,double b) : shape(a,b){
			
		}
		area(){
			a=breadth*length;
			cout<<"  rectangle class"<<endl<<"Area of rectangle is "<<a<<endl;

		}
};

int main(){
	double a,b;
	cout<<"Enter length and breadth respectively."<<endl;
	cin>>a>>b;
	shape s(a,b);
	s.area();
	cout<<endl<<"Enter length and breadth respectively."<<endl;
	cin>>a>>b;
	rectangle r(a,b);
	r.area();
	
}
		
