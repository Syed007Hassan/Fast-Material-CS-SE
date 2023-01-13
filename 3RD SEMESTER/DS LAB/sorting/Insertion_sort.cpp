#include<iostream>
using namespace std;

void InsertionSort(int data[ ], int n){

     for(int i = 1; i<n; i++){
  
       int current = data[i];
       int j = i-1;
       
       while(data[j] > current && j>=0){
       	
       	data[j+1] = data[j];
       	j--;
	   }
	   
	   data[j+1] = current;
    
   }

	for(int i=0;i<10;i++){
		cout<<data[i]<<" ";
	}
}


int main(){
	
	int arr[] = {1,2,5,3,7,4,8,10,6,9};
		int n = sizeof(arr)/ sizeof(int);
	

	InsertionSort(arr,n);
	
	
}
