#include<stdio.h>
#include<iostream>
using namespace std;
float x=0;
class invoice
{
private:
string pn;
string pd;
int n;
double p;
public:
invoice(string pn, string pd, int n, double price)
{
cout << " Part # = "<<pn;
cout << "\n Part Description = "<<pd;
cout << "\n quantity = "<<n;
cout << "\n price per item = "<<p;
x = x + getinvoice(n,p);

}

getinvoice(int n, double p)
{
float bill = bill + n * p;
if(bill<0)
{
bill=0;
}
cout <<" INVOICE = "<<bill;
return bill;
}

};
main()
{
cout << "Enter number of purcheses: \n";
int ch;
cin>>ch;

for(int i=0;i<ch;i++)
{
string a,b;
int c;
double d;
cout << "Part # = \n";
cin >> a;
cout << "Part Description: \n";
cin >> b;
cout << "Items: \n";
cin>>c;
cout << "Price: \n";
cin>>d;

invoice in(a,b,c,d);

}

cout <<"\n\n TOTAL BILL : "<<x;
}
