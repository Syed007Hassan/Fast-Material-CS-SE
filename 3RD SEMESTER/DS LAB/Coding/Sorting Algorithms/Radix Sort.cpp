#include <iostream>
using namespace std;

int findMax(int arr[], int n){
	int max = arr[0];
	
	for(int i=0; i<n; i++)
		if(arr[i]>max)
			max= arr[i];
	return max;
}

void CountingSort(int arr[], int n, int exp){
	int max= findMax(arr,n);
	int count[max+1];
	int output[n];
	
	for(int i=0; i<max+1; i++)
		count[i]=0;
	
	for(int i=0; i<n; i++)
		count[(arr[i]/exp)%10]++;
	
	for(int i=1; i<max+1; i++)
		count[i] += count[i-1];
	
	for(int i=n-1 ; i>=0; i--)
		output[--count[(arr[i]/exp)%10]]= arr[i];
	
	for(int i=0; i<n; i++)
		arr[i]= output[i];
	
}

void RadixSort(int arr[], int size){
	int max= findMax(arr,size);
	
	for(int exp = 1; max/exp>0; exp*=10){
		CountingSort(arr,size,exp);
	}
}

int main(){
	int arr[] = {7,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	RadixSort(arr,n);
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	return 0;
}
