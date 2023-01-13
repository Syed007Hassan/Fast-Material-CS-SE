#include<iostream>
using namespace std;

class Mammals{
	
	public:
		string coat="Hair/fur";
		string heart="Four chambered heart";
		
};

class Landcreatures{
	
	public:
		int run=55;
		
		eat(){
			cout<<"Eat using a claw or hand"<<endl;
		}
		
};

class Lionn:protected Mammals,Landcreatures{
	
	public:
		Lionn(){
		cout<<"Lion has: "<<endl;
		cout<<coat<<endl;
		cout<<heart<<endl;
		cout<<"Speed: "<<run<<endl;
		cout<<eat();
	}
};

int main(){
	
	Lionn a;
}
