#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	double wght,pound;
	
	cout<<"Enter the weight of a person in kg: ";
	cin>>wght;
	
	pound=wght*2.2;
	
	cout<<fixed<<setprecision(6)<<"The weight of the person in pound is: "<<pound<<endl;
}
