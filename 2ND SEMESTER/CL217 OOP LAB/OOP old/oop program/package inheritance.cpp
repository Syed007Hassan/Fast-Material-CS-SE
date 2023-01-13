#include<iostream>
using namespace std;
class package{
	
	string senname;
	string senaddress;
	string sencity;
	string senstate;
	int senzipcode;
	string recname;
	string recaddress;
	string reccity;
	string recstate;
	int reczipcode;
	double weightperounce;
	double costperounce;
	public:
		package(string sname,string saddress,string scity,string sstate,int szipcode,string rname,string raddress,string rcity,string rstate,int rzipcode,double wperounce )
		{
	weightperounce=wperounce;
	 senname=sname;
	 senaddress=saddress;
	 sencity=scity;
	 senstate=sstate;
	 senzipcode=szipcode;
	 recname=rname;
	 recaddress=raddress;
	  reccity=rcity;
	 recstate=rstate;
	 reczipcode=rzipcode;
		}
		string getsenname()
		{
			return senname;
		}
		string getsenaddress()
		{
			return senaddress;
		}
		string getsencity()
		{
			return sencity;
		}
		string getsenstate()
		{
		return senstate;
		}
		int getsenzipcode()
		{
			return senzipcode;
		 }
		 string getrecname()
		{
			return recname;
		}
		string getrecaddress()
		{
			return recaddress;
		}
		string getreccity()
		{
			return reccity;
		}
		string getrecstate()
		{
		return recstate;
		}
		int getreczipcode()
		{
			return reczipcode;
		 } 
		 
