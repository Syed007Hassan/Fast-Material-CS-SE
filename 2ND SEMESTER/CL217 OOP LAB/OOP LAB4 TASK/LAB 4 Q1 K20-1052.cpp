#include<iostream>
#include<iomanip>
using namespace std;

class Circle{
	
	private:
		double radius;
		
		
	public:
	  
	  Circle(double r){    //parameterized constructor
	  	
	  	radius=r;
	  	
	  	cout<<fixed<<setprecision(2)<<"The area is: "<<getArea(radius)<<endl;
	  	
	  	cout<<"The perimeter is: "<<getPeri(radius)<<endl;
	  	
	  	
	  }
	  
	  
	  double getArea(int r){
	  	
	  	double a;
	  	
	  	a=3.142*r*r;
	  	
	  	return a;
	  	
	  }
	  
	  
	  double getPeri(int r){
	  	
	  	double p;
	  	
	  	p=2*3.142*r;
	  	
	  	return p;
	  }
	  
	  ~Circle(){  //destructor
	  	
	  	
	  }
	  	
		
};

int main(){
	double r2;
	cout<<"Enter the radius: ";
	cin>>r2;
	Circle r1(r2);  //calling of parameterized constructor
	
}

