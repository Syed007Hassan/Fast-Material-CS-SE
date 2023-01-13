#include <iostream>
using namespace std;

int main(){
	int a,b;
	int arr[10][10];
	int stop;
	cout<<"Enter no. of Rows: \n";
	cin>>a;
	cout<<"Enter no. of column: \n";
	cin>>b;
	 if(a!=b){
	 	cout<<"It is not a identity matrix";
	 }
	 else
	 for(int i=0;i<a;i++){
	 	for(int j=0;j<b;j++){
	 		
	 		cout<<"arr["<<i<<"]"<<"["<<j<<"]";
	 		cin>>arr[i][j];
		 }
	 }
	for(int i=0;i<a;i++){
	 	for(int j=0;j<b;j++){
	 		
			 if((i==j))
			{
				if(arr[i][j]!=1)
				{

				stop=1;
				}
	 	}
		 else if(arr[i][j]!=0)
			{
			stop=1;
			}
		}}
	 	
	 	if(stop==0){
		 
	 			cout<<"Array is a identity matrix \n";
	 			
			 }
			 else{
			 cout<<"Array is not a identity matrix \n";	
			 }
			 
		for(int i=0;i<a;i++){
	 	for(int j=0;j<b;j++){
	 		cout<< arr[i][j] <<" ";
	 	
		 }
		 
cout<<"\n";}
}

