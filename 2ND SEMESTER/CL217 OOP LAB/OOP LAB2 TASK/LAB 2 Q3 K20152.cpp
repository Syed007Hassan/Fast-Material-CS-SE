#include <iostream>
#include <iomanip>

using namespace std;

double regularservice(int accno);
double premiumservice(int accno);

	const float RCF = 10.00;
    const float RR = 0.20;
    const float PAF = 25.00;
    const float PDR = 0.10;
    const float PNR = 0.05;
    
int main(){
	
	int accno;
	char choice;
	
	cout<<"This program calculates the bill for the cellular company\n\n";
	cout<<"Enter the account no: ";
	cin>>accno;
	cout<<"Enter the type of service\n-(R or r) denotes regular bus service\n-(P or p) denotes premium bus service\n";
	cin>>choice;
	
	switch(choice){
		
		case 'r':
		case 'R':
		
		cout<<"The due amount is: $ "<<regularservice(accno);
		break;
		
		case 'p':
		case 'P':
		
		cout<<"The due amount is: $ "<<premiumservice(accno);
		break;
		
		default:
		
		cout<<"Enter the relevent service type code\n";	
	}
	
}

double regularservice(int accno){
	
	float minutes;
	double amount;
	
	cout<<"Enter the no of minutes used by the customer: ";
	cin>>minutes;
	
	if(minutes > 50){
		
		amount=((minutes-50)*RR)+RCF;
	}
	else{
		
		amount=RCF;
	}
	
	cout<<"Account no: "<<accno<<endl;
	cout<<"Type of service: REGULAR"<<endl;
	cout<<"Minutes used: "<<minutes<<endl;
		
	return amount;	
	
}

double premiumservice(int accno){
	
	float dm,nm;
	double amount;
	
	cout<<"Enter the no of minutues used in day: ";
	cin>>dm;
	
	cout<<"Enter the no of minutes used in night: ";
	cin>>nm;
	
	if(dm > 75){
		
		amount=((dm-75)*PDR);
	}
	
	if(nm > 100){
		
		amount=((nm-100)*PNR);
	}
	
	amount= amount + PAF;
	
	cout<<"Account no: "<<accno<<endl;
	cout<<"Type of service: PREMIUM"<<endl;
	cout<<"Minutes used: "<<dm+nm<<endl;
	
	return amount;
	
}


   
