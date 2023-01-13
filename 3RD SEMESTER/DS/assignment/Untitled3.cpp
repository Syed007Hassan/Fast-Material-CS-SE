#include<iostream>
using namespace std;

int find(int arr[],int n,int x){
	int i=0;
	while(arr[i] != x){
		
		if(arr[i] == x){
			cout<<"Element has been found: "<<endl;
			break;
		}
		
		i++;
		if(i+1>x){
			cout<<"No element has been found "<<endl;
			break;
		}
		
		
	}
	
}



int main(){
	
	int arr[]={1,44,32,45,87,123,453,12,89,76};
	int n = sizeof(arr)/sizeof(int);

	
	find(arr,n,45);
}
