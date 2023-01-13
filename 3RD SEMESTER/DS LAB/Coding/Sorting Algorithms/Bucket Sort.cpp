#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void BucketSort(int arr[], int n){
	vector<int> b[n];
	for(int i=0; i<n; i++){
		int bi = n*arr[i];
		b[bi].push_back(arr[i]);
		cout << bi;
	}
	
	for(int i=0; i<n; i++){
		sort(b[i].begin(), b[i].end());
	}
	
	int index = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j< b[i].size(); j++){
			arr[index++]= b[i][j];
		}
	}
	
}

int main(){
	int arr[] = {7,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	BucketSort(arr,n);
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	return 0;
}
