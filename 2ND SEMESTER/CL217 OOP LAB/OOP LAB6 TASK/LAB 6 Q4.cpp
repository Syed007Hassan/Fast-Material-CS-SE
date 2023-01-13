#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class CoffeeShop{
	private:
	 const string sname;
		string menu[4][3];
		string orders[3];
		
	public:
		CoffeeShop():sname("Hassan Coffer Shop"){
	   	menu[0][0]="item";
	   	menu[0][1]="type";
	   	menu[0][2]="price";
	   	menu[1][0]="pizza";
	   	menu[1][1]="food";
	   	menu[1][2]="200$";
	   	menu[2][0]="pasta";
	   	menu[2][1]="food";
	   	menu[2][2]="300$";
	   	menu[3][0]="coffee";
	   	menu[3][1]="drink";
	   	menu[3][2]="65$";
	  // 	sname = hassan Coffer Shop";
	   	int ch,i,j;
	   	float n_bill;
	   	
	   	cout << "\n\t\t\t~~~~ "<< sname << " ~~~~\n\n";
	   	for(int i=0;i<4;i++){
	   		
	   		for(int j=0;j<3;j++){
	   			cout<<menu[i][j]<<"\t\t\t";
			   }
		cout<<endl;
		}
	   	cheapestItem();
	   	drinksOnly();
	   	foodOnly();
	   	cout << "\n\nEnter 1 to add order else enter 0: ";
	   	cin >> ch;
	   	if(ch==1) {
	   		n_bill=addOrder();
	   		cout << "\nEnter 1 to view ordered list else enter 2 to view due amount:";
	   		cin >> ch;
	   		if (ch==1) {
	   			listOrders(n_bill);
			   }
			else
			{
				dueAmount(n_bill);
			   }   
		   }
		else {
			cout << "\nHope to see you soon.";
			exit(0);
		}   
	   }
	   
	   float addOrder() {
	   	string item;
	   	int qty,cho;
	   	static float bill=0;
	   	static int i=0;
		cout << "\n\nEnter the name of item to give order in small letters: ";
	   	cin >> item;
	   	if(item==menu[1][0])
	   	{
	   		cout << "\nEnter the quantity of item: ";
	   		cin >> qty;
	   		orders[i]= item;
	   		i++;
	   		cout << "\nOrder noted!";
	   		bill = bill + (qty*200);
	   		cout << "\nEnter 1 if you want to order more else enter 0: ";
	   		cin >> cho;
	   		if (cho==1) {
	   			addOrder();
			   }
			else {
				fullfillOrder();
				return bill;
			}   
		   }
		else if(item==menu[2][0])
	   	{
	   		cout << "\nEnter the amout of item: ";
	   		cin >> qty;
	   		orders[i]= item;
	   		i++;
	   		cout << "\nOrder noted!";
	   		bill = bill + (qty*300);
	   		cout << "\nEnter 1 if you want to order more else enter 0: ";
	   		cin >> cho;
	   		if (cho==1) {
	   			addOrder();
			   }
			else {
				fullfillOrder();
				return bill;
			}
		   }
		else if(item==menu[3][0])
	   	{
	   		cout << "\nEnter the amout of item: ";
	   		cin >> qty;
	   		orders[i]= item;
	   		i++;
	   		cout << "\nOrder noted!";
	   		bill = bill + (qty*65);
	   		cout << "\nEnter 1 if you want to order more else enter 0: ";
	   		cin >> cho;
	   		if (cho==1) {
	   			addOrder();
			   }
			else {
				fullfillOrder();
				return bill;
			}
		   }
		else
		{
			cout << "\nItem unavailable.";
			cout << "\nEnter 1 if you want to order again else enter 0: ";
			cin >> cho;
			if (cho==1) {
	   			addOrder();
			   }
			else {
				fullfillOrder();
				return bill;
			}
		}         
	   	
	   }
	   
	   void fullfillOrder()
	   {
	   	int i;
	   	string b;
	   	if(orders[0]== b)
	   	{
	   		cout << "\n\nAll orders are fullfiled.";
		   }
		else
		{
			for(i=0;i<3;i++) {
				if(orders[i] != b)
				cout<<"\n \t Your "<<orders[i]<<" is ready\n";
			}
		   }   
	   }
	   
	   void listOrders(float n_bill) {
	   	int i;
	   	string b;
	   	cout << "\n\nItems: \n\n";
	   	for(i=0;i<3;i++) {
	   		if(orders[i] != b)
			cout << orders[i];
			cout << endl;
		   }
		dueAmount(n_bill);      
	   }
	   
	   void dueAmount(float n_bill)
	   {
	   	cout << "\n\n\t\t    Your Total bill is: " << n_bill << " $";
	   	cout << "\n\n\t\t\tPlease Visit Again.";
	   }
	   
	   void cheapestItem() 
	   {
	   		int i;
	   		cout << "\n\nCheapest Iteam: \n";
		    for(i=0;i<3;i++)
		    cout<<menu[3][i]<<"\t\t\t";
	   }
	   
	   void drinksOnly()
	   {
	   		int i;
	   		cout << "\n\nDrinks Only: \n";
		    for(i=0;i<3;i++)
		    cout<<menu[3][i]<<"\t\t\t";
	   }
	   
	   void foodOnly()
	   {
	   		int i,j;
	   		cout << "\n\nFood Only: \n";
		    for(i=1;i<3;i++) 
		    {
		    	for(j=0;j<3;j++)
		    	cout<<menu[i][j]<<"\t\t\t";
		    	cout << "\n";
			}
	   }
};

int main()
{
	CoffeeShop c;
}
