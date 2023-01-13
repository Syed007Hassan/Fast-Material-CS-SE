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
//	void setcoffwithsign(int coffwithsign)
//	{
//	this->coffwithsign=coffwithsign;	
//	}
//	int getcoffwithsign()
//	{
//		return coffwithsign;
//	}
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
	{
	cout<<"invalid eq";
	}
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
        { 
	 	exp=exp+p.exp;
                coff=coff*p.coff;
                setvar(var);
	}
	else
        {
	coff=coff*p.coff;
        p.setvar(var);
        p.setexp(exp);
	}
}
void display()
{
        cout<<" "<<coff;
        cout<<" "<<var;
        if(exp!=1)
        {
        	cout<<"^"<<exp;
        }
}

  
};
int main()
{
	poly p1,p2,p3;
	int a,b,x;
	char c;
	int s;
	cout<<"which function do you want to perform  ";
	cout<<"\n1.polynomial addition";
	cout<<"\n2.polynomial subtraction";
	cout<<"\n3.polynomial multiplication";
	cout<<"\n4.polynomial assingment";
	cout<<"\n5.polynomial addition assignment";
	cout<<"\n6.polynomial subtraction assignment";
	cout<<"\n7.polynomial multiplication assignment";
	cout<<"\n8.solve polynomial eqution";
	cout<<"\n\t\tyourchoice:";
	cin>>x;
	switch(x)
	{
	case 1:
	{
	        cout<<"\n\t addition\npolynomial 1";
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
		cout<<"\n\t multiplication\npolynomial 1";
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
	{
	        cout<<"\n\t  assignment\npolynomial 1";
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
		cout<<"\n\t addition assignment\npolynomial 1";
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
		if(p1.getexp()==p2.getexp()&&p1.getvar()==p2.getvar())
		{
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
		cout<<"\n\t multiplicatin assignment\npolynomial 1";
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
        case 8:
	{
	system("cls");
	cout<<"\n\tsolving equation:\n";
        int n,m;
        cout<<"Enter the number of terms in first equation: ";
        cin>>n;
        cout<<"Enter the number of terms in second equation: ";
        cin>>m;
        poly poly1[n],poly2[m];   
        int i,j,k;
        int cof,exp;
        char let;
        cout<<endl<<endl<<"first equation: "<<endl;
        for(i=0; i<n; i++)    
        {
             cout<<"coefficeint:  ";
            cin>>cof;
            fflush(stdin);
            poly1[i].setcoff(cof) ;
            cout<<"variable : ";
            cin>>let;
            fflush(stdin);
            poly1[i].setvar(let);
           cout<<"exponent : ";
            cin>>exp;
            fflush(stdin);
            poly1[i].setexp(exp);
        }


        cout<<endl<<endl<<"Second equation: "<<endl;
        for(i=0; i<m; i++)     //forming equation2
        {
            cout<<"coefficeint:  ";
            cin>>cof;
            fflush(stdin);
            poly2[i].setcoff(cof);
            cout<<"variable : ";
            cin>>let;
            fflush(stdin);
            poly2[i].setvar(let);
            cout<<"exponent : ";
            cin>>exp;
            fflush(stdin);
            poly2[i].setexp(exp);
        }
        
	cout<<"first equation is"<<endl;
        for(i=0; i<n; i++)   
        {
        if(i!=(n-1))
        {
        poly1[i].display();
        if(poly1[i+1].getcoff()>0)
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
       for(i=0; i<m; i++)    
       {
       if(i!=(m-1))
       {
       poly2[i].display();
       if(poly2[i+1].getcoff()>0)
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
     poly pol3[n+m], temporary[m];   
     int temp=0; 
     for(i=0; i<n; i++)
      {
        for(j=0; j<m; j++)
         {
          if(poly1[i].getexp()==poly2[j].getexp() && poly1[i].getvar()==poly2[j].getvar())
                {
                           pol3[i]=poly1[i]+poly2[j];
                           temporary[i]=poly2[j];
                           break;
                }
          else if(poly1[i].getexp()!=poly2[j].getexp() && poly1[i].getvar()!=poly2[j].getvar())
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
        for(i=0; i<m; i++)
        {
        for(j=0; j<m; j++)
        {
        if(temporary[i].getcoff()!=poly2[j].getcoff() && temporary[i].getexp()!=poly2[j].getexp() && temporary[i].getvar()!=poly2[j].getvar())
        {
        temporary[i]=poly2[j];
        break;
        }
        }
        } 
        for(i=0; i<m; i++)
        {
         for(j=0; j<(m+n); j++)
         {
        if(pol3[j].getcoff()==0 && pol3[j].getexp()==0 && pol3[j].getvar()==' ')                                                                 
        {
        pol3[j]=temporary[i];
        break;
        }
        else if(pol3[j].getcoff()==temporary[i].getcoff() && pol3[j].getexp()==temporary[i].getexp()&& pol3[j].getvar()==temporary[i].getvar())
        {
        break;
        }
        }
        }
        cout<<"The answer is: "<<endl;
        for(i=0; i<(n+m); i++)
        {
        if(pol3[i].getcoff()==0 && pol3[i].getexp()==0 && pol3[i].getvar()==' ')
        {
        break;
        }
        else
        {
        pol3[i].display();
        }

        if(pol3[i+1].getcoff()>0)
        {
         cout<<" +";
        } 
        else if(pol3[i+1].getcoff()<0)
        {
        cout<<"-";
        }
        }
break;
system("pause");
}
}
}
