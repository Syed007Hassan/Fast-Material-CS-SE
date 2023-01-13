#include <iostream>
using namespace std;
class Vehicle{
	private:
		string typeOfCar;
		string make;
		string model;
		string color;
		int year;
		double miles_driven;
	public:
		Vehicle(){
		}
		Vehicle(string typeOfCar, string make, string model, string color, int year, double miles_driven){
			this->typeOfCar = typeOfCar;
			this->make = make;
			this->model = model;
			this->color = color;
			this->year = year;
			this->miles_driven = miles_driven;
		}
		string gettypeOfCar(void){
			return typeOfCar;
		}
		string getmake(void){
			return make;
		}
		string getmodel(void){
			return model;
		}
		string getcolor(void){
			return color;
		}
		int getyear(void){
			return year;
		}
		double getmiles_driven(void){
			return miles_driven;
		}
};
class GasVehicle: virtual public Vehicle{
	private:
		double fuel_tank_size;
	public:
		GasVehicle(){
		}
		GasVehicle(string typeOfCar, string make, string model, string color, int year, double miles_driven, double fuel_tank_size): Vehicle(typeOfCar, make, model, color, year, miles_driven){
			this->fuel_tank_size = fuel_tank_size;
		}
		double getfuel_tank_size(void){
			return fuel_tank_size;
		}
};
class ElectricVehicle: virtual public Vehicle{
	private:
		double energy_storage;
	public:
		ElectricVehicle(){
		}
		ElectricVehicle(string typeOfCar, string make, string model, string color, int year, double miles_driven, double energy_storage): Vehicle(typeOfCar, make, model, color, year, miles_driven){
			this->energy_storage = energy_storage;
		}
		double getenergy_storage(void){
			return energy_storage;
		}
};
class HighPerformance: public GasVehicle{
	private:
		double horse_power;
		double top_speed;
	public:
		HighPerformance(){
		}
		HighPerformance(string typeOfCar, string make, string model, string color, int year, double miles_driven, double fuel_tank_size, double horse_power): Vehicle(typeOfCar, make, model, color, year, miles_driven), GasVehicle(typeOfCar, make, model, color, year, miles_driven, fuel_tank_size){
			this->horse_power = horse_power;
			this->top_speed = top_speed;
		}
		double gethorse_power(void){
			return horse_power;
		}
		double gettop_speed(void){
			return top_speed;
		}
};
class HeavyVehicle: public GasVehicle, public ElectricVehicle{
	private:
		double max_weight;
		int no_of_wheels;
		double length;
	public:
		HeavyVehicle(){
		}
		HeavyVehicle(string typeOfCar, string make, string model, string color, int year, double miles_driven, double fuel_tank_size, double energy_storage, double max_weight, int no_of_wheels, double length): Vehicle(typeOfCar, make, model, color, year, miles_driven), GasVehicle(typeOfCar, make, model, color, year, miles_driven, fuel_tank_size), ElectricVehicle(typeOfCar, make, model, color, year, miles_driven, energy_storage){
			this->max_weight = max_weight;
			this->no_of_wheels = no_of_wheels;
			this->length = length;
		}
		double getmax_weight(void){
			return max_weight;
		}
		int getno_of_wheels(void){
			return no_of_wheels;
		}
		double getlength(void){
			return length;
		}
};
class SportsCar: public HighPerformance{
	private:
		string gearbox;
		string drive_system;
	public:
		SportsCar(){
		}
		SportsCar(string typeOfCar, string make, string model, string color, int year, double miles_driven, double fuel_tank_size, double horse_power, string gearbox, string drive_system): Vehicle(typeOfCar, make, model, color, year, miles_driven), HighPerformance(typeOfCar, make, model, color, year, miles_driven, fuel_tank_size, horse_power){
			this->gearbox = gearbox;
			this->drive_system = drive_system;
		}
		string getgearbox(void){
			return gearbox;
		}
		string getdrive_system(void){
			return drive_system;
		}
};
class ConstructionTruck: public HeavyVehicle{
	private:
		string cargo;
	public:
		ConstructionTruck(){
		}
		ConstructionTruck(string typeOfCar, string make, string model, string color, int year, double miles_driven, double fuel_tank_size, double energy_storage, double max_weight, int no_of_wheels, double length, string cargo): Vehicle(typeOfCar, make, model, color, year, miles_driven), HeavyVehicle(typeOfCar, make, model, color, year, miles_driven, fuel_tank_size, energy_storage, max_weight, no_of_wheels, length){
			this->cargo = cargo;
		}
		string getcargo(void){
			return cargo;
		}
};
class Bus: public HeavyVehicle{
	private:
		int num_of_seats;
	public:
		Bus(){
		}
		Bus(string typeOfCar, string make, string model, string color, int year, double miles_driven, double fuel_tank_size, double energy_storage, double max_weight, int no_of_wheels, double length, int num_of_seats): Vehicle(typeOfCar, make, model, color, year, miles_driven), HeavyVehicle(typeOfCar, make, model, color, year, miles_driven, fuel_tank_size, energy_storage, max_weight, no_of_wheels, length){
			this->num_of_seats = num_of_seats;
		}
		void Display(){
			cout << "Type of Car: " << gettypeOfCar() << endl;
			cout << "Make: " << getmake() << endl;
			cout << "Year: " << getyear() << endl;
			cout << "Miles driven: " << getmiles_driven() << endl;
			cout << "Fuel tank size: " << getfuel_tank_size() << endl;
			cout << "Energy Storage: " << getenergy_storage() << endl;
			cout << "Maximum Weight: " << getmax_weight() << endl;
			cout << "Number of Wheels: "<< getno_of_wheels() << endl;
			cout << "Length: " << getlength() << endl;
			cout << "Number of seats: " << num_of_seats << endl;
		}
};
int main(){
	Bus ob("sportscar", "Porsche", "cbw", "silver", 2018, 1234, 12312, 121231, 780000, 6, 580, 65);
	ob.Display();
	return 0;
}

