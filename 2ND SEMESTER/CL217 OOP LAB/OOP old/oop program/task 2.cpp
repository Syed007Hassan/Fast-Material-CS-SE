#include<iostream>
using namespace std;
class hotel
{
string name;
int noofdays;
float rent;
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
	void bill( )
	{if(noofdays>7)
	{
	noofdays=noofdays-1;
	noofdays=noofdays*1000.85;
	cout<<"\nRENT after discount:"<<noofdays;
	rent=noofdays;
	}
	else{
 noofdays=noofdays*1000.85;
 cout<<"RENT :"<<noofdays;
 rent=noofdays;
}
 
	} 
	display()
	{
	 cout<<"rent"<<rent;
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
    h1.display();
}
