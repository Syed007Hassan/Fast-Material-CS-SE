#include<iostream>
using namespace std;
class poly{
	int coff;
	int exp;
	char var;
	public:
		void setcoff(int coff)
		{
			this->coff=coff;
		}
		void setexp(int exp)
		{
			this->exp=exp;
		}
		void setvar(char var)
		{
			this->var=var;
		}
		int getcoff()
		{
			return coff;
		}
		int getexp()
		{
			return exp;
		}
		char getvar()
		{
			return var;
		}
		poly operator +(poly p)
		{poly a;
		if(var==p.getvar()&&exp==p.getexp())
                {
                	a.coff=coff+p.coff;
                	a.setvar(var);
                	a.setexp(exp);
                	
//                	a3.x = x + a.x;
//			a3.y = y + a.y;
//			return a3;
return a;
}

		else
		{
			cout<<"invalid eq";
		}	}
void getvalue()
	{int a,b;
	char c;
	
		poly p1;
	cout<<"\nenter cofficient:";
	cin>>a;p1.setcoff(a);
	cout<<"\nenter variable:";
	cin>>c;p1.setvar(c);
	cout<<"\nenter exponent:";
	cin>>b;p1.setexp(b);
//	cout<<"\npolynomial 2";
//	cout<<"\nenter cofficient:";
//	cin>>a;p2.setcoff(a);
//	cout<<"\nenter variable:";
//	cin>>c;p2.setvar(c);
//	cout<<"\nenter exponent:";
//	cin>>b;p2.setexp(b);
       
	}
			
};
int main()
{
	poly p1,p2,p3;
	int a,b,x;
	char c;
	cout<<"which function do you want to perform in polynomial equation";
	cout<<"\n1.addition";
	cout<<"\n2.subtraction";
	cout<<"\n3.multiplication";
	cout<<"\n4.assingment";
	cin>>x;
	switch(x)
	{
		case 1:
			{cout<<"\npolynomial 1";
			p1.getvalue();
			p2.getvalue();
				p3=p1+p2;
				cout<<"\nafter addition:"<<p3.getcoff()<<p3.getvar()<<"^"<<p3.getexp();
				break;
			}
	}
}

