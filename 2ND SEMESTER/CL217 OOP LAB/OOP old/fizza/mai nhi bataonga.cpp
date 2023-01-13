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
	cout<<"\nsolving equation:";
int n,m;
cout<<"Enter the number of terms in first equation: ";
cin>>n;
poly eq1[n];   //for equation1 and equation 2
int i,j,k;
cout<<endl<<endl<<"first equation: "<<endl;
for(i=0; i<n; i++)    //forming equation 1
{
cout<<"coefficeint with sign:  ";
            cin>>a;
            fflush(stdin);
            eq1[i].  ;
            cout<<"variable : ";
            cin>>let;
            fflush(stdin);
            poly1[i].set_letter(let);
           cout<<"exponent : ";
            cin>>exp;
            fflush(stdin);
            poly1[i].set_exponent(exp);
}

cout<<"Enter the number of terms in second equation: ";
cin>>m;
poly eq2[m];
cout<<endl<<endl<<"Second equation: "<<endl;
for(i=0; i<m; i++)     //forming equation2
{
cout<<"coefficeint:  ";
            cin>>cof;
            fflush(stdin);
            poly2[i].set_cof(cof);
            cout<<"variable : ";
            cin>>let;
            fflush(stdin);
            poly2[i].set_letter(let);
           cout<<"exponent : ";
            cin>>exp;
            fflush(stdin);
            poly2[i].set_exponent(exp);

}


cout<<"first equation is"<<endl;
for(i=0; i<n; i++)   //displaying equation 1
{
if(i!=(n-1))
{
poly1[i].display();
if(poly1[i+1].get_cof()>0)
{
cout<<"+";
}

   }
   else
   {
    poly1[i].display();
}
}


cout<<endl;
cout<<"Second eqquation is"<<endl;
for(i=0; i<m; i++)    //displaying equation 2
{

if(i!=(m-1))
{
poly2[i].display();
if(poly2[i+1].get_cof()>0)
{
cout<<"+";
}

   }
   else
   {
    poly2[i].display();
}
}
cout<<endl;
polynomial pol3[n+m], temporary[m];   //pol3 is for storing answer and the temporary is for storing the terms of equation 2 that has been added to any term of equation 1
int temp=0;    //this variable is for checking that if the term of equation 1 has a term in equation 2 with same variable and exponent
for(i=0; i<n; i++)
{
for(j=0; j<m; j++)
{
if(poly1[i].get_exp()==poly2[j].get_exp() && poly1[i].get_let()==poly2[j].get_let())
{
                           pol3[i]=poly1[i]+poly2[j];
                           temporary[i]=poly2[j];
                           break;
}
else if(poly1[i].get_exp()!=poly2[j].get_exp() && poly1[i].get_let()!=poly2[j].get_let())
{
temp=1;
}
}
if(temp==1)
{
pol3[i]=poly1[i];
}

}
cout<<endl<<endl;
//in this loop we will compare the terms in equation 2 and temporary and if the terms are same they will be replace with the terms of eq 2 that were different
//in short temporary is now storing values that did not have same exp and var as any term in equation 1
for(i=0; i<m; i++)
{
for(j=0; j<m; j++)
{

if(temporary[i].get_cof()!=poly2[j].get_cof() && temporary[i].get_exp()!=poly2[j].get_exp() && temporary[i].get_let()!=poly2[j].get_let())
{
temporary[i]=poly2[j];
break;
}
   }
}

//now we are storing the terms(in tempporary) in final answer equation
for(i=0; i<m; i++)
{
for(j=0; j<(m+n); j++)
{
if(pol3[j].get_cof()==0 && pol3[j].get_exp()==0 && pol3[j].get_let()==' ') // as the contructor will set everything to zero if there is
                                                                           // an empty element of array because we dont know the size of final eq array
{
pol3[j]=temporary[i];
break;
}
else if(pol3[j].get_cof()==temporary[i].get_cof() && pol3[j].get_exp()==temporary[i].get_exp() && pol3[j].get_let()==temporary[i].get_let())
{
break;
}
}
}
cout<<"The answer is: "<<endl;
for(i=0; i<(n+m); i++)
{
if(pol3[i].get_cof()==0 && pol3[i].get_exp()==0 && pol3[i].get_let()==' ')
{
break;
    }
    else
    {
    pol3[i].display();
}

if(pol3[i+1].get_cof()>0)
{
  cout<<" +";
   }
   else if(pol3[i+1].get_cof()<0)
   {
    cout<<"-";
}
}

}  
        break;
	}
		   }}

