#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string.h>
int i,l;
int p,q,r,s;
int k=0;
 using namespace std;
class Coffeeshop
{
	private:
	string	name = "\n\t\t\t***Das deutsche Café(In German)***\n\n";
	string	menu[3] = {"Tea","Juice","Coffee"};
	string 	orders[10];
	public:
		Coffeeshop ()
 {
 	cout<<"\t\t\t\tWELCOME TO COFFEE SHOP!!\n"<<name<<"\t\t\t\tBelow is our menu\n";
 	for(i=0;i<3;i++)
 	{
 		cout<<"\t--> "<<menu[i]<<endl;
	 }
	 cout<<"\tEnter your choice of order: ";
 	string n;
 	cin>>n;
 	addorder(n);
 	fulfillorder();
 	listorder();
	dueamount();
 	cheapestitem();
 	drinksonly();
 	foodonly();
 }
 drinksonly()
 {
 	cout<<"\n\n Currently we have only 3 drinks item\n";
 	for(i=0;i<3;i++)
 	{
 		cout<<endl<<menu[i];
	 }
 }
 foodonly()
 {
 	cout<<endl<<"\n\tToday is Sunday and we keep drinks only for this day\n*";
 	cout<<endl<<"\n\tCome Tomorrow for the food items. Thanks for coming\n";
 }
 cheapestitem()
 {
 	int c1=50,c3=30,c2=100;
 	if(c1<c2 && c1<c3)
 	cout<<"\n\n\t\t\t Cheapest item on menu is tea ";
 	else if(c2<c1 && c2<c3)
 	cout<<"\n\n\t\t\t Cheapest item on menu is juice ";
 	else
 	cout<<"\n\n\t\t\t Cheapest item on menu is coffee";
 	
 }
 dueamount()
 {
 	cout<<"\n \t ONE cup of Tea = 50 \n \t ONE Glass of Juice is = 100 \n \t ONE cup of Gold Coffee is = 30\n";
 	string u = "Tea";
 	string m = "Juice";
 	string e = "Coffee";
 	for(int i=0;i<10;i++)
 	{
 		if(u==orders[i])
 		{
 			p++;
 			
		 }
		 else if(orders[i]==m)
		 {
		 	q++;
		 }
		 else if(e==orders[i])
		 {
		 	r++;
		 }
		 
	 }
 	
 	float bill = (p*50) + (q*100) + (r*30);
 	cout<<"\n\t You need to pay amout of: "<<bill;
 	
 }
 listorder()
 {
 	cout<<"\n\n\t List of orders taken\n";
 	for(i=0;i<10;i++)
 	cout<<orders[i]<<endl;
 	
 	
 }
 		fulfillorder()
 		{
 			string bb;
 			if(orders[i]!=bb)
 			for(int i=0;i<10;i++)
 			{
			 
 			cout<<"\n\t the "<<orders[i]<<" is ready\n";
 			if(orders[i+1]==bb)
 			break;
 		}
 			else
 			cout<<"\n\t All orders have been fulfilled";
		 }
 
		void addorder(string a)
 {
 	
 	for(i=0;i<3;i++)
 	{
 	
 			if(a==menu[k] || a==menu[k+1] || a==menu[k+2])
 	{
 		orders[i] = a;
 		cout << "\n\n\tORDER noted";
 		cout<<endl<<"\t-"<<orders[i];
 		yes(a);
 		cout<<"\n WE break";
 		break;
	 }
	 else 
	 {
	 
	 cout << "SORRY!! This item is currently unavailiable";
	 break;
}
	 }
	 
 
 }
 int yes(string x)
 {
 	cout<<"\n\t Want to order again enter 1 else press 2: ";
 		int ch;
 		cin>>ch;
 		if(ch==1)
 		{
 			cout<<"\n\tEnter your choice of order: ";
 			string j;
 			cin>>j;
 			if(j==menu[k] || j==menu[k+1] || j==menu[k+2])
 			{
		orders[i+1]=j;	 
		i++;
 			yes(j);
 		}
		 }
		 else
		 {
		 cout<<"\n you pressed 2";
		 return 0;
 }
 }
 
	
 };
 
 
 main()
 {
 	Coffeeshop b1;
 	
		
 }
