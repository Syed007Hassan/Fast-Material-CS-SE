#include <iostream>
using namespace std;
 
class InDec{

    int n1;
	
	public:
	
	InDec(int a):n1(a){
	}
	
	func(){
		cout<<"The number before prefix and postfix is: "<<n1<<endl<<endl;
	}
	func1(){
		cout<<"PREFIX: the number after the multiplication by 4 is: "<<n1<<endl<<endl; 
	}
	
	func2(){
		cout<<"POSTFIX: the number after the divison by 4 is: "<<n1<<endl<<endl; 
	}
	
	void operator--(){
		n1=n1*4;
	}
	
	
	void operator--(int i){
		i=4;
		n1=n1/4;
	}
	
}; 

int main(){
	
	InDec a(44);
	a.func();
	--a;
	a.func1();
	
	
	a--;
	a.func2();
	
	
	
}
