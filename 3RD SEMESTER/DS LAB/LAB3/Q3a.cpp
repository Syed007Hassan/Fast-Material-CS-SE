#include<iostream>
using namespace std;
//tail recursive sorting 

void printff(int arr[],int size);
int sorting(int arr[],int size){
 	
 	if(size == 1){
 		return arr[0];
	 }
	 
	 else{
	 	
	 	for(int i=0;i<size-1;i++){
	 		if(arr[i] > arr[i+1]){
	 			swap(arr[i],arr[i+1]);
			 }
		 }
		 
		 return sorting(arr,size-1);    //this is the last executing function
	 }	 	 	 
}

 void printff(int arr[],int size){
 	cout<<"Printing Sorted elements in ascending order: "<<endl;
 	for(int i=0;i<size;i++){
 		cout<<arr[i]<<endl;
	 }
 }

int main(){
	 
	  int arr[] = {1,32,54,23,12,76,86,23,56,99};
	  
	  int size = sizeof(arr)/sizeof(int);
	  
	  sorting(arr,size);
	  printff(arr,size);
	
}
