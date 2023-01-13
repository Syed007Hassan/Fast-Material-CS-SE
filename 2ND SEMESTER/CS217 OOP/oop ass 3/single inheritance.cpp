#include<iostream>
using namespace std;

class Father{    //base classs
	public:
		double money;
		string house;
		string car;
		
		Father():money(999999),house("VILLA"),car("Porshe"){
			
		}
};

class Child:protected Father{    //single inheritance, derived class
	public:
		
	Child(){
		cout<<"The child owns: "<<endl;
		cout<<"House: "<<house<<endl;
		cout<<"Money: "<<money<<endl;
		cout<<"Car: "<<car<<endl;
	}
};

int main(){
	
	Child Ali;	
}
