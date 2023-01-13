#include<iostream>
using namespace std;
class bankaccount{
	int accno;
	string name;
	string acctype;
	double balance;
	double interestrate;
	public:
		bankaccount(int accno,string acctype,double balance,  string name )
		{
			this->accno=accno;
			this->acctype=acctype;
			this->balance=balance;
			this->name=name;
		//	this->interestrate=interestrate;
			
			
		}
		
		void depositamount()
		{
		double a;
		cout<<"\nenter amount for deposit:";
		cin>>a;
		balance+=a;
			cout<<"\nyour current balance is>>"<<balance;
		cout<<"\nTHANK YOU!!";
		}
		void withdrawamount()
		{
			double w;
			cout<<"\nenter amount for withdraw:";
			cin>>w;
			 if(w>balance)
                cout<<"\n Cannot Withdraw Amount";
		else	balance-=w;
		cout<<"\n sucessfulyy withdraw money";
		cout<<"\nyour current balance is>>"<<balance;
		cout<<"\nTHANK YOU!!";
			
		}
		void show()
		{
			cout<<"\n\taccount information";
			cout<<"\nname:"<<name;
			cout<<"\naccount no:"<<accno;
			cout<<"\naccount type:"<<acctype;
			cout<<"\n balance:"<<balance; 
		}
		void setinterest()
		{
			interestrate=(balance*10*5)/100;
		}
		double getinterestrate()
		{
			return interestrate;
		} 
 
};
int main()
{
	int a ;
	string b;
	string c;
	double d;
	//double e;
	cout<<"\nenter name:";
	cin>>b;
	fflush(stdin);
	cout<<"\nenter account no:";
	cin>>a;
	fflush(stdin);
	cout<<"\nenter account type:";
	cin>>c;
	fflush(stdin);
	cout<<"\nenter balance:";
	cin>>d;
	fflush(stdin);
  bankaccount b1(a,c,d,b);
  cout<<"\n information saved!!";
 fflush(stdin);
 	 cout<<"\n\nwhat do u want";
  cout<<"\n1.withdraw";
  cout<<"\n2.deposit";
  cout<<"\n3.show detail";
  int choice;
  cin>>choice;
  switch(choice)
  {
  	case 1:
  	{
  		b1.withdrawamount();
  		break;
    }
    case 2:
    	{
    		b1.depositamount();
    		break;
		}
	case 3:
		{
			b1.show();
			b1.setinterest();
			cout<<"\ninterest rate:"<<b1.getinterestrate();
			break;
		}
  
}


		}
