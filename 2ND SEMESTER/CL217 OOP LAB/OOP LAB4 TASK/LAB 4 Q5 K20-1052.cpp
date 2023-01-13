#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
using namespace std;


class CoffeeShop{
	
	private:
		string sname;
		string menu[4][3];
		string orders[3][3];
		
		
	public:
	   CoffeeShop(){
	   	
	   	menu[0][0]="item";
	   	menu[0][1]="type";
	   	menu[0][2]="price";
	   	menu[1][0]="1-pizza";
	   	menu[1][1]="food";
	   	menu[1][2]="200";
	   	menu[2][0]="2-Pasta";
	   	menu[2][1]="food";
	   	menu[2][2]="300";
	   	menu[3][0]="3-coffee";
	   	menu[3][1]="drink";
	   	menu[3][2]="65";
	   	
	   }
	     	
		   show(){
		   	for(int i=0;i<4;i++){
	   		
	   		for(int j=0;j<3;j++){
	   			
	   			cout<<menu[i][j]<<"\t\t\t";
	   			
			   }
			   cout<<endl;
		}
		   	
		   }
		 
		   addorder(){
		   	int aa,quan[3];
		   	float amount[3],amount1;
		   	cout<<"Enter the no to give order of the meal: ";
		   	cin>>aa;
		   	
		   	if(aa == 1){
		   		cout<<"Item available"<<endl;
		   		cout<<"Enter the quantity of the item: ";
		   		cin>>quan[0];
		   		amount[0]= amount[0]+ quan[0]*200;
		   		amount1=amount1+amount[0];
		   		orders[0][0]="Pizza";
		   		orders[0][1]=quan[0];
		   		orders[0][2]=amount[0];
		   		cout<<"The order is: "<<endl;
		   	cout<<orders[0][0]<<endl;
		   	cout<<"Quantity "<<orders[0][1]<<endl;
		   	cout<<"Amount "<<orders[0][2]<<endl;
		   		
			   }
			   else if(aa==2){
			   	cout<<"Item available"<<endl;
		   		cout<<"Enter the quantity of the item: ";
		   		cin>>quan[1];
		   		amount[1]= amount[1]+ quan[1]*300;
		   		amount1=amount1+amount[1];
		   		orders[1][0]="Pasta";
		   		orders[1][1]=quan[1];
		   		orders[1][2]=amount[1];
			   	
			   }
			   
			   else if(aa == 3){
			   	cout<<"Item available"<<endl;
		   		cout<<"Enter the quantity of the item: ";
		   		cin>>quan[2];
		   		amount[2]= amount[2]+ quan[2]*65;
		   		amount1=amount1+amount[2];
		   		orders[2][0]="Coffee";
		   		orders[2][1]=quan[2];
		   		orders[2][2]=amount[2];
			   	
			   }
			   
			   else{
			   	fullfillorder();
			   }
		   	
		   	listOrder(amount,amount1);
		   	
		   }
		   
		   fullfillorder(){
		   	 
		   	 if(orders == NULL){
		   	 	cout<<"The item is ready"<<endl;
		   	 	
				}
				else{
					
					cout<<"All orders have been fulfilled"<<endl;
				}
		   	
		   }
		   
		   
		   int listOrder(float amount[3],float amount1){
		   	cout<<"The order is: "<<endl;
		   	cout<<orders[0][0]<<endl;
		   	cout<<"Quantity "<<orders[0][1]<<endl;
		   	cout<<"Amount "<<orders[0][2]<<endl;
		   	
		   	
		   }
	   	
	
};

	int main(){
		
		CoffeeShop a1;
		a1.show();
		a1.addorder();
		a1.fullfillorder();
		
	}
	
