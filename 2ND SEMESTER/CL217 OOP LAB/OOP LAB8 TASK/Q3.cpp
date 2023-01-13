#include<iostream>
using namespace std;

class Person{
	
	public:
		int employeeid;
		
		getData(){
		
		}
		
		displayData(){
			
		}
	
};

class Admin:public Person{
	
		public:
		string noe;
		float min;
		getData(){
			cout<<"Enter the employee id of admin: ";
			cin>>employeeid;
			cout<<"Enter the admin name: ";
			cin>>noe;
			cout<<"Enter the montholy income: ";
			cin>>min;
		}
		
		displayData(){
			cout<<"The admin name: "<<noe<<endl;
				cout<<"The employee id is: "<<employeeid<<endl;
			cout<<"The montholy income is: "<<min<<endl;
		}
		
		bonus(){
			float bb;
			bb=(min*12) +((min*12)*5/100);
			cout<<"The anual salary after 5% bonus is: "<<bb<<endl;
		}

}; 

class Accounts:public Person{
	
		public:
		string noe;
		float min;
		getData(){
			cout<<"Enter the employee id of accounts: ";
			cin>>employeeid;
			cout<<"Enter the accounts name: ";
			cin>>noe;
			cout<<"Enter the montholy income: ";
			cin>>min;
			
		}
		
		displayData(){
			cout<<"The admin name: "<<noe<<endl;
				cout<<"The employee id is: "<<employeeid<<endl;
			cout<<"The montholy income is: "<<min<<endl;
			
		}
		
		bonus(){
			float bb;
			bb=(min*12) +((min*12)*5/100);
			cout<<"The anual salary after 5% bonus is: "<<bb<<endl;
			
		}

}; 

int main(){
	Admin a1;
	a1.getData();
	cout<<endl;
	
	
	Accounts a2;
	a2.getData();
		cout<<endl;
		a1.displayData();
		cout<<endl;
	a1.bonus();
		cout<<endl;
		
	a2.displayData();
		cout<<endl;
	a2.bonus();
		cout<<endl;
	
}

