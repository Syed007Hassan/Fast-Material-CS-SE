#include<iostream>
using namespace std;



  void SelectionSort(int data[ ], int n){
  	
for(int i = 0, j, least; i < n - 1; i++){
	
for( j = i + 1, least = i; j < n; j++)


    if (data [ j ] < data [least])
	
       least = j;
       
    swap (data [ least ], data [ i ] );


	
}

	for(int x = 0;x<n;x++){
		
		cout<<data[x]<<" ";
	}
}

int main(){
	
	int arr[] = { 1, 2, 5, 3, 7, 4, 8, 10, 6, 9 };
	int n = 10;
	

	
	SelectionSort(arr,n);	
}
