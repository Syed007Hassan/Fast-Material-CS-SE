case 6:  //solving equation
{
int n,m;
cout<<"Enter the number of terms in first equation: ";
cin>>n;
cout<<"Enter the number of terms in second equation: ";
cin>>m;
polynomial poly1[n],poly2[m];   //for equation1 and equation 2
int i,j,k;
cout<<endl<<endl<<"first equation: "<<endl;
for(i=0; i<n; i++)    //forming equation 1
{
cout<<"coefficeint:  ";
            cin>>cof;
            fflush(stdin);
            poly1[i].set_cof(cof);
            cout<<"variable : ";
            cin>>let;
            fflush(stdin);
            poly1[i].set_letter(let);
           cout<<"exponent : ";
            cin>>exp;
            fflush(stdin);
            poly1[i].set_exponent(exp);
}


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