		 double getweight()
		 {
		 	return weightperounce;
		 }
		 double getcost()
		 {
		 	return costperounce;
		 }
		 double costcalculate(double w)
		 {
		 	double cost;
		 	cost=costperounce*w;
		 	return cost;
		 }
};
class twodaypackage:public package
{private:
double flatfee;
public :
 twodaypackage(string sendername,string senderaddress,string sendercity,string senderstate,int senderzipcode,string recievername,string recieveraddress,string recievercity,string recieverstate,int recieverzipcode,double weightperounce):package( sendername, senderaddress,sendercity,senderstate, senderzipcode,recievername, recieveraddress,recievercity, recieverstate,recieverzipcode, weightperounce)
 {
 }
 
double twodaycost(double ff,double w)
{
    double tcost;
	tcost=ff +costcalculate(w);
	return tcost;
}
};
class overnightpackage:public package
{
	public:
		overnightpackage(string sendername,string senderaddress,string sendercity,string senderstate,int senderzipcode,string recievername,string recieveraddress,string recievercity,string recieverstate,int recieverzipcode,double weightperounce):package( sendername, senderaddress,sendercity,senderstate, senderzipcode,recievername, recieveraddress,recievercity, recieverstate,recieverzipcode, weightperounce)
		{
		}
		double costovernight(double additionalcharges,double weight)
		{
			double z;
			z=(additionalcharges*weight)+costcalculate(weight);
			return z;
		}
};
int main()
{
	 
	string sendername;
	string senderaddress;
	string sendercity;
	string senderstate;
	int senderzipcode;
	string recievername;
	string recieveraddress;
	string recievercity;
	string recieverstate;
	int recieverzipcode;
	double weightperounce;
	cout<<"\n\tWELCOME TO DHL";
	cout<<"\n please complete folowing requirement";
	cout<<"\nSENDERNAME:";
	cin>>sendername;
	fflush(stdin);
	cout<<"\nSENDER ADDRESS:";
	cin>>senderaddress;
	fflush(stdin);
	cout<<"\nSENDER CITY:";
	cin>>sendercity;
	cout<<"\nSENDER STATE:";
	cin>>senderstate;
	fflush(stdin);
	cout<<"\nSENDER ZIPCODE:";
	cin>>senderzipcode;
	fflush(stdin);
	cout<<"\nWEIGHT OF PARCEL:";
	cin>>weightperounce;
	fflush(stdin);
	cout<<"\nRECIEVER NAME:";
	cin>>sendername;
	fflush(stdin);
	cout<<"\nRECIEVER ADDRESS:";
	cin>>senderaddress;
	fflush(stdin);
	cout<<"\nRECIEVER  CITY:";
	cin>>sendercity;
	cout<<"\nRECIEVER STATE:";
	cin>>senderstate;
	fflush(stdin);
	cout<<"\nRECIEVER ZIPCODE:";
	cin>>senderzipcode;
	fflush(stdin);
	//package p( sendername, senderaddress,sendercity,senderstate, senderzipcode,recievername, recieveraddress,recievercity, recieverstate,recieverzipcode, weightperounce);
		 
	
	 
cout<<"\nchoose any one option"; 
	cout<<"   1- Calculate Base Cost  "<<endl<<endl; 
    cout<<"   2- Calculate Two Day Cost "<<endl<<endl; 
    cout<<"   3- Calculate Over Night Cost"<<endl<<endl; 
    int c;
    cin>>c;
    switch(c)
    {
    	case 1:
    		{	overnightpackage onp(sendername, senderaddress,sendercity,senderstate, senderzipcode,recievername, recieveraddress,recievercity, recieverstate,recieverzipcode, weightperounce);
system("cls");
	cout<<"\n\tCUSTOMER PACKAGE DETAIL";
	cout<<"\nSENDER NAME:"<<onp.getsenname();
	cout<<"\nSENDER ADRESS:"<<onp.getsenaddress();
	cout<<"\nSENDER CITY:"<<onp.getsencity();
	cout<<"\nSENDER STATE:"<<onp.getsenstate();
	cout<<"\nSENDER ZIPCODE:"<<onp.getsenzipcode();
	cout<<"\n RECIEVER NAME:"<<onp.getrecname();
	cout<<"\nRECIEVER ADDRESS:"<<onp.getrecaddress();
	cout<<"\nRECIEVER CITY:"<<onp.getreccity();
	cout<<"\nRECIEVER STATE:"<<onp.getrecstate();
	cout<<"\nRECIEVER ZIPCODE:"<<onp.getreczipcode();
	cout<<"\nWEIGHT OF PACKAGE:"<<onp.getweight();
    			cout<<"\nThe base cost is "<<onp.costcalculate(weightperounce);
    			break;
			}
		case 2:
			{double f;
			twodaypackage tdp(sendername, senderaddress,sendercity,senderstate, senderzipcode,recievername, recieveraddress,recievercity, recieverstate,recieverzipcode, weightperounce);
			cout<<"\nenter flat fee:";
			cin>>f;
			//twodaypackage(f);
			system("cls");
	cout<<"\n\tCUSTOMER PACKAGE DETAIL";
	cout<<"\nSENDER NAME:"<<tdp.getsenname();
	cout<<"\nSENDER ADRESS:"<<tdp.getsenaddress();
	cout<<"\nSENDER CITY:"<<tdp.getsencity();
	cout<<"\nSENDER STATE:"<<tdp.getsenstate();
	cout<<"\nSENDER ZIPCODE:"<<tdp.getsenzipcode();
	cout<<"\n RECIEVER NAME:"<<tdp.getrecname();
	cout<<"\nRECIEVER ADDRESS:"<<tdp.getrecaddress();
	cout<<"\nRECIEVER CITY:"<<tdp.getreccity();
	cout<<"\nRECIEVER STATE:"<<tdp.getrecstate();
	cout<<"\nRECIEVER ZIPCODE:"<<tdp.getreczipcode();
	cout<<"\nWEIGHT OF PACKAGE:"<<tdp.getweight();
 cout<<"\nTHE TWO DAY PACKAGE COST:"<<tdp.twodaycost(f,weightperounce);
			break;
			}
		case 3:{
			double ac;
				overnightpackage onp(sendername, senderaddress,sendercity,senderstate, senderzipcode,recievername, recieveraddress,recievercity, recieverstate,recieverzipcode, weightperounce);

			cout<<"\n enter additional charges:";
			cin>>ac;
			fflush(stdin);
			system("cls");
	cout<<"\n\tCUSTOMER PACKAGE DETAIL";
	cout<<"\nSENDER NAME:"<<onp.getsenname();
	cout<<"\nSENDER ADRESS:"<<onp.getsenaddress();
	cout<<"\nSENDER CITY:"<<onp.getsencity();
	cout<<"\nSENDER STATE:"<<onp.getsenstate();
	cout<<"\nSENDER ZIPCODE:"<<onp.getsenzipcode();
	cout<<"\n RECIEVER NAME:"<<onp.getrecname();
	cout<<"\nRECIEVER ADDRESS:"<<onp.getrecaddress();
	cout<<"\nRECIEVER CITY:"<<onp.getreccity();
	cout<<"\nRECIEVER STATE:"<<onp.getrecstate();
	cout<<"\nRECIEVER ZIPCODE:"<<onp.getreczipcode();
	cout<<"\nWEIGHT OF PACKAGE:"<<onp.getweight();
			cout<<"\nTHE OVER NIGHT PACKAGE COST:"<< onp.costovernight(ac,weightperounce);
			break;
		}
	}
	
}
