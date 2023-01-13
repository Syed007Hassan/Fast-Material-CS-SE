#include<iostream>
using namespace std;

class Vehicle{
	public:
		string toc;
		int make;
		string colour;
		int year;
		int md;
		
		Vehicle(string toc,int make,string colour,int year, int md):toc(toc),make(make),colour(colour),year(year),md(md){
			
		}
	
};

class GasVehicle:  public virtual Vehicle{
	public:
		int fts;
		
		GasVehicle(int f,string toc,int make,string colour,int year, int md):fts(f),Vehicle(toc,make,colour,year,md){
			
		}
};

class ElectricVehicle:  public virtual Vehicle{
	public:
		int es;
		
		ElectricVehicle(int e,string toc,int make,string colour,int year, int md):es(e),Vehicle(toc,make,colour,year,md){
			
		}
		
	};
	
class HeavyVehicle: public GasVehicle,public ElectricVehicle{
	
	public:
		int weight;
		int now;
		int length;
		
		HeavyVehicle(int wei,int now,int len,int e,int f,string toc,int make,string colour,int year, int md):weight(wei),now(now),length(len),ElectricVehicle(e,toc,make,colour,year,md),GasVehicle(f,toc,make,colour,year,md),Vehicle(toc,make,colour,year,md){
			
		}
	
};



class HighPerformance: public GasVehicle{
	
	public:
		int hp;
		int ts;
		
		HighPerformance(int hpp,int tss,int f,string toc,int make,string colour,int year, int md):hp(hpp),ts(tss),GasVehicle(f,toc,make,colour,year,md),Vehicle(toc,make,colour,year,md){
			
		}
	
};


class SportsCar: public HighPerformance{
	
	public:
		
		SportsCar(int hpp,int tss,int f,string toc,int make,string colour,int year, int md):HighPerformance(hpp,tss,f,toc,make,colour,year,md),Vehicle(toc,make,colour,year,md){
		}
	gearbox(){
		cout<<"There are two types of gear box\n\t 1-Manual 2-Automatic"<<endl;
	}
	drive_sys(){
		cout<<"There are two types of drive system\n\t 1-Rear wheel  2-Front wheel"<<endl;
	}

};
class ConstructionTruck: public HeavyVehicle{
	
	public:
		ConstructionTruck(int weight,int now,int length,int e,int f,string toc,int make,string colour,int year, int md):HeavyVehicle(weight,now,length,e,f,toc,make,colour,year,md),Vehicle(toc,make,colour,year,md){
			
		}
		
		cargo(){
			cout<<"The cargo item needs cement, gravel and sand\n";
		}
		
};

class Bus: public HeavyVehicle{
	
	public:
		int nos;
		Bus(int nos,int weight,int now,int length,int e,int f,string toc,int make,string colour,int year, int md):nos(nos),HeavyVehicle(weight,now,length,e,f,toc,make,colour,year,md),Vehicle(toc,make,colour,year,md){
			
		}
		
		Display() {
			cout << "\t\t\n\t Type of Car: " << toc<<endl;
			cout << "\t\t\n\t Make: " << make<<endl;
			cout << "\t\t\n\t Colour: " << colour<<endl;
			cout << "\t\t\n\t Type: " << toc<<endl;
			cout << "\t\t\n\t Year: " << year<<endl;
			cout << "\t\t\n\t Miles Driven: " << md<< " km\n";
			cout << "\t\t\n\t Feul tank size: " << fts<<" litres\n";
			cout << "\t\t\n\t Energy Storage: " << es<<" Joules\n";
			cout << "\t\t\n\t Weight: " << weight<<" Tons\n";
			cout << "\t\t\n\t Number of wheels: " << now<<endl;
			cout << "\t\t\n\t Lenght: " << length<<" m\n";
			cout << "\t\t\n\t Number of seats: " << nos<<endl;
		}
	
};	

int main(){
	
	
   Bus b1(2,1750,4,20,490,40,"Mercedez",2018,"Grey",2021,999);
   b1.Display();
}
