#include<iostream>
#include<stdlib.h>
using namespace std;
//S.M.HASSAN ALI K201052

int main(){
	
	
     int *arr { new int[10]{23,34,22,56,89,54,68,45,87,32}};
     int *arr2 = new int[10];
     int temp,max=9,min=0;
     
     //sorting happens here
     	for(int i=0;i<10;i++){
		
		for(int j=i+1;j<10;j++){
		
		
		if(	arr[i] > arr[j] ){
			temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			
		}		
	}
	}
	
	cout<<endl<<"Elements in ascending order are: "<<endl;
	
	for(int i=0;i<10;i++){
		cout<< arr[i]<<endl;
	}
	
	cout<<endl<<endl;
	
	 int x = 1;
	for(int i=0;i<10;i++){
		
		if(x == 1){
		
		arr2[i] = arr[max--];
	}
	else{
	
		arr2[i] = arr[min++];
	
    }
     x = !x;
	}
	
	
	for(int i=0;i<10;i++){
		
		cout<<arr2[i]<<endl;
	}
	
	delete []arr;
	delete []arr2;
	
}
