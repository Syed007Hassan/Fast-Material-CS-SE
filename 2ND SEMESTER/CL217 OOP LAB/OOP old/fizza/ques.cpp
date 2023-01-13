#include<iostream>
using namespace std;
class poly{
	int coff,exp;
	char var;
	public:
	poly(){}
	poly(int coff,int exp,char var){
	this->coff=coff;
	this->exp=exp;
	this->var=var;}
	void setcoff(int coff)
	{this->coff=coff;}
	void setexp(int exp)
	{this->exp=exp;}
	void setvar(char var)
	{this->var=var;}
	int getcoff()
	{return coff;}
	int getexp()
	{return exp;}
	char getvar()
	{return var;}
poly operator +(poly p)
{
	poly a;
        if(var==p.getvar()&&exp==p.getexp())
        {
       	a.coff=coff+p.coff;
        a.setvar(var);
        a.setexp(exp);
        return a;
        }
       	else
	{cout<<"invalid eq";}
}
poly operator -(poly p)
{
        poly a;
        if(var==p.getvar()&&exp==p.getexp())
        {
       	a.coff=coff-p.coff;
        a.setvar(var);
        a.setexp(exp);
        return a;
        }
       	else
	{cout<<"invalid eq";}
}

poly operator *(poly p)
{  
   poly a;
   if(coff==p.getcoff()&&var==p.getvar())
   { 
   a.exp=exp+p.exp;
   a.coff=coff*p.coff;
   a.setvar(var);
   }	
   else
    {
   a.coff=coff*p.coff;
   a.setvar(var);
   a.setexp(exp);
   return a;
}
}
poly operator =(poly p)
{
	poly a;
	a.coff=coff=p.coff;
	a.exp=exp=p.exp;
	a.var= var=p.var;
	
}
void operator +=( poly p)
{
	if(var==p.getvar()&&exp==p.getexp())
	{
		coff=coff+p.coff;
		p.setvar(var);
   p.setexp(exp);
		
	}
}
void operator -=( poly p)
{
	if(var==p.getvar()&&exp==p.getexp())
	{
		coff=coff-p.coff;
		p.setvar(var);
   p.setexp(exp);
		
	}
}
void operator *=( poly p)
{
	 if(coff==p.getcoff()&&var==p.getvar())
   { 	exp=exp+p.exp;
   coff=coff*p.coff;
   setvar(var);
		}
	else {
	coff=coff*p.coff;
        p.setvar(var);
        p.setexp(exp);
	}
}

  
};
int main()
{
	poly p1,p2,p3;
	int a,b,x;
	char c;
	string s;
	cout<<"which function do you want to perform  ";
	cout<<"\n1.polynomial addition";
	cout<<"\n2.polynomial subtraction";
	cout<<"\n3.polynomial multiplication";
	cout<<"\n4.polynomial assingment";
	cout<<"\n5.polynomial addition assignment";
	cout<<"\n6.polynomial subtraction assignment";
	cout<<"\n7.polynomial multiplication assignment";
	cout<<"\n8.solve polynomial eq";
	cin>>x;
	switch(x){
	
		case 1:
	{cout<<"\n\t addition\npolynomial 1";
	cout<<"\nenter cofficient:";
		cin>>a;p1.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p1.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p1.setexp(b);
		cout<<"\npolynomial 2";
		cout<<"\nenter cofficient:";
		cin>>a;p2.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p2.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p2.setexp(b);
		p3=p1+p2;
		if(p1.getexp()==p2.getexp()&&p1.getvar()==p2.getvar()){
		cout<<"\nafter addition:"<<p3.getcoff()<<p3.getvar()<<"^"<<p3.getexp();}
		else
		break;	system("pause");
	}
		case 2:
	{cout<<"\n\t subtraction\npolynomial 1";
	cout<<"\nenter cofficient:";
		cin>>a;p1.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p1.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p1.setexp(b);
		cout<<"\npolynomial 2";
		cout<<"\nenter cofficient:";
		cin>>a;p2.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p2.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p2.setexp(b);
		p3=p1-p2;
		if(p1.getexp()==p2.getexp()&&p1.getvar()==p2.getvar()){
		cout<<"\nafter subtraction:"<<p3.getcoff()<<p3.getvar()<<"^"<<p3.getexp();
		}
		else
		break;
		system("pause");
		}
		case 3:
		{
		cout<<"\n\t subtraction\npolynomial 1";
	        cout<<"\nenter cofficient:";
		cin>>a;p1.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p1.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p1.setexp(b);
		cout<<"\npolynomial 2";
		cout<<"\nenter cofficient:";
		cin>>a;p2.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p2.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p2.setexp(b);
		p3=p1*p2;
		cout<<"\nafter multiplication:"<<p3.getcoff()<<p3.getvar()<<"^"<<p3.getexp();
				break;
				system("pause");
			}
			case 4:
			{cout<<"\n\t assignment\npolynomial 1";
	cout<<"\nenter cofficient:";
		cin>>a;p1.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p1.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p1.setexp(b);
		cout<<"\npolynomial 2";
		cout<<"\nenter cofficient:";
		cin>>a;p2.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p2.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p2.setexp(b);
		p1=p2;
//		swap(p1,p2);
		cout<<"\neq 1:"<<p1.getcoff()<<p1.getvar()<<p1.getexp();
		cout<<"\neq 2:"<<p2.getcoff()<<p2.getvar()<<p2.getexp();
			break;
			system("pause");
			
				}
			case 5:
			{
		cout<<"\n\t assignment\npolynomial 1";
	         cout<<"\nenter cofficient:";
		cin>>a;p1.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p1.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p1.setexp(b);
		cout<<"\npolynomial 2";
		cout<<"\nenter cofficient:";
		cin>>a;p2.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p2.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p2.setexp(b);
		p1+=p2;
		if(p1.getexp()==p2.getexp()&&p1.getvar()==p2.getvar()){
		cout<<"\nafter additon assignment:"<<p1.getcoff()<<p1.getvar()<<p1.getexp();
			}
			break;
			system("pause");
	}
	case 6:
		{
		cout<<"\n\t assignment\npolynomial 1";
	         cout<<"\nenter cofficient:";
		cin>>a;p1.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p1.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p1.setexp(b);
		cout<<"\npolynomial 2";
		cout<<"\nenter cofficient:";
		cin>>a;p2.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p2.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p2.setexp(b);
			p1-=p2;
		if(p1.getexp()==p2.getexp()&&p1.getvar()==p2.getvar()){
		cout<<"\nafter subtraction:"<<p1.getcoff()<<p1.getvar()<<"^"<<p1.getexp();
		}
		break;
		system("pause");
		}
	case 7:
		{
		cout<<"\n\t assignment\npolynomial 1";
	         cout<<"\nenter cofficient:";
		cin>>a;p1.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p1.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p1.setexp(b);
		cout<<"\npolynomial 2";
		cout<<"\nenter cofficient:";
		cin>>a;p2.setcoff(a);
		cout<<"\nenter variable:";
		cin>>c;p2.setvar(c);
		cout<<"\nenter exponent:";
		cin>>b;p2.setexp(b);
		p1*=p2;
		cout<<"\nafter multiplication:"<<p1.getcoff()<<p1.getvar()<<"^"<<p1.getexp();
				break;
				system("pause");
                   }
        case 8:{
	system("cls");        	
        	 int n,i;
        	 poly eq1[n] ;
        	 poly eq2[n] ;
	cout<<"\nenter no of term in eq 1";
        cout<<"enter equation (coff,var,exp,sign respectfully)";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nno of term :"<<i+1;
		cout<<"\ncofficient:";
		cin>>a;
		eq1[i].setcoff(a);
		cout<<"\ncvaraible:";
		cin>>c;
		eq1[i].setvar(c);
		cout<<"\nexpression:";
		cin>>b;
		eq1[i].setexp(b);
		cout<<"\nsign:";
		cin>>s[i];
		if(i<n-1){
		cout<<"\nsign:";
		cin>>s[i];}
		
	}
	system("cls");
	cout<<"\nenter no of term in equation2";
        cout<<"enter equation (coff,var,exp,sign respectfully)";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nno of term :"<<i+1;
		cout<<"\ncofficient:";
		cin>>a;
		eq2[i].setcoff(a);
		cout<<"\nvaraible:";
		cin>>c;
		eq2[i].setvar(c);
		cout<<"\nexpression:";
		cin>>b;
		eq2[i].setexp(b);
		if(i<n-1){
		cout<<"\nsign:";
		cin>>s[i];}
		
	}
		system("cls");
		cout<<"\nequation 1";
	for(i=0;i<n;i++)
	{
		cout<<eq1[i].getcoff()<<eq1[i].getvar()<<eq1[i].getexp()<<s[i];
}
cout<<"\nequation 2";
	for(i=0;i<n;i++){
	
		cout<<eq2[i].getcoff()<<eq2[i].getvar()<<eq2[i].getexp()<<s[i];
	}
        break;
	}
		   }}

