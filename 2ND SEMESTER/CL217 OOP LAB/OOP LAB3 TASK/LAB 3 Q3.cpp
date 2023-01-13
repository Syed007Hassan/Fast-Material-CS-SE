#include<iostream>
using namespace std;

class Glass{
    	
 	public:
 		
  	int Liquidlevel=200;
 		
 		publicdrink(){
 			int a,b;
 	
 			
 			cout<<"Enter the level of drink in ml the user required: ";
 			cin>>a;
 			
 			b=Liquidlevel-a;
 			
 			if(b < 100){
 				
 				cout<<"The "<<b<<" ml of drink is left now\n\n";
 				publicrefill(b);
 				
 			}
 			
 			else{
 				
 				againpd(b);
 				
			 }
		}
		
		againpd(int b){
			int a;
		    cout<<"The "<<b<<" ml of drink is left now\n\n";
			cout<<"Enter the level of drink in ml the user required: ";
 			cin>>a;
 			
 			b=b-a;
 			
 			if(b < 100){
 				
 				publicrefill(b);
			 }
			 else{
			 	
			 	againpd(b);
			 }
			 
		}
 				
 				publicrefill(int b){
 					int opt;
 					cout<<"The "<<b<<" ml of drink is less than 100ml so it will be refilled\n\n";
 					cout<<"The drink is now refilled to 200ml"<<endl;
 					
 					cout<<"Do you want to take drink again? Press 1 for it else it terminate\n\n";
 					cin>>opt;
 					if(opt==1){
 						
 						publicdrink();
					 }
					 else{
					 	
					 	exit(0);
					 }
 					
				 }
 				
 			
};


int main(){
	
	
	Glass g1;
	
	g1.publicdrink();
	
	
	
}
