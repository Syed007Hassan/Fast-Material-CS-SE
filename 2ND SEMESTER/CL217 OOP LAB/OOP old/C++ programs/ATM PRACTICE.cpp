#include<iostream>
using namespace std;

class Atm{
	
	private:
		string accname;
		int pin;
		double amount,balance;
		
	
	public:
		
		readcard(){
			int p;
			cout<<"Welcome to HBL ATM SERVICE"<<endl;
			cout<<"Enter the Pin ";
			cin>>p;
			
			if(p == 786 ){
				
				getinfo();
			}
			else{
			     againpin();	
			}
		}
		
		againpin(){
			int pp;
			
			cout<<"Enter the correct pin"<<endl;
			cin>>pp;
			if(pp == 786){
				getinfo();
			}
			else{
				againpin();
			}
			
		}
		
		getinfo(){
			int ch;
			double temp;
			cout<<"ACCESS GRANTED"<<endl;
			cout<<"1- Get Cash"<<endl;
			cout<<"2- Withdrawl"<<endl;
			cout<<"3- Transfer"<<endl;
			
			cin>>ch;
			
			if(ch == 1){
				
				getcash(temp);
			}
			else if(ch == 2){
				
				withdrawl(temp);
			}
		//	else if(ch == 3){
		//		transfer();
		//	}
		}
		
		getcash(double temp){
             
			 temp=28500;			
			 balance=temp;
			 int y;
			 double am[7]={500,1000,3000,5000,10000,15000,20000};
			cout<<"1- 500  Rs"<<endl;
			cout<<"2- 1000 Rs"<<endl;
			cout<<"3- 3000 Rs"<<endl;
			cout<<"4- 5000 Rs"<<endl;
			cout<<"5- 10000 Rs"<<endl;
			cout<<"6- 15000 Rs"<<endl;
			cout<<"7- 20000 Rs"<<endl;
			
			cin>>y; 
			if(y == 1){
				if(am[0] <= balance ){
					
					balance = balance - am[0];
					cout<<"You have taken "<<am[0]<<" Rs cash from your account"<<endl;
					cout<<"The remaining balance is: "<<balance<<" Rs in your account"<<endl;
			 	cout<<"Thank you for using our service"<<endl;
				}
			}
			else if(y == 2){
				if(am[1] <= balance ){
						balance = balance - am[1];
					cout<<"You have taken "<<am[1]<<" Rs cash from your account"<<endl;
					cout<<"The remaining balance is: "<<balance<<" Rs in your account"<<endl;
			 	cout<<"Thank you for using our service"<<endl;
				}
			}
			else if(y == 3){
				if(am[2] <= balance ){
						balance = balance - am[2];
					cout<<"You have taken "<<am[2]<<" Rs cash from your account"<<endl;
					cout<<"The remaining balance is: "<<balance<<" Rs in your account"<<endl;
			 	cout<<"Thank you for using our service"<<endl;
				}
			}
			else if(y == 4){
				if(am[3] <= balance ){
						balance = balance - am[3];
					cout<<"You have taken "<<am[3]<<" Rs cash from your account"<<endl;
						cout<<"The remaining balance is: "<<balance<<" Rs in your account"<<endl;
			 	cout<<"Thank you for using our service"<<endl;
				}
			}
			else if(y == 5){
				if(am[4] <= balance ){
						balance = balance - am[4];
					cout<<"You have taken "<<am[4]<<" Rs cash from your account"<<endl;
						cout<<"The remaining balance is: "<<balance<<" Rs in your account"<<endl;
			 	cout<<"Thank you for using our service"<<endl;
				}
			}
			else if(y == 6){
				if(am[5] <= balance ){
						balance = balance - am[5];
					cout<<"You have taken "<<am[5]<<" Rs cash from your account"<<endl;
						cout<<"The remaining balance is: "<<balance<<" Rs in your account"<<endl;
			 	cout<<"Thank you for using our service"<<endl;
				}
			}
			else if(y == 7){
				if(am[6] <= balance ){
						balance = balance - am[6];
					cout<<"You have taken "<<am[6]<<" Rs cash from your account"<<endl;
						cout<<"The remaining balance is: "<<balance<<" Rs in your account"<<endl;
			 	cout<<"Thank you for using our service"<<endl;
				}
			}
				
		}
		

		withdrawl(double temp){
			temp=28500;			
			 balance=temp;
			 
			 cout<<"Enter the amount to be withdrawn: ";
			 cin>>amount;
			 
			 if(amount <= balance){
			 	balance = balance - amount;
			 	cout<<"You have withdrawn "<<amount<<" Rs from your account"<<endl;
			 	cout<<"The remaining balance is: "<<balance<<" Rs in your account"<<endl;
			 	cout<<"Thank you for using our service"<<endl;
			 }
			 else{
			 	againbalance(temp);
			 	
			 }
			
		}
		
		againbalance(double temp){
				temp=28500;			
			 balance=temp;
			 
			 cout<<"Insufficient balance, enter correct amount: ";
			 cin>>amount;
			
			if(amount <= balance){
				
				balance = balance - amount;
			 	cout<<"You have withdrawn "<<amount<<" Rs from your account"<<endl;
			 	cout<<"The remaining balance is: "<<balance<<" Rs in your account"<<endl;
			 		cout<<"Thank you for using our service"<<endl;
			}
			else{
				againbalance(temp);
			}
		}
		
		
		
	
};


int main(){
	
	Atm a;
	
	a.readcard();
	
	return 0;
	

}
