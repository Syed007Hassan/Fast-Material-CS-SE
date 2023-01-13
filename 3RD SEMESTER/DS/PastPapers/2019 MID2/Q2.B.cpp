#include <iostream>
using namespace std;

int main(){
	
	int arr[]={1,2,3,4,5};
	int brr[]={2,4,6,8,9};
	
	int n1= sizeof(arr)/sizeof(arr[0]);
	int n2= sizeof(brr)/sizeof(brr[0]);
	
	int newarr[n1+n2];
	int k=0;
	for(int i=0; i<n1+n2; i++){
		if(i<n1){
			newarr[i]= arr[i];
		}
		else{
			newarr[i]= brr[k++];
		}
	}
	int n= n1+n2;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(newarr[j]> newarr[j+1]){
				int t= newarr[j];
				newarr[j]= newarr[j+1];
				newarr[j+1] = t;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		cout << newarr[i] << " ";
	}
	
	cout << endl << newarr[n/2];
	
	return 0;
}
