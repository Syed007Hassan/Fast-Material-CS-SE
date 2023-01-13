/* Bookshop.cppp*/
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
class book
{

 char author[20]; 
 char title[20];
 char publisher[20];
 double price;
 int stock;
   public:
     book();    
   void insertdata();
   void display();
   int search(char[],char[]);
   void nocopies(int);     
};
  book::book()
  {
    char *author=new char[50];
    char * title=new char[50];
    char *publisher=new char[50];
    price=0;
    stock=0;
   }
void book::insertdata()
         {
  cout<<"\n Enter the name of Book:";
  cin>>title;
  cout<<"\n Enter The Name Of Author:";
  cin>>author;
  cout<<"\n Enter The name of Publisher:";
  cin>>publisher;
  cout<<"\n Enter the Price of book:";
  cin>>price;
  cout<<"\n Enter Stock of book:";
  cin>>stock;
 }


  void book::display()
 {
 cout<<"\n "<<title<<"\t\t "<<author<<"\t\t  "<<publisher<<" \t\t\t "<<price<<"\t "<<stock;
        }
  int book::search(char t[],char a[])
  {
      if(strcmp(title,t)&&(strcmp(author,a)))
 {
 return 0;
 }
 else
 {
 return 1;
 }
  }

 void book::nocopies(int num)
{
if(stock>=num)
{
cout<<"\n Title is avilable";
cout<<"\n Cost of"<<num<<"Books is Rs."<<(price*num);
}
else
{
cout<<"\n Required copies not in stock";
}
}
int main()
{
 int ch,n,i,flag=0,copies,key=0;
          book b[100];
          char bname[50];
          char key_title[50],key_author[50];
   do
    {
 cout<<"\n************Book Store*******************";
 cout<<"\n 1.Insert Details of book \n 2.Display \n 3.search \n 4.exit";
 cout<<"\n Enter Your Choice:";
 cin>>ch;
 switch(ch)
  {
      case 1:
                    cout<<"\n How many books data u want to enter";
                    cin>>n;
                    for(i=0;i<n;i++)
                      {
                       b[i].insertdata();
   }
                     break;
     case 2:
                       cout<<"\n"<<"TITLE"<<"\t \t "<<"AUTHOR"<<"\t\t"<<"PUBLISHER"<<"\t\t"<<"PRICE"<<"\t "<<"STOCK";
                        for(i=0;i<n;i++)
    {
                        cout<<"\n";
   
         b[i].display();   
     }
   
                        break;
                    
   case 3:
                          cout<<"\n Enter title of required book";
                           cin>>key_title;
                           cout<<"\n Enter author of required book";
                            cin>>key_author;
                             
                            for(i=0;i<n;i++)
                          {
                              if(b[i].search(key_title,key_author))
                               {
                                  flag=1;
 cout<<"\n"<<"TITLE"<<"\t \t "<<"AUTHOR"<<"\t\t"<<"PUBLISHER"<<"\t\t"<<"PRICE"<<"\t "<<"STOCK";
                                  b[i].display();                        
    //break;
    key=i;
            }
    }
   if(flag==1)                          
    cout<<"\n Book is available";
   else
 {
     cout<<"\n book is Not available";
        break;
 }        
              if(flag==1)
                      {
                      cout<<"\n Please enter the required number of copies of the book";
                       cin>>copies;
                      b[key].nocopies(copies);
                     }
                   
                     break;
                case 4: exit(EXIT_SUCCESS);
   break;
  default :
                    cout<<"\n Wrong Choice";
                       break;
 }   
   }while(ch!=5);
 return 0;
} 
