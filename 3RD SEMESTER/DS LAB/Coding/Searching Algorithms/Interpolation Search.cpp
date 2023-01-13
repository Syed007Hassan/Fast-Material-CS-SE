#include <iostream>
using namespace std;

bool InterpolationSearch(int a[], int l, int r, int key){
	while( (l<=r) && (a[l]<=key) && (a[r]>=key)){
		if(l==r){
			if(a[l]==key)
				return true;
			return false;
			
		}
		int pos = l+ (r-l)/(a[r]-a[l])*(key-a[l]);
		if(a[pos]==key)
			return true;
		else if(a[pos]<key)
			l= pos+1;
		else
			r=pos-1;
	}
	return false;
}

int main(){
	int arr[]= {1,3,5,7,9,11};
	int size= sizeof(arr)/sizeof(arr[0]);
	int key=7;
	cout << InterpolationSearch(arr,0,size-1,key);
	return 0;
}
