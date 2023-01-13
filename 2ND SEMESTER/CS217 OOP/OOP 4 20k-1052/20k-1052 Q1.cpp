#include<iostream>
using namespace std;

class Temp{
	
	int data;
	
	public:
		
		Temp(int i):data(i){
			
		}
		
		show(){
			cout<<data;
		}
		
		void operator ++(void){  //++t 
			data=data+3;
		}
		
		void operator ++(int){    //t++
			data=data-5;
		}
	
};

int main(){
	
	
	Temp t(10);
	++t;          //first 10+3

    t++;         //then 13-5
	t.show();
}
