#include <iostream>
using namespace std;

int showChoices();
void feetAndInchesToMetersAndCent(float feet, float inches);
void metersAndCentTofeetAndInches(float meters, float centi);

int main(){
	int x;
	float feet,inches,meters,centi;

	x=showChoices();
	
	
	switch(x){
		
		case 1:
			
			cout<<"Enter the length in feet: ";
			cin>>feet;
			cout<<"Enter the lengthin inches: ";
			cin>>inches;
			cout<<endl;
			feetAndInchesToMetersAndCent(feet,inches);
			
			break;
			
        case 2:
        	cout<<"Enter the length in meter: ";
			cin>>meters;
			cout<<"Enter the lengthin centimeter: ";
			cin>>centi;
			cout<<endl;
			metersAndCentTofeetAndInches(meters, centi);
        	
        	break;
        
		case 3:
		cout<<"Program terminated\n";
		break;

			
        default:
		
		cout<<"Enter the correct option\n";
		main();
		break;

}

}

int showChoices(){
	
	int chooi;
	cout<<"Enter 1 for converting feet and inches to meters and centimeter\nEnter 2 for converting meters and centimeter to feet and inches\nEnter 3 for exit\n";
	cin>>chooi;
	
	return chooi;
}

void feetAndInchesToMetersAndCent(float feet, float inches){
	
	float ff,ii;

	ff=feet*0.3048;
	ii=inches*2.54;
	
	cout<<feet<<" feet in meters is: "<<ff<<endl;
	cout<<inches<<" inches in centimeter is: "<<ii<<endl;
	
		cout<<endl;
	main();
	
}

void metersAndCentTofeetAndInches(float meters, float centi){
	
	float mm,cm;
	

	mm=meters*3.28084;
	cm=centi*0.393701;
	
	cout<<meters<<" meters in feet is: "<<mm<<endl;
	cout<<centi<<" centimeters in inches is: "<<cm<<endl;
	
		cout<<endl;
	main();	
	
}
