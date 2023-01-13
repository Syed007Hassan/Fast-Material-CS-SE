#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
 using namespace std;
 
   float x=0;
    
    class invoice{
    private:
     string pn[50];
     string pd[50];
     int quan[50];
     double price[50];
    
	public:
	   invoice(){
	   	
	   	int choice;
	   	double x;
	   	cout<<"Enter the no of purchases: ";
	   	cin>>choice;
	   	cout<<endl;
	   	
	   	for(int i=1;i<=choice;i++){
	   		
	   		cout<<"Enter the product "<<i<<" no: ";
	   		cin>>pn[i];
	   		
	   		getchar();
	   		cout<<"Enter the product details: ";
	   	     getline(cin,pd[i]);
	   		
	   		cout<<"Enter the quantity of the product: ";
	   		cin>>quan[i];
	   		
	   		cout<<"Enter the price of the product: ";
	   		cin>>price[i];
	   		
	   	cout<<endl;
	   	getchar();
	   	
	   		x= x + amount(choice);
	   		
	   	
	   }
	   for(int i=1;i<=choice;i++){
	   	
	   	cout<<"The Product "<<i<<" no: "<<pn[i]<<endl;
		cout<<"The Product detail is: "<<pd[i]<<endl;
		cout<<"The quantity of the product: "<<quan[i]<<endl;
		cout<<"The price of the a single product: "<<setprecision(2)<<price[i]<<endl;   	   		
	   
	   
	    cout<<endl;
	
	}
	cout<<"The total amount is: "<<x<<endl;
	cout<<"****************************************";
	}
		   
		   
	double amount(int choice){
		
		int i;
		double arr;
		
		arr= arr + (quan[i]*price[i]);
		
	//	cout<<"amount is: "<<arr<<endl;
		
		if(choice == i){
		cout<<"*****The invoice of the hardware store is:*****\n\n";
		cout<<"The total amount is: "<<arr<<fixed<<endl;
			}
	}
	
	
	
	

	
};
	
	int main(){
		cout<<"\t\t\t^_^_^Welcome to the hardware store^_^_^\n\n";
		invoice h1;
			
	}
