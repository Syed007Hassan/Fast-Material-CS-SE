#include <iostream>
using namespace std;

int main(){
	
char mname[50];
	int noadtic,nochdtic,ttic;
	double padult,pchild;
	double grossamount,damount,pgross,nsale;
	
	cout<<"Enter the movie name: ";
    cin.getline(mname,50);
	
	cout<<"Enter the price of adult ticket: ";
	cin>>padult;
	
	cout<<"Enter the price of child ticket: ";
	cin>>pchild;
	
	cout<<"Enter the no of adult tickets: ";
	cin>>noadtic;
	
	cout<<"Enter the no of child tickets: ";
	cin>>nochdtic;
	
	cout<<"Enter the percentage of gross amount to be donated to charity: ";
	cin>>pgross;
	
	ttic=(noadtic + nochdtic);
	grossamount=(padult*noadtic + pchild*nochdtic);
	
	damount=(grossamount*pgross)/100;
	
	nsale=grossamount-damount;
	
	
	cout<<"******************************************************************** "<<endl;
	cout<<"Movie name is:                        "<<mname<<endl;
	cout<<"No of tickets sold are:               "<<ttic<<endl;
	cout<<"Gross amount is:                    $ "<<grossamount<<endl;
	cout<<"Percentage of gross amount donated:   "<<pgross<<"%"<<endl;
	cout<<"Amount donated:                     $ "<<damount<<endl;
	cout<<"Net sale:                           $ "<<nsale<<endl; 
	
	
	
}

