#include<iostream>
using namespace std;

class Vehicle{
	
	public:
		string model;
		int speed;
		int nowheel;
};

class Car:public Vehicle{
	
	public:
		int cc;
		Car():model("MERCEDEZ BENZ"),speed(250),nowheel(4),cc(1800){
		}
};

class Bike:protected Vehicle{
	int brakes;
	public:
		
		Bike():model("Kawasaki Ninja"),speed(280),nowheel(2),brakes(3){
		}
};

class Bus:protected Vehicle{
	int passengerseat;
	public:
		Bus():model("Highway Runner"),speed(200),nowheel(6),passengerseat(150){
			
		}
};

int main(){
	Bus b1;
}
