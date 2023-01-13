#include<iostream>
#include<cmath>

using namespace std;

double billinamount(int hpr,int tct,int ti);

int main(){
	
	double hpr;
	int ti;
	int tct;
	
	cout<<"***Welcome to J&J accounting, we provide firm assistance***\n\n";
	 
	cout<<"Enter the hourly pay rate: ";
	cin>>hpr;
	
	cout<<"Enter the total consulting time in minutes: ";
	cin>>tct;
	
	cout<<"Enter the total income: ";
	cin>>ti;
	
	if(ti <= 25000 ){
		cout<<"The customer has low total income\n";
	}
	else{
		cout<<"The customer has high total income\n";
		
	}
	
	cout<<"The billing amount is: $ "<<billinamount(hpr,tct,ti);
	
}

double billinamount(int hpr,int tct,int ti){
	
  if (ti <= 25000) {
      if (tct <=30)
          return 0;
      else
          return hpr*0.40*((tct-30)/60);
  }
    else {
        if (tct <= 20)
            return 0;
        else
            return hpr*0.70*((tct-20)/60);
    }
    
}
          

	
	
	
	
	
	
	

