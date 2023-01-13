#include<iostream>
using namespace std;
int p,q,r,s;
int k=0;
class coffeeshop{
	private:
		string name = "Central Perk";
		string menu[10]={"Coffee","Tea","Scone","Donut"};
		string order[10];
	public:
	   coffeeshop(){
	   	cout<<"\t\tWelcome to"<<name<<endl;
	   	cout<<"\t\tMenu:"<<endl;
	   	for(int i=0;i<4;i++)
 	{
 		cout<<"\t\t"<<menu[i]<<endl;
	 }
	 cheapestitem();
	foodonly();
	drinkonly();
	
	cout<<"\t\tSelect Item:";
 	string item;
 	cin>>item;
 	addorder(item);
	fulfillorder();
 	listorder();
	dueamount();

	   }
	   cheapestitem(){
	cout<<"\t\tThe cheapest item we have is water which is free"<<endl;
	
}
drinkonly(){
	cout<<"\t\tDRINKS:Coffee,Tea"<<endl;
}
foodonly(){
	cout<<"\t\tFood:Scone,Donut"<<endl;
}
void addorder(string a)
 {
 	
 	for(int i=0;i<4;i++)
 	{
 	
 	if(a==menu[k] || a==menu[k+1] || a==menu[k+2] || a==menu[k+3])
 	{
 		order[i] = a;
 		cout <<endl<<order[i];
 		again(a);
 		break;
	 }
	 else 
	 {
	 cout << "NOT AVAILABLE";
	 break;
}
	 }
	 
 
 }
 int again(string x)
 { int i,j;	
 	cout<<endl<<"press (y/n)";
 		char select;
 		cin>>select;
 		if(select=='y')
 		{
 			cout<<"ENTER YOU CHOICE:";
 			string j;
 			cin>>j;
 			if(j==menu[k] || j==menu[k+1] || j==menu[k+2])
 			{
		order[i+1]=j;	 
		i++;
 			again(j);
 		}
		 }
		 else
		 {
		 
		 return 0;
 }
 }
 listorder()
 {
 	cout<<"List of orders taken:"<<endl;
 	for(int i=0;i<4;i++)
 	cout<<order[i]<<endl;
 	
 	
 }
 		fulfillorder()
 		{int i;
 			string b;
 			if(order[i]!=b)
 			for(i=0;i<4;i++)
 			{
			 
 			if(order[i+1]==b)
 			break;
 		}
 			else
 			cout<<"NO Orders left";
		 }
 dueamount()
 {
 	string u = "Coffee";
 	string m = "Tea";
 	string e = "Scone";
 	string l = "Donut";
 	for(int i=0;i<4;i++)
 	{
 		if(u==order[i])
 		{
 			p++;
 			
		 }
		 else if(order[i]==m)
		 {
		 	q++;
		 }
		 else if(e==order[i])
		 {
		 	r++;
		 }
		 else if(l==order[i]){
		 	s++;
		 }
		 
	 }
 	
 	float bill = (p*7) + (q*8) + (r*15) + (s*10);
 	cout<<"BILL:$"<<bill<<endl;
 	
 }
	
};
main(){
	coffeeshop C1;
}

