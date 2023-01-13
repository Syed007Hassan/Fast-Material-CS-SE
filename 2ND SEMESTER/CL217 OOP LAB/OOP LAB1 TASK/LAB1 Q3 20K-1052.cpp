#include <iostream>
#include <iomanip>
using namespace std;


struct stdinfo{
	
	char name[50];
	double marks[5];
	double avg;

};

int main(){
	
	stdinfo s1;
	
	int i;
	double sum;
	
	cout<<"Enter the name of the student  ";
    cin.getline(s1.name,50);
    
    cout<<"Enter the 5 test scores"<<endl;
	for(int i=0;i<5;i++){
		
		cin>>s1.marks[i];	
	}
	
		for(int i=0;i<5;i++){
		
		sum = sum + s1.marks[i];	
	}
	
	s1.avg=sum/5;
	
	
	
	cout<<endl;
	cout<<"Student name is: "<<s1.name<<endl;
	
	cout<<"Test scores: ";
	for(int i=0;i<5;i++){
	cout<<fixed<<setprecision(2)<<s1.marks[i]<<" ";
		
}

   cout<<endl;
    
   cout<<fixed<<setprecision(2)<<"The average test score is: "<<s1.avg; 

	
}
