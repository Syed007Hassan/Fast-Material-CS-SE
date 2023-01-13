#include <iostream>
using namespace std;

bool TernarySearch(int a[], int l, int r, int key){
	if(r>=1){
		int oneThird= l+(r-l)/3;
		int twoThird= r-(r-l)/3;
		if(a[oneThird]==key){
			return true;
		}
		if(a[twoThird]==key){
			return true;
		}
		
		if(a[oneThird] > key)
			return TernarySearch(a, l, oneThird-1, key);
		else if(key>a[oneThird] && key<a[twoThird])
			return TernarySearch(a, oneThird+1, twoThird-1, key);
		else
			return TernarySearch(a, twoThird+1, r, key);
		return false;
	}
}

int main(){
	int arr[]= {1,2,3,4,5,6,7,8,9,10};
	int size= sizeof(arr)/sizeof(arr[0]);
	int key=11;
	cout << TernarySearch(arr,0,size-1,key);
	return 0;
}
