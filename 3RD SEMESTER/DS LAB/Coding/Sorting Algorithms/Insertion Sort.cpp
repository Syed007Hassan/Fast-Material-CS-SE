#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n){
	
	for(int i=1; i<n; i++){
		int key = arr[i];
		int j = i-1;
		
		while(j>-1 && (arr[j]>key)){
			arr[j+1]= arr[j];
			j--;
		}
		arr[j+1]=key;
		
	}
}

int main(){
	int arr[] = {7,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	InsertionSort(arr,n);
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	return 0;
}
