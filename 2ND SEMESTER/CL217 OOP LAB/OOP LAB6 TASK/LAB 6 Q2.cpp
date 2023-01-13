#include<iostream>
using namespace std;

class Demos{
	
	const int x;
	int y;
	public:
		
		Demos(int i):x(i){
		}
		
		showMessage(){
			
			cout<<"Inside show message function."<<endl<<endl;
			
		}
	
	display() const{
	
	    cout<<"Inside the display function."<<endl;
	    cout<<x;
	    
	}
	
};

int main(){
	
	
	Demos d1(500);
	
	d1.showMessage();
	d1.display();
}

