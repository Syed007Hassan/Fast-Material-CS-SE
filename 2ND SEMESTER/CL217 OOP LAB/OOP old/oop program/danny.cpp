#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
// KEY ASSUMPTION: Assuming that taxis are used to transport individuals and hotel staff, and shuttles are used to transport
// people to/from entertainment venues and tourist organizations.
class Vehicle{
	private:
		static int available_vehicles;
	public:
		Vehicle(){
			available_vehicles--;
		}
		static bool isAvailable(){
			if (available_vehicles == 0){
				return false;
			}else{
				return true;
			}
		}
		void Arrive(string point, string customer){
			ofstream os("C:\\travel_log.txt", ios::app);
			string line;
			if (point == "pickup"){
				line = "[pickup] " + customer;
			}else if (point == "destination"){
				line = "[destination] " + customer;
			}
			os << line << endl;
			os.close();
		}
		virtual void Schedule() = 0;
};
int Vehicle::available_vehicles = 10;
class Taxi: public Vehicle{
	private:
		static int available_taxis;
	public:
		static bool isAvailable(){
			if (available_taxis == 0){
				return false;
			}else{
				return true;
			}
		}
		void Schedule(){
			available_taxis--;
			cout << "A taxi has been scheduled!" << endl;
		}
};
int Taxi::available_taxis = 5;
class Shuttle: public Vehicle{
	private:
		static int available_shuttles;
	public:
		static bool isAvailable(){
			if (available_shuttles == 0){
				return false;
			}else{
				return true;
			}
		}
		void Schedule(){
			available_shuttles--;
			cout << "A shuttle has been scheduled!" << endl;
		}
};
int Shuttle::available_shuttles = 5;
int main(){
	bool stop = false;
	char choice2;
	do{
		if (Vehicle::isAvailable()){
			int choice;
			Vehicle* ob;
			system("cls");
			cout << "What type of customer are you?" << endl;
			cout << "1. Individual" << endl;
			cout << "2. Hotel" << endl;
			cout << "3. Entertainment Venue" << endl;
			cout << "4. Tourist Organization" << endl;
			cout << "Your Choice: ";
			cin >> choice;
			switch(choice){
				case 1:
					if (Taxi::isAvailable()){
						ob = new Taxi;
						ob->Schedule();
						// Assuming that a taxi arrives at its pickup point 2 seconds after it's scheduled
						Sleep(2000);
						ob->Arrive("pickup", "individual");
						// Assuming that a taxi arrives at its destination 2 seconds after it arrives at its pickup point
						Sleep(2000);
						ob->Arrive("destination", "individual");
					}else{
						cout << "No taxis available" << endl;
					}
					break;
				case 2:
					if (Taxi::isAvailable()){
						ob = new Taxi;
						ob->Schedule();
						// Assuming that a taxi arrives at its pickup point 2 seconds after it's scheduled
						Sleep(2000);
						ob->Arrive("pickup", "hotel");
						// Assuming that a taxi arrives at its destination 2 seconds after it arrives at its pickup point
						Sleep(2000);
						ob->Arrive("destination", "hotel");
					}else{
						cout << "No taxis available" << endl;
					}
					break;
				case 3:
					if (Shuttle::isAvailable()){
						ob = new Shuttle;
						ob->Schedule();
						// Assuming that a taxi arrives at its pickup point 2 seconds after it's scheduled
						Sleep(2000);
						ob->Arrive("pickup", "entertainment venue");
						// Assuming that a taxi arrives at its destination 2 seconds after it arrives at its pickup point
						Sleep(2000);
						ob->Arrive("destination", "entertainment venue");
					}else{
						cout << "No taxis available" << endl;
					}
					break;
				case 4:
					if (Shuttle::isAvailable()){
						ob = new Shuttle;
						ob->Schedule();
						// Assuming that a taxi arrives at its pickup point 2 seconds after it's scheduled
						Sleep(2000);
						ob->Arrive("pickup", "tourist organization");
						// Assuming that a taxi arrives at its destination 2 seconds after it arrives at its pickup point
						Sleep(2000);
						ob->Arrive("destination", "tourist organization");
					}else{
						cout << "No taxis available" << endl;
					}
					break;
				default:
					cout << "Error: Invalid customer type." << endl;
					cout << "Press any key to try again" << endl;
					getch();
					main();
			}
			cout << "Would you like to make another call? (y/n)" << endl;
			cin >> choice2;
			if (choice2 != 'y'){
				stop = true;
			}
		}else{
			cout << "There are no vehicles available." << endl;
			stop = true;
		}
	}while (!stop);
	return 0;
}
