#include<iostream>
using namespace std;

class Employee{
	
	public:
		string name;
	    string code;
	    
	    Employee(string n,string c):name(n),code(c){
	    	
		}
		
		
};

class Consultant: virtual public Employee{
	
	public:
		int yoex;
		
		Consultant(int y,string n,string c):yoex(y),Employee(n,c){
			
		}
	
};

class Manager: virtual public Employee{
	
	public:
		int noteam;
		
		Manager(int no,string n,string c):noteam(no),Employee(n,c){
			
			
		}
};

class ConsultantManager: public Manager, public Consultant{
	
	public:
		
		ConsultantManager(int no,int y,string n,string c):Manager(no,n,c),Consultant(y,n,c),Employee(n,c){
			
		}
		display(){
			
			cout<<"The employee name is: "<<name<<endl;
			cout<<"The employee code is: "<<code<<endl;
			cout<<"The no of years of experience for consultant is: "<<yoex<<endl;
			cout<<"The no of teams for manager are: "<<noteam<<endl<<endl;
			
		}
};

int main(){
	
	
	ConsultantManager c(17,5,"ALI","S-123");
	c.display();
	return 0;

}
