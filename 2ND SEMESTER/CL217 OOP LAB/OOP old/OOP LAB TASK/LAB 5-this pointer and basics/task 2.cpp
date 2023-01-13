#include<iostream>
using namespace std;
class hotel
{
string name;
int noofdays;
public:
 hotel(string name,int noofdays)
 {
 	this->name=name;
 	this->noofdays=noofdays;
	 }	
  string getname() const
	{
		return name;
	}
	int getdays()
	{
		return noofdays;
	}
	void bill(double d)
	{if(d>7)
	{
	d=d-1;
	d=d*1000.85;
	cout<<"\nRENT after discount:"<<d;
	}
	else{
 d=d*1000.85;
 cout<<"RENT :"<<d;
}
 
	} 
};
int main()
{
	string n;
	double d;
	cout<<"\twelcome to hotel 'Hotel Mercato'"<<endl;
	cout<<"name>>";
	cin>>n;
	fflush(stdin);
	cout<<"No of days>>";
	cin>>d;
	hotel h1(n,d);
	
	cout<<"\n\t<<bill reciept>>\n\n";
	cout<<"\nNAME:"<<h1.getname();
     h1.bill(d);
	
}
