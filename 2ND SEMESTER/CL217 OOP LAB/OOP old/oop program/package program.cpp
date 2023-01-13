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
		void setsenname(string sname)
		{
			senname=sname;
		}
		void setsenddress(string saddress)
		{
			senaddress=saddress;
		}	 
		void setsencity(string scity)
		{
			sencity=scity;
		}
		void setsenzipcode(int szipcode)
		{
			senzipcode=szipcode;
		}
		void setsenstate(string sstate)
		{
			senstate=sstate;
		}
		void setrecname(string rname)
		{
			recname=rname;
		}
		void setrecaddress(string raddress)
		{
			recaddress=raddress;
    	}	 
		void setreccity(string rcity)
		{
			reccity=rcity;
		}
		void setreczipcode(int rzipcode)
		{
			reczipcode=rzipcode;
		}
		void setrecstate(string rstate)
		{
			recstate=rstate;
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
		 void setweight(double w)
		 {
		 	weightperounce=w;
		 }
		 void setcost(double c)
		 {
		 	costperounce=c;
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
	class twodaypackage :public package
	{
		double flatfee;
		
		public:
			void setflatfee(double ff)
			{
				flatfee=ff;
			}
			double getflatfee()
			{
				return flatfee;
			}
			double twodaycost(double w)
			{
				flatfee=flatfee+costcalculate(w);
				return flatfee;
			} 
			
	};
	class overnightpackage:public package
	{ 
	public:
		double costovernight(double additionalcharges,double weight)
		{
			double z;
			z=(additionalcharges*weight)+costcalculate(weight);
			return z;
		}
	};
//	void display()
//	{
	//	package p;
			
//	}
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
	double weightp ;
	double costp;
	package p;
		cout<<"\n\t'WELCOME TO DHL'\n\n";
	cout<<"\n please complete folowing requirement";
	cout<<"\nSENDERNAME:";
	cin>>sendername;
	p.setsenname(sendername);
	fflush(stdin);
	cout<<"\nSENDER ADDRESS:";
	cin>>senderaddress;
	p.setsenddress(senderaddress);
	fflush(stdin);
	cout<<"\nSENDER CITY:";
	cin>>sendercity;
	p.setsencity(sendercity);
	cout<<"\nSENDER STATE:";
	cin>>senderstate;
	p.setsenstate(senderstate);
	fflush(stdin);
	cout<<"\nSENDER ZIPCODE:";
	cin>>senderzipcode;
	p.setsenzipcode(senderzipcode);
	fflush(stdin);
	cout<<"\nWEIGHT OF PARCEL:";
	cin>>weightp;
	p.setweight(weightp);
	fflush(stdin);
	cout<<"\nRECIEVER NAME:";
	cin>>recievername;
	p.setrecname(recievername);
	fflush(stdin);
	cout<<"\nRECIEVER ADDRESS:";
	cin>>recieveraddress;
	p.setrecaddress(recieveraddress);
	fflush(stdin);
	cout<<"\nRECIEVER  CITY:";
	cin>>recievercity;
	p.setreccity(recievercity);
	cout<<"\nRECIEVER STATE:";
	cin>>recieverstate;
	p.setrecstate(recieverstate);
	fflush(stdin);
	cout<<"\nRECIEVER ZIPCODE:";
	cin>>recieverzipcode;
	p.setreczipcode(recieverzipcode);
	fflush(stdin);
	overnightpackage onp;
	twodaypackage tdp;
	 cout<<"\nchoose any one option\n"; 
	cout<<"   1- Calculate Base Cost  "<<endl<<endl; 
    cout<<"   2- Calculate Two Day Cost "<<endl<<endl; 
    cout<<"   3- Calculate Over Night Cost"<<endl<<endl; 
    int c;
    cin>>c;
    switch(c)
    {
    	case 1:
    		{
    			//display();
    				system("cls");
	cout<<"\n\tCUSTOMER PACKAGE DETAIL";
	cout<<"\nSENDER NAME:"<<p.getsenname();
	cout<<"\nSENDER ADRESS:"<<p.getsenaddress();
	cout<<"\nSENDER CITY:"<<p.getsencity();
	cout<<"\nSENDER STATE:"<<p.getsenstate();
	cout<<"\nSENDER ZIPCODE:"<<p.getsenzipcode();
	cout<<"\n RECIEVER NAME:"<<p.getrecname();
	cout<<"\nRECIEVER ADDRESS:"<<p.getrecaddress();
	cout<<"\nRECIEVER CITY:"<<p.getreccity();
	cout<<"\nRECIEVER STATE:"<<p.getrecstate();
	cout<<"\nRECIEVER ZIPCODE:"<<p.getreczipcode();
	cout<<"\nWEIGHT OF PACKAGE:"<<p.getweight();
    			cout<<"\nThe Base Cost is:"<<p.costcalculate(weightp);
    			break;
			}
		case 2:
			{
				double f;
				cout<<"enter flat fee:";
				cin>>f;
			tdp.setflatfee(f);
				fflush(stdin);
			//	display(); 
				system("cls");
	cout<<"\n\tCUSTOMER PACKAGE DETAIL";
	cout<<"\nSENDER NAME:"<<p.getsenname();
	cout<<"\nSENDER ADRESS:"<<p.getsenaddress();
	cout<<"\nSENDER CITY:"<<p.getsencity();
	cout<<"\nSENDER STATE:"<<p.getsenstate();
	cout<<"\nSENDER ZIPCODE:"<<p.getsenzipcode();
	cout<<"\n RECIEVER NAME:"<<p.getrecname();
	cout<<"\nRECIEVER ADDRESS:"<<p.getrecaddress();
	cout<<"\nRECIEVER CITY:"<<p.getreccity();
	cout<<"\nRECIEVER STATE:"<<p.getrecstate();
	cout<<"\nRECIEVER ZIPCODE:"<<p.getreczipcode();
	cout<<"\nWEIGHT OF PACKAGE:"<<p.getweight();
				cout<<"\nThe Two day
				 Cost is:"<<tdp.twodaycost(weightp);
				break;
			}
		case 3:
			{
				double ac;
				cout<<"\nenter additional charges:";
				cin>>ac;
			//	display();
				system("cls");
	cout<<"\n\tCUSTOMER PACKAGE DETAIL";
	cout<<"\nSENDER NAME:"<<p.getsenname();
	cout<<"\nSENDER ADRESS:"<<p.getsenaddress();
	cout<<"\nSENDER CITY:"<<p.getsencity();
	cout<<"\nSENDER STATE:"<<p.getsenstate();
	cout<<"\nSENDER ZIPCODE:"<<p.getsenzipcode();
	cout<<"\n RECIEVER NAME:"<<p.getrecname();
	cout<<"\nRECIEVER ADDRESS:"<<p.getrecaddress();
	cout<<"\nRECIEVER CITY:"<<p.getreccity();
	cout<<"\nRECIEVER STATE:"<<p.getrecstate();
	cout<<"\nRECIEVER ZIPCODE:"<<p.getreczipcode();
	cout<<"\nWEIGHT OF PACKAGE:"<<p.getweight();
				cout<<"\nThe over night cost is:"<<onp.costovernight(ac,weightp);
				break;
			}
	}
	
	}
