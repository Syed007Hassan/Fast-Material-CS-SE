#include<iostream>
#define N 10
using namespace std;
class system{
	protected:
		int noofvehcle;
		string drivername;
		double rate;
	public:
		virtual void dropoff(string l)=0;   //virtual functions which is used 
		virtual void pickup(string l)=0;   //by th class of taxi and shuttle 
		virtual int driveravailaible()=0;
	void setdname(string dn)
		{
			drivername=dn;
		}
		string getdname()
		{
			return drivername;
		}
	system()
	{
	   
	}
};
class taxi:public system
{
	public:
		void calculaterate(double k)
		{
			rate =k*6;
		}
                double getrate()
		{
			return rate;
		}	
	
		void pickup(string l) 
		{
			cout<<"\ntaxi is booked !";
			cout<<"\npickup location:"<<l;
			n--;
		}
		void dropoff(string l )
		{
			cout<<"\ndrop off location:"<<l;
		}
		taxi()
		{
		}
		~taxi()
		{
			cout<<"\n passenger dropped!";
		}
		int driveravailaible()
		{
			return n;
		}
		
	
};
class shuttle :public system
{
	public:
		int driveravailaible()
		{
			return n;
		}
		void calculaterate(double k)
		{
			rate =k*6;
		}
		double getrate()
		{
			return rate;
		}
		void pickup(string l)
		{
			cout<<"\nshuttle is booked !";
			cout<<"\npickup location:"<<l;
			n--;
		}
		void dropoff(string l )
		{
			cout<<"\ndropped location: "<<l;
		}
//		~shuttle()
//		{
//			cout<<"\n passener dropped!";
//		}
};
int main()
{
	taxi t;
	shuttle s;
	double km;
	string pl,dl;
	string dname;		 //asking driver about his recent passenger directory
	int n;
	cout<<"\nenter your name:";
	cin>>dname;
	cout<<"\nenter no of passenger:";
	cin>>n;
	cout<<"\nenter pickup location:";
	cin>>pl;
	cout<<"\nenter dropoff location: ";
	cin>>dl;
	cout<<"\nenter kilometer :";
	cin>>km;
	
	if(n==1) //if passenger is 1 shuttle will book otherwise shuttle will book
	{
		int x;
		x=s.driveravailaible();             //checking if driver is availaible
 		if(x==0)                              
		{
			cout<<"\nno shuttle availaible";
		}
		else
		{
		cout<<"\npassenger travel log";
		s.setdname(dname);
		s.pickup(pl);
		cout<<"\ndrivername:"<<s.getdname();
		cout<<"\nno of passenger:"<<n;
		s.dropoff(dl);
		s.calculaterate(km);
		cout<<"\ncalculated fare:"<<s.getrate()<<"$";}
	}
	else 
	{
		int x;
		x=s.driveravailaible();
		if(x==0)
		{
			cout<<"\nno shuttle availaible";
		}
		else
		{
		cout<<"\npassenger travel log";
		t.setdname(dname);
		t.pickup(pl);
		cout<<"\ndrivername:"<<t.getdname();
		cout<<"\nno of passenger:"<<n;
		t.dropoff(dl);
		t.calculaterate(km);
		cout<<"\ncalculated fare:"<<t.getrate()<<"$";}
	}
	
}
