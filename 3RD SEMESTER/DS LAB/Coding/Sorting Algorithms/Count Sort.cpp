#include <iostream>
using namespace std;

int findMax(int arr[], int n){
	int max = arr[0];
	
	for(int i=0; i<n; i++)
		if(arr[i]>max)
			max= arr[i];
	return max;
}

void CountSort(int arr[], int n){
	int max= findMax(arr,n);
	int *c = new int[max+1];
	for(int i=0; i<max+1; i++)
		c[i] = 0;
	
	for(int i=0; i<n; i++)
		c[arr[i]]++;
	
	int j = 0, i=0;
	while(i<max+1){
		if(c[i]>0){
			arr[j++]=i;
			c[i]--;
		}
		else
			i++;
	}
	
}

int main(){
	int arr[] = {7,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	CountSort(arr,n);
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	return 0;
}
