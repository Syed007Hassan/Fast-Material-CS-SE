#include<iostream>
using namespace std;
class heartrate{
	string firstname;
	string lastname;
	int byear;
	int bmonth;
	int bday;
	 
	int maxhr;
	int curday;
	int curmon;
	int curyear;
	public:
		heartrate(string Fname,string Lname,int BY,int BM,int BD,int CM,int CD,int CY)
		{
			firstname=Fname;
			lastname=Lname;
			byear=BY;
			bmonth=BM;
			bday=BD;
			curmon=CM;
			curday=CD;
			curyear=CY;
		}
		void setfirstname(string f)
		{
			firstname=f;
		}
		void setlastname(string l)
		{ lastname=l;
		}
		void setbyear(int by){
			byear=by;
		}
		void setbmonth(int bm)
		{
			bmonth=bm;
		}
		void setbday(int bd)
		{
			bday=bd;
		}
		void setcurmon(int cm)
		{
			curmon=cm;
		}
		void setcurday(int cd)
		{
			curday=cd;
		}
		void setcuryear(int cy)
		{
			curyear=cy;
		}
		string getfirstname()
		{
			return firstname;
		}
		string getlastname()
		{
			return lastname;
		}
		int getbyear()
		{
			return byear;
		}
		int getbmonth()
		{
			return bmonth;
		}
		int getbday()
		{
			return bday;
		}
		int getcurmon()
		{
			return curmon;
		}
	 int getcurday()
	 {
	 	return curday;
	 }
		int getcuryear()
		{
			return curyear;
		}
		int getage()
		{
		int age=getcuryear()-getbyear() ;
			return age;
		}
		  int getmaxheartrate()
		  {
		  	int maxhr=220-getage();
		  	return maxhr;
		  }
	float gettargetheartrate()
	{
		float THR;
		cout <<" \nyour max target heart rate is "<<getmaxheartrate()*0.5<<" to "<<getmaxheartrate()*0.85;
	}
};
int main()
{
	string a,b;
	int c,d,e,f,g,h;
	heartrate r(a,b,c,d,e,f,g,h);
	heartrate r1(a,b,c,d,e,f,g,h)        ;
	cout<<"enter first name:\n";
	cin>>a;   
	r1.setfirstname(a);
	fflush(stdin);                    
	cout<<"enter last name:\n";
	cin>>b;
	r1.setlastname(b);
	fflush(stdin);  
	cout<<"enter birth year(in number):\n";
	cin>>c;
	r1.setbyear(c);
	fflush(stdin);  
	cout<<"enter birth month(in number):\n";
	cin>>d;
	r1.setbmonth(d);
	fflush(stdin);  
	cout<<"enter birth day(in number):\n";
	cin>>e;
	r1.setbday(e);
	fflush(stdin);  
	cout<<"enter current year(in number):\n";
	cin>>f;
	r1.setcuryear(f);
	fflush(stdin);  
	cout<<"enter current month(in number):\n";
	cin>>g;
	r1.setcurmon(g);
	fflush(stdin);  
	cout<<"enter current day(in number):\n";
	cin>>h;
	r1.setcurday(h);
	cout<"\n\n\n";
	cout<<r1.getfirstname()<<r1.getlastname();
	cout<<"\nyour curent age:"<<r1.getage();
	fflush(stdin);  
	cout<<"\nmaximum heart rate:"<<r1.getmaxheartrate();
	r1.gettargetheartrate();
	return 0;
}

