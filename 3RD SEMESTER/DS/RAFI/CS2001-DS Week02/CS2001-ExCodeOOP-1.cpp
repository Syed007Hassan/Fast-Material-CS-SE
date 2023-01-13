#include<iostream>

using namespace std;

class Base{
	
	private: int b;
	
	public:
	Base(){
	
	cout<< "Base class constructor called" << endl;
	
	}
	
	~Base(){
		
	cout<< "Base class destructor called" << endl;	
		
	}
	
	void setB(int be){
		
		b=be;
	}
	

	
	
	
	
};


class Derieved : public Base {
	
	private: int d;
	
	public:
	Derieved(){
	
	cout<< "Derieved class constructor called" << endl;
	
	}
	
	~Derieved(){
		
	cout<< "Derieved class destructor called" << endl;	
		
	}
	
	void setD(int de){
		
		d=de;
	}
	
	
	
	
	
	
	
	
};


// driver program 

int main(){
	
	//Base be;
	
    Derieved de;
	
	
	
	return 0;
	
	
	
}
