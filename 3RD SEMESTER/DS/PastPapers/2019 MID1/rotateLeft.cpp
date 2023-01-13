#include <iostream>
using namespace std;

void RotateLeft(int arr[], int n, int r){
	int i;
	for(int k=0; k<r; k++){
		int temp= arr[0];
		for(i=0; i<n; i++){
			arr[i]= arr[i+1];
		}
		arr[i-1]= temp;
	}
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
}

int main(){
	int arr[]={5,4,3,2,1};
	for(int i=0; i<5; i++)
		cout << arr[i] << " ";
	cout << endl;
	RotateLeft(arr,5,3);
	return 0;
}
