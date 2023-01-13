#include <iostream>
using namespace std;

void ShellSort(int arr[], int n){
	
	for(int gap= n/2; gap>0; gap/=2)
	{
		for(int i= gap; i<n; i++)
		{
			int temp = arr[i];
			int j= i-gap;
			while(j>-1 && arr[j]>temp){
				arr[j+gap] = arr[j];
				j-= gap;
			}
			arr[j+gap]= temp;
		}
	}
}

int main(){
	int arr[] = {7,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	ShellSort(arr,n);
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	return 0;
}
