#include <iostream>
using namespace std;

class Account
{
       private:
       float accountbalance=9999;

       public:
       Account()
    {
       int choice,i;
       cout<<"1.Add Balance\n2.Withdraw Balance\n3.Show Balance\n4.Enter any other to Exit\n";

         for(i=1;i>=1;i++){          //infinite loop condition
         
		cout<<"Enter your Choice: ";
        cin>>choice;

       switch(choice){
       case 1:
       
	   addbalance();
       break;
       
	   case 2:
       withdraw();
       break;
       
	   case 3:
       showbalance();
       break;
      
	  default:
      exit(1);
}
}

}

      int addbalance(){
        double a;
       cout<<"Enter the amount of money you want to add in the current balance of: "<<accountbalance<<" ";
       cin>>a;
       accountbalance=accountbalance+a;;
       cout<<"The current balance after adding money in the account is: "<<accountbalance<<endl;
    }

   withdraw()
  {
       double b;
        cout<<"Enter the amount of money you want to withdraw: ";
          cin>>b;
          if(b > accountbalance){
          	withdraw();
		  }
		  else{
		  
         accountbalance=accountbalance-b;
         cout<<"The Balance after Withdrawal of money "<<b<<" is: "<<accountbalance<<endl;
  }
  }

      showbalance(){
         cout<<"The current amount left in your account is: "<<accountbalance<<endl;
        }


};


   int main(){

    Account acc1;  //user defined default constructor calling
}
