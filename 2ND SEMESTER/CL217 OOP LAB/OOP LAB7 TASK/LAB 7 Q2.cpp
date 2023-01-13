#include<iostream>
#include<string>
using namespace std;

class Vehicle{
	public:
		int price[2];
			
};

class Car:public Vehicle{

	
	public:
		int seatcapacity;
		int nodoor;
		string ftype;
				
};

class Motorcycle:public Vehicle{

	public:
		int nocy;
		int nog;
		int now;
		
};

class Audi:public Car{
	public:
		string mtype;
			
	Audi(){
		
		cout<<"Enter the Price of the Audi vehicle: ";
		cin>>price[0];
		
		cout<<"Enter the seating capacity of the car: ";
		cin>>seatcapacity;
		
		cout<<"Enter the no of doors of the vehicle: ";
		cin>>nodoor;
		
		
		cout<<"Enter the fuel type (diesel or patrol): ";
		getchar();
		getline(cin,ftype);
		
		cout<<"Enter the model type: ";
		getline(cin,mtype);
			
			cout<<endl<<endl;
	}
	
};

class Yamaha: public Motorcycle{
	public:
		string maketype;
		Yamaha(){
		
		cout<<"Enter the Price of the Yahama vehicle: ";
		cin>>price[1];
		
		cout<<"Enter the no of cylinders: ";
		cin>>nocy;
		
		cout<<"Enter the no of gears: ";
		cin>>nog;
		
		cout<<"Enter the no of wheels: ";
		cin>>now;
			
		cout<<"Enter the make type: ";
		getchar();
		getline(cin,maketype);		
		
		cout<<endl<<endl;
		}
		
};

int main(){
	
	Audi a;
	Yamaha b;
	
	cout<<"The details of the Audi vehicle is: "<<endl;
	cout<<"The price is: "<<a.price[0]<<endl;
	cout<<"The seatcapacity is: "<<a.seatcapacity<<endl;
	cout<<"The no of doors of the vehicle is: "<<a.nodoor<<endl;
	cout<<"The fuel type is: "<<a.ftype<<endl;
	cout<<"The model type is: "<<a.mtype<<endl<<endl;
	
	cout<<"The details of the Yamaha vehicle is: "<<endl;
	cout<<"The price is: "<<b.price[1]<<endl;
	cout<<"The no of cylinders is: "<<b.nocy<<endl;
	cout<<"The no of gears is: "<<b.nog<<endl;
	cout<<"The no of wheels: "<<b.now<<endl;
	cout<<"The make type is: "<<b.maketype;
	

}
