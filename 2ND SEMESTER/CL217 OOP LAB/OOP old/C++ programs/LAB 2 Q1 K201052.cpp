#include <iostream>
using namespace std;
      
	  
	  float residentialbill(){
      int code,premiumchan;
      float total;

        cout<<"Enter the customers code:\t";
        cin>>code;
        cout<<"Enter the number of premium channels:\t";
        cin>>premiumchan;
        
        cout<<endl;
        
        cout<<endl<<endl;
        float billprocessfee=4.50;
        float basicservicefee=20.50;
        float premiumfee=premiumchan*7.50;

        total=billprocessfee+basicservicefee+premiumfee;
       
	   return total;

}

      float businessbill(){
      int accno,code,premiumchan,total,connections;
      int rem;

      
      cout<<"Enter the customers code: ";
      cin>>code;
      cout<<"Enter the number of premium channels: ";
      cin>>premiumchan;
      cout<<"Enter the number of connections: ";
      cin>>connections;
      
       cout<<endl;

     float billprocessfee= 15.00;
     float basicservicefee;
     float premiumfee=premiumchan*50.00;

    if(connections<=10){
      basicservicefee=75.00;
   }
     else
   {
    
	rem=connections-10;
     basicservicefee= 75.00+ 5*rem;
    } 
    total= billprocessfee+basicservicefee+premiumfee;

     return total;

   }
int main(){


   int accno;
   char choice;
   float x,y;
       cout<<"1-Enter R or r For Residential Customers"<<endl;
       cout<<"2-Enter B or b Business Customers"<<endl<<endl;

       cout<<"Enter your choice: ";
       cin>>choice;

      switch(choice){
     case 'r':
     case 'R':	
     cout<<"Enter the customers account number: ";
     cin>>accno;
     x=residentialbill();
     
	 cout<<"The customer account no is: "<<accno<<endl; 
     cout<<"Total Billing Price of Residential customer is: $"<<x;
     break;
     
     
     case 'b':
     case 'B':
    cout<<"Enter the customers account number: ";
    cin>>accno;
    y= businessbill();
    	 cout<<"The customer account no is: "<<accno<<endl; 
    cout<<"Total Billing Price of Business customer is: $"<<y;

   break;
   
   default:
   cout<<"WRONG INPUT DETECTED"<<endl;
}


}
