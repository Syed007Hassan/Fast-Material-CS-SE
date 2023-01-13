#include <iostream>
#include <fstream>
#include<string>
using namespace std;
 
 
class Participants{
	
	public:
		int id[2],j;
		string name[2];
		int score[2];
		int arr;
		
		input(){
			for(int i=0;i<2;i++){
			
			cout<<"\n\nEnter id "<<i+1<<" :";
			cin>>id[i];
			
			getchar();
			cout<<"Enter the name: ";
			getline(cin,name[i]);
			
			cout<<"enter the score: ";
			cin>>score[i];
    	}
    	
    	cout<<endl;
		}
		
	      max() {
			for(int i=0;i<2;i++) {
				if(score[i] > score[i+1]) {
					arr=score[i];
				}
			
				
			}
		}  
		
		 output(){
		 	cout<<"READING FROM THE FILE: "<<endl<<endl;
			for(int i=0;i<2;i++){
            cout<<"Name:" << name[i] << endl;
	   		cout<<"Score: " << score[i] <<endl;
	   		cout<<"ID: " << id[i] <<endl<<endl;
           }
           
           cout<<"The maximum score is "<<arr<<endl;
       }
        
		 
		         	
}; 

int main(){
	
    Participants p1;
   	
	fstream file;
	file.open("participant.dat",ios::out);	
	
	p1.input();
	p1.max();
	file.write((char*)&p1, sizeof(p1));
    file.close();
    
    file.open("participant.dat", ios::in);
	file.read((char*) &p1, sizeof(p1));
	p1.output();
	file.close();
	
	

}
