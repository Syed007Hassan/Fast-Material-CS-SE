#include<iostream>
using namespace std;
classs account
{
	 double balance;
	 public:
	account(double bal)
{
	if (bal<0)
	{
		balance=0;
		cout<<"\n Your initial balance is invalid";
	}
	else
	{
		balance=bal;
	}
}

double getbalance()
{
	return balance;
}
void credit(double amoun)
{
	balance+=amoun;
	
}
void debit(double amoun)
{
	if(amoun)>balance
	{
		cout<<"\nDebit amount exceded current balance!";
	}
	else
	{
		balance-=amoun;
	}
}
};
class savingaccount:public package
{
double interestrate;
public:
savingaccount(double IR)
{
	interestrate=IR;
}
double calinterestrate(double IR)
{
	IR=(balance*IR)/100;
	return IR;
}


	
};
		
}
