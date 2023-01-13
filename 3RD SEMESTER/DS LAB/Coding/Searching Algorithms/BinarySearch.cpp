#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int l, int r, int key){
	
	if(l<=r){
		int mid = (l+r)/2;
		if(arr[mid]==key)
			return true;
		else if(arr[mid]>key)
			return BinarySearch(arr, l, mid-1, key);
		else
			return BinarySearch(arr, mid+1, r, key);
	}
	return false;
}

int main(){
	int arr[]= {1,2,3,4,5,6,7,8,9,10};
	int size= sizeof(arr)/sizeof(arr[0]);
	int key=6;
	cout << BinarySearch(arr,0,size-1,key);
	return 0;
}
