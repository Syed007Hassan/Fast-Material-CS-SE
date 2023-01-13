#include <iostream>
using namespace std;

class Person{
	
	public:
		string name;
		int id;
		float bon,sal;
		
		virtual void getdata()=0;
		virtual void display()=0;
        virtual void bonus()=0;
			
};

class Admin: virtual public Person{
	  
	  public:
	  	
	  	void getdata(){
	  		cout<<"Enter the name of ADMIN: ";
	  		cin>>name;
	  		cout<<"Enter the id: ";
	  		cin>>id;
	  		cout<<"Enter the salary: ";
	  		cin>>sal;
	  		cout<<endl;
	  		
		  }
		  
		void bonus(){
			float ff;
			cout<<"Enter the percentage of bonus for admin btw 5-15: ";
			cin>>ff;
			
			bon=sal+(sal*ff)/100;
				cout<<endl;
		}
		
		void display(){
			cout<<"NAME: "<<name<<endl;
			cout<<"ID: "<<id<<endl;
			cout<<"SALARY: "<<sal<<endl;
			cout<<"SALARY AFTER BONUS: "<<bon<<endl;
				cout<<endl;
		}
	
}; 

class Account: virtual public Person{
	
	public:
		
		void display(){
			cout<<"NAME: "<<name<<endl;
			cout<<"ID: "<<id<<endl;
			cout<<"SALARY: "<<sal<<endl;
			cout<<"SALARY AFTER BONUS: "<<bon<<endl;
			
			if(sal > 25000 && bon >8){
				cout<<"The person has a filer account "<<endl;
			}
				else{
					cout<<"the person needs to have a filer account asap "<<endl;
				}
				
					cout<<endl;
			}
			
			void getdata(){
			cout<<"Enter the name of accounts: ";
	  		cin>>name;
	  		cout<<"Enter the id: ";
	  		cin>>id;
	  		cout<<"Enter the salary: ";
	  		cin>>sal;
	  			cout<<endl;
				
			}
			void bonus(){
			float ff;
			cout<<"Enter the percentage of bonus for account btw 5-15: ";
			cin>>ff;
			
			bon=sal+(sal*ff)/100;
				cout<<endl;
				
			}
		
		
};

class Masterclass: public Account,public Admin{
	
	public:
		
		void getdata(){
			 Admin:: getdata();
			 Account::getdata();
		}
		void bonus(){
		   	Admin::bonus();
		   	Account::bonus();
		}
		
		void display(){
		 Admin::display();
		 Account::display();
		}
		

	
}; 


int main(){
	
   Admin a,*ptr;
   Account a1,*p;
   Masterclass m,mm;
   
   ptr=&m;
   
   ptr->getdata();
   ptr->bonus();
   ptr->display();

   

}
