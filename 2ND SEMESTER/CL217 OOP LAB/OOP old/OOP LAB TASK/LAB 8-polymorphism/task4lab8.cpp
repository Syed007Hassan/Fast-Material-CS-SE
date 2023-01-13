#include<iostream>
using namespace std;

class Bank
{
public:
    double getBalance()
    {
        return 0;
    }
};

class BankA : public Bank
{
    double amount;
public:
    BankA(int a)
    {
    	if(a==0)
    	{
    		cout<<"\nerror";
		}
        amount = a;
    }

    double getBalance()
    {
        return amount;
    }
};

class BankB : public Bank
{
   double amount;
public:
    BankB(double  a)
    {
    		if(a==0)
    	{
    		cout<<"\nerror";
		}
        amount = a;
    }

   double getBalance()
    {
        return amount;
    }
};

class BankC : public Bank
{
    double amount;
public:
    BankC(double a)
    {
    		if(a==0)
    	{
    		cout<<"\nerror";
		}
        amount = a;
    }

    double getBalance()
    {
        return amount;
    }
};

int main()
{
	double a1,a2,a3;
	cout<<"\nenter amount to deposit:";
	cin>>a1;
	cout<<"\nenter amount to deposit:";
	cin>>a2;
	cout<<"\nenter amount to deposit:";
	cin>>a3;
    BankA a(a1);
    BankB b(a2);
    BankC c(a3);
    cout << a.getBalance() << endl;
    cout << b.getBalance() << endl;
    cout << c.getBalance() << endl;
    return 0;
}   
