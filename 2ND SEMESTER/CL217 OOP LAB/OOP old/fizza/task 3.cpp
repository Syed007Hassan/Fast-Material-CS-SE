#include<iostream>
using namespace std;
class acute{
	int length;
	int breadth;
	public:
	friend	void areaoftriangle(acute a);
	void setlength(int l)
	{
		length=l;
	}
	int getlength()
	{
		return length;
	}
	void setbreadth(int b)
	{
		breadth=b;
	}
	int getbreadth()
	{
		return breadth;
	}
	
};
class obtuse:public acute
{

	public:
		friend	void areaoftriangle(obtuse);
};
void areaoftriangle(acute a)
{ 
double area;
	area=a.getlength()*a.getbreadth();
        cout<<"area of ACUTE triangle:"<<area;
}
void areaoftriangle(obtuse a)
{ 
double area;
	area=a.getlength()*a.getbreadth();
        cout<<"area of OBTUSE 1triangle:"<<area;
}
int main()
{
	int l,b;
	double deg;
	cout<<"\nenter degree:";
	cin>>deg;
	if(deg>=90)
	{ acute a;
	cout<<"\nenter length and breadth:";
	cin>>l>>b;
	a.setlength(l);
	a.setbreadth(b);
	areaoftriangle(a);
	}
	else{
		obtuse a;
	cout<<"\nenter length and breadth:";
	cin>>l>>b;
	a.setlength(l);
	a.setbreadth(b);
	areaoftriangle(a);
		
	}
}
