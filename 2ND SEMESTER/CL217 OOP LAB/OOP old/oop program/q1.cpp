#include<iostream>
using namespace std;
class marks{
	protected:
		double per;
	
	public:
		virtual getpercentage()=0;
};
class A:public marks{
	double marks1,marks2,marks3;
	public:
		A(double m1,double m2,double m3)
		{
			marks1=m1;
			marks2=m2;
			marks3=m3;
		}
		getpercentage()
		{
			double per;
			per=((marks1+marks2+marks3)/300)*100;
			cout<<"\npercentage of CLASS A :"<<per;
		}
};
class B:public marks{
	double marks1,marks2,marks3,marks4;
	public:
		B(double m1,double m2,double m3,double m4)
		{
			marks1=m1;
			marks2=m2;
			marks3=m3;
			marks4=m4;
		}
		getpercentage()
		{
			double per;
			per=((marks1+marks2+marks3+marks4)/400)*100;
			cout<<"\npercentage of CLASS B :"<<per;
		}
};
int main()
{
	A a(99,66,80.5);
	a.getpercentage();
	B b(77.5,65,80,70);
	b.getpercentage();
}

