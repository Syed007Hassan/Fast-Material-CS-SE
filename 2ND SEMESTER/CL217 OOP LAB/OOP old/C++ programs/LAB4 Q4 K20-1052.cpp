#include <iostream>
#include<string>
using namespace std;

class Books{
	
	private:
		string author[3];
		string title[3];
		int price[3];
		string publisher[3];
		int stkpos[3];
	public:
		
	Books(){
		
		
		author[0]="Jkrolling";
		author[1]="KhaledHosseini";
		author[2]="J.R.R.Tolkien";
		title[0]="Harry Potter";
		title[1]="Kite Runner";
		title[2]="lord of Ring";
		price[0]=3000;
		price[1]=2500;
		price[2]=4300;
		publisher[0]="xyz";
		publisher[1]="zyx";
		publisher[2]="yzx";
		stkpos[0]=5;
		stkpos[1]=6;
		stkpos[2]=8;
				
	}
	
	display(){
		
		cout<<"The list of books are as follows:\n\n";
		cout<<"Book author\tBook title\tPrice\tPublisher\tStockPosition\n";
		cout<<author[0]<<"\t"<<title[0]<<"\t"<<price[0]<<" \t   "<<publisher[0]<<"   \t  "<<stkpos[0]<<"\n";
		cout<<author[1]<<"\t"<<title[1]<<"\t"<<price[1]<<" \t   "<<publisher[1]<<"   \t  "<<stkpos[1]<<"\n";
		cout<<author[2]<<"\t"<<title[2]<<"\t"<<price[2]<<" \t   "<<publisher[2]<<"   \t  "<<stkpos[2]<<"\n\n\n";		
	
	}	
	
	
	search(){
		string ba,bt;
		int copy,aa,x;
		float amount;
		
		cout<<"Enter the name of the Book Author: ";
		getchar();
		getline(cin,ba);
		cout<<"Enter the name of the Book Title: ";
		getline(cin,bt);
		
		for(int i=0;i<3;i++){
			
			if(ba == author[i]){
				
				if( bt == title[i]){
					cout<<endl;
					cout<<"The Book is available and the copies that are available are: "<<stkpos[i]<<endl<<endl;
					
					cout<<"Enter the no of copies you want: ";
					cin>>copy;
					
					if(copy > stkpos[i]){
						    x=validcopy(copy,i,stkpos);
						    amount=x*price[i];
						cout<<endl;
						cout<<"The book you have bought is: "<<title[i]<<" and the quantity is "<<x<<endl;
						cout<<"The amount is: "<<amount<<endl;
						    
					}
					else{
						
						amount=copy*price[i];
						cout<<endl;
						cout<<"The book you have bought is: "<<title[i]<<" and the quantity is "<<copy<<endl;
						cout<<"The amount is: "<<amount<<endl;
					}
					
					cout<<endl;
					cout<<"Do you want to buy another book? If yes enter 1: ";
					cin>>aa;
					cout<<endl;
					if(aa == 1){
						search();
					}
				}
			
			else{
				cout<<endl;
				cout<<"Enter the correct name of Book Author or the Title: "<<endl;
				search();
			}
			
			
			}
		}
		
				
		
	}
	
	int validcopy(int copy,int i,int stkpos[3]){
		
		cout<<"Required copies not in stock,Enter the valid no of copies: ";
		cin>>copy;
		
		if(copy > stkpos[i]){
			validcopy(copy,i,stkpos);
		}
		else{
			return copy;
		}
	}
		
		
};

int main(){
	
	Books b1;
	cout<<"MENU\n";
	cout<<"1.Display books\n2.Search book\n3.Exit\n\n";

    
     	int choice;
     	cout<<"Enter the choice: ";
	    cin>>choice;
   		
		switch(choice){
			
			case 1:
			b1.display();
	     	main();
		
			break;
			
			case 2:
			b1.search();
			main();
		
		
			break;
			
			default:
				exit(0);
				break;	
			
		}
		
	}
		
		
	



