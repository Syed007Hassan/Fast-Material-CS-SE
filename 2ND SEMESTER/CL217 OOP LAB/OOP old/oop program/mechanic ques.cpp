#include<iostream>
using namespace std;
class mechanic{
	string name;
	
	double salary;
	public:
		string work;
		
	double amount=0;
		void setname(string n)
		{
			name=n;
		}
		string getname()
		{
			return name;
		}
		void setwork(string w)
		{
			work=w;
		}
		string getwork()
		{
			return work;
		}
		void setsalary(double s)
		{
			salary=s;
		}
		double getsalary()
		{
			return salary;
		}
			double getamount()
				{
					return amount;
				}
		};
		class customer:public mechanic
		{
			public:
				void generatebill()
				{
					int c;
//					string s;
					cout<<"\n1.regularcustomer";
					cout<<"\n2.newcustomer";
					cin>>c;
					if(c==1)
					{
					if(work=="repair")
					{
						amount=5000; 
					}
					else if(work=="paint")
					{
						amount=10000;  
					}
					}
					else if(c==2)
					{
							if(work=="repair")
					{
						amount=3500; 
					}
					else if(work=="paint")
					{
						amount=7500; 
					}
						
					}
					
				}
			
		};
		int main()
		{ 
		
			mechanic m;
			customer c;
			string mname,mwork;
			cout<<"\nenter name:";
			cin>>mname;
			m.setname(mname);
			fflush(stdin);
			cout<<"\nenter work(repair or paint):";
			cin>>mwork;
			m.setwork(mwork);
			c.generatebill();
			cout<<"\ncustomer bill:";
			cout<<"\nname:"<<m.getname();
			cout<<"\nwork:"<<m.getwork();
			cout<<"\namount to pay:"<<m.getamount();
		}
