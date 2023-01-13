#include<iostream>
using namespace std;

class Grandfather{
	public:
		string factory;
		
		Grandfather():factory("TIMBER FACTORY"){
		} 
};

class Father:public Grandfather{    //base classs
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
		cout<<"Factory: "<<factory<<endl;
	}
};

int main(){
	
	Child Ali;	
}
