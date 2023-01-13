#include<iostream>
using namespace std;
class employee{
	int ID ;
	string name ;
	public:
		void setid(int I  ) 
		{
			 ID =I ;
		}
		void setname(string name )
		{
			this->name =name ;
		}
		string getname()
		{
			return name ;
		}
		int getID() const
		{
			return ID ;
		}
		
};
int main()
{
	int d ,i;
	string n ;
 	employee e[3];
 	for(i=0;i<3;i++)
 	{
 		cout<<"\nname:"; 
		 cin>> n;
		 fflush(stdin);
		 cout<<"\nid:";
		 cin>>d;
		 e[i].setname(n);
		 e[i].setid(d);
		 	 }
 
   
	  for(i=0;i<3;i++)
	  {
	  	  cout<<"\n \t\temployee information";
	  cout<<"\nemployee "<<i ;
	  cout<<"\nID:"<<e[i].getID();
	  cout<<"\nname:"<<e[i].getname();
	  }
	  
}
	  
	   













