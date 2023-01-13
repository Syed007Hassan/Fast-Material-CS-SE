#include<iostream>
using namespace std;

class complex{
	
	private:
		
		float a;
		float b;
	
	public:
		complex(void);
		void printno();
	
};

complex::complex(void){
	
	cout<<"Enter the real no ";
	cin>>a;
	cout<<"Enter the imaginary no ";
	cin>>b;
	
}

void complex::printno(){
	
	cout<<"The complex no is "<<a<<" + "<<b<<"i"<<endl;
	
}


int main(){
	
	complex c1,c2;
	c1.printno();
	c2.printno();
	
	return 0;
	
}
