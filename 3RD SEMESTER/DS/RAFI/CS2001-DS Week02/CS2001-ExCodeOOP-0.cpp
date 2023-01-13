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


// driver program 

int main(){
	
	Base be;
	
	Base b2(be);
	
	
	
	return 0;
	
	
	
}
