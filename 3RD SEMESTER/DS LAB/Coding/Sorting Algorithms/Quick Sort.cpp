#include <iostream>
using namespace std;

int partition(int arr[], int l, int h){
	int pivot = arr[l];
	int i = l, j = h;
	
	do{
		do{
			i++;
		}while(arr[i] <= pivot);
		do{
			j--;
		}while(arr[j] > pivot);
		
		if(i<j){
			int t= arr[i];
			arr[i]= arr[j];
			arr[j] = t;
		}
	}while(i<j);
	
	int t= arr[l];
	arr[l] = arr[j];
	arr[j] = t;
	
	return j;
}

void QuickSort(int arr[], int l, int h){
	
	if(l<h){
		int j = partition(arr,l,h);
		QuickSort(arr,l,j);
		QuickSort(arr,j+1,h);
	}
}

int main(){
	int arr[] = {7,4,3,2,1, INT32_MAX};
//	int n = sizeof(arr)/sizeof(arr[0]);
	int n= 6;
	QuickSort(arr,0,n-1);
	
	for(int i=0; i<n-1; i++)
		cout << arr[i] << " ";
	return 0;
}
