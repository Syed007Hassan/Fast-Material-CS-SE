#include <iostream>
using namespace std;

class Car{
	public:
		string model;
		int price;
		
		Car(string a):model(a){
			
		}
		
	   virtual void setPrice()=0;
};

class Colour:public Car{
	public:
		
		Colour(string a):Car(a){
		}
		
	  void setPrice(){
			price=55;
			cout<<"The price of the colour is: "<<price<<endl;
		}
		
	
};

class Company:public Car{
		public:
	
	Company(string a):Car(a){
		
	}
	void setPrice(){
			price=55555;
			cout<<"The price of the car of company AUDI is: "<<price<<endl;
		}
		
};

int main(){
	
	Colour c("AUDI");
	Company c1("AUDI");
	
	cout<<c.model<<endl;
	c.setPrice();
	
	c1.setPrice();
	
	
}
