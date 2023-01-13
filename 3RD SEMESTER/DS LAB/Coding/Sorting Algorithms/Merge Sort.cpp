#include <iostream>
using namespace std;

void MergingLists(int A[], int l, int mid, int h){
	int i,j,k;
	i=l;
	j=mid+1;
	k=l;
	
	int B[h+1];
	while(i<=mid && j<=h){
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
	}
	for(; i<=mid; i++)
		B[k++]= A[i];
	for(; j<=h; j++)
		B[k++]= A[j];
	for(int i=l ;i<=h; i++)
		A[i]= B[i];
}

void MergeSort(int A[], int l, int h){
	if(l<h){
		int mid = (l+h)/2;
		MergeSort(A, l, mid);
		MergeSort(A, mid+1, h);
		MergingLists(A,l,mid,h);
	}
}

int SmallestElement(int A[], int n, int k){
	int min, i;
	for( i=0; i<k; i++){
		min = i;
		for(int j = i+1; j<n; j++){
			if(A[j] < A[min])
				min = j;
		}
		if(min!=i){
			swap(A[min],A[i]);
			min = i;
		}
			
		
//		for(int i=0; i<n; i++)
//			cout << A[i] << " ";
//			cout << endl << min << endl;
//		system("pause");
	}
	return A[min];
}

int main(){
	int A[]= {11,13,7,12,16,9,24,5,10,3};
	int n= 11;
//	MergeSort(A,0,n-1);
//	
	for(int i=0; i<n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
	
	cout << SmallestElement(A,n,3);
}
