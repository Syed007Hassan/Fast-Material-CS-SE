#include<iostream>
using namespace std;
class marks
{
int rollno;
string name;
float mark1;
float mark2;
float mark3;
double total=300;
double per=0;
public:
marks()
{
    rollno++;
}
int getrollno()
{
	return rollno;
}
void setname(string n)
{
	name=n;
}
string getname()
{
	return name;
}
double percal(float m1,float m2,float m3)
{

per=((m1+m2+m2)/total)*100;
}
};
class physics:public marks
{
    public:
    void displayphymarks(float m1)
    {
        cout<<"\nphysics marks:"<<m1;
    }

};
class maths:public marks
{
  public:
    void displaymathmarks(float m2)
    {
        cout<<"\nmath marks:"<<m2;
    }
};
class chemistry:public marks
{
      public:
    void displaychemmarks(float m3)
    {
        cout<<"\nchemistry marks:"<<m3;
    }

};
int main()
{
    float phy,chem,math;
    string name;
    cout<<"\nenter name:";
    cin>>name;
    
    cout<<"\nenter marks:";
    cout<<"\nphysics:";
    cin>>phy;
    cout<<"\nmaths:";
    cin>>math;
    cout<<"\nchemistry:";
    cin>>chem;
     marks m;
     m.setname(name);
     chemistry c;
     physics p;
     maths ma;
     cout<<"\nname:"<<m.getname();
     cout<<"\nrollno:"<<m.getrollno();
     ma.displaymathmarks(math);
     p.displayphymarks(phy);
      c.displaychemmarks(chem);
cout<<"\npercentage:"<<m.percal(math,phy,chem)<<"%";
    return 0;
}
