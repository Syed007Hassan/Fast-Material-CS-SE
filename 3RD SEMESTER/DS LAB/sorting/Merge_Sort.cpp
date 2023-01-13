#include<iostream>
using namespace std;



void Merge(int arr[],int l,int mid,int h){
	
	int i = l, j = mid+1, k = l;
	int B[100];
	
	while(i<=mid && j<=h){
		
		if(arr[i]<arr[j]){
			B[k++] = arr[i++];
		}
		else{
			B[k++] = arr[j++];
		}
	}
	
	
	for(;i<=mid;i++){
		B[k++] = arr[i];
	}
	
	for(;j<=h;j++){
		B[k++] = arr[j];
	}
	
	
	for(i=l;i<=h;i++){
		arr[i] = B[i];
	}
	
	
	
	
}


void Merge_Sort(int arr[],int n){
	
	int p,l,h,mid;
	
	for(p=2;p<=n;p=p*2){
	
		for(int i=0; i+p-1<=n; i=i+p){
			
			l = i;
			h = i+p-1;
			mid = (l+h)/2;
			Merge(arr,l,mid,h);
		}
			
	}
	
	if(p/2 < n){
		Merge(arr,0,p/2-1,n);
	}
	
	for(int i=0;i<n;i++){
	 	cout<<arr[i] <<" ";
	 }
		
	
}


int main(){
	
	int arr[] = {1,2,5,11,10,15,3,7,4,6,9};
	int n = sizeof(arr)/ sizeof(int);
	
    
    Merge_Sort(arr,n);
	
}

