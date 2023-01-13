#include<iostream>
using namespace std;

class Add{
	
	public:
		
		static int a,b;
		
		static sum(){
			
			float add;
			
			cout<<"Enter the value of a: ";
			cin>>a;
			
			cout<<"Enter the value of b: ";
			cin>>b;
			
			add=a+b;
			
			cout<<"The sum is "<<add<<endl;
			
		}	
	
};

    int Add::a=0;
    int Add::b=0;


int main(){
	
	Add a1;
	a1.sum();
	
}
