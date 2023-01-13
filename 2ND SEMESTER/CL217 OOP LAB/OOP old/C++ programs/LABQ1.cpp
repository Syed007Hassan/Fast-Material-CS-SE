#include <iostream>
using namespace std;

struct playerData
{
    string name;
    int homeRuns;
    int hits;
    int id;
};

int main()
{
  playerData player[10];
  int arr[10];
  int i,idd,choice;
  cout<<"1- For storing the data of baseball players\n2- For finding the info of a certain player stored in index\n3- For finding the index of a specific player, and update the data of a player.\n4- For showing the info of all players\n\n";

do{
   
   cout<<"Input the choice ";
  cin>>choice;
   switch(choice){

  case 1:
  	cout<<endl;
for(i=0; i<2; i++)
{
    cout << "Enter name of the player " << i << ": ";
    cin >> player[i].name;
    cout << "Enter the number of home runs: ";
    cin >> player[i].homeRuns;
    cout << "Enter the number of hits: ";
    cin >> player[i].hits;
    cout << "Enter the id of player: ";
    cin >> player[i].id;


     cout<<endl;
     
 }
 break;

case 2:

    cout<<endl;
    cout << "Enter the ID of the player for searching: ";
    cin >> idd;
    for(int i=0 ;i<2; i++){
    if(idd == player[i].id){
    	
    cout<<"Name: "<<player[i].name<<endl;
    cout<<"Home runs: "<<player[i].homeRuns<<endl;
    cout<<"Hits: "<<player[i].hits<<endl;
   }  
   

}
break;

case 3:
	cout<<endl;
 cout << "Enter the ID of the player to change the data: ";
 cin >> idd;
 
 cout<<endl;
 
  for(int i=0 ;i<2; i++){
    if(idd == player[i].id){
    
	cout<<"Enter the new Name of player: ";	
    cin>> player[i].name;
    cout<<"Enter the new home runs of player: ";
    cin>> player[i].homeRuns;
    cout<<"Enter the new hits for player: ";
    cin>> player[i].hits;
}

}
break;

case 4:
	cout<<endl;
   cout<<"The detail of each player is\n";

   for(int i=0 ;i<2; i++){
 	
    	cout<< "Name: " << player[i].name<<endl;
        cout<< "Home runs: "<< player[i].homeRuns<<endl;
        cout << "Hits: "<< player[i].hits<<endl;

}

        default:
        	cout<<endl;
        cout << "Enter the correct choice\n";

}
    
    cout<<"If you want to do further task enter correct choice else it will terminate\n";
}
while(choice >= 1 || choice <=4);
return 0;
}

