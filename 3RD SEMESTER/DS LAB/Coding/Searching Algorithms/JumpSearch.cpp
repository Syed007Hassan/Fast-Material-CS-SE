#include <iostream>
#include <cmath>
using namespace std;

bool JumpSearch(int arr[], int l, int r, int size, int key){
	int n= sqrt(size);
	int pos=0;
	int next=l+n;
	int i=0;
	while(arr[next]<key){
		if(arr[pos]== key)
			return true;
		pos = next;
		next += n;	
		if(next>size){
			next-= n;
			pos -= n;
			break;
		}
	}
	for(int i=next; i>=pos; i--){
		if(arr[i]== key)
			return true;
	}
	return false;
}
int main(){
	int arr[]= {1,2,3,4,5,6,7,8,9,10};
	int size= sizeof(arr)/sizeof(arr[0]);
	int key=19;
	cout << JumpSearch(arr,0,size-1,size, key);
	return 0;
}
