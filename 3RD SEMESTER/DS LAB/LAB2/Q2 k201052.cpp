#include<iostream>
using namespace std;
int main (){
	
	
	int *arr = new int[10];
	int *arr2 = new int[10];
	int temp;
	
	cout<<"Enter the elements of array: "<<endl;
	
	for(int i=0;i<10;i++){
		cout<<"arr["<<i<<"]: ";
		cin>>*(arr + i);
		
	} 
	for(int i=0;i<10;i++){
	*(arr2 + i)= *(arr + i);
	}
	
	cout<<endl<<"Elements copied to new dynamic array are: "<<endl;
	for(int i=0;i<10;i++){
		cout<<"arr["<<i<<"]: "<<*(arr2 + i)<<endl;;
	}
	
		
	for(int i=0;i<10;i++){
		
		for(int j=i+1;j<10;j++){
		
		
		if(	*(arr2 + i) > 	*(arr2 + j)){
			temp = 	*(arr2 + i);
				*(arr2 + i) = 	*(arr2 + j);
				*(arr2 + j) = temp;
			
		}
		
	}
	}
	
	cout<<endl<<"Elements in ascending order are: "<<endl;
	
	for(int i=0;i<10;i++){
		cout<<*(arr2 + i)<<endl;
	}
	
	
	for(int i=0;i<10;i++){
		
		for(int j=i+1;j<10;j++){
		
		
		if(	*(arr2 + i) < 	*(arr2 + j)){
			temp = 	*(arr2 + i);
				*(arr2 + i) = 	*(arr2 + j);
				*(arr2 + j) = temp;
			
		}
		
	}
	}
	
	cout<<endl<<"Elements in descending order are: "<<endl;
	
	for(int i=0;i<10;i++){
		cout<<*(arr2 + i)<<endl;
	}
	
		
}

