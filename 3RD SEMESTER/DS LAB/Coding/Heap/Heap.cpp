#include <iostream>
using namespace std;

void Insert(int H[], int n){
	int i=n, temp = H[i];
	
	while(i>1 && temp>H[i/2]){
		H[i]= H[i/2];
		i/=2;
	}
	H[i]= temp;
}

int Delete(int A[], int n){
	int i,j,x= A[n];
	int val = A[1];
	A[1]= A[n];
	A[n]= val;
	
	i=1; j=i*2;
	
	while(j<n-1){
		if(A[j+1]>A[j])
			j=j+1;
		if(A[i]<A[j]){
			int t = A[i];
			A[i]= A[j];
			A[j] = t;
			
			i=j;
			j=2*j;
		}
		else
			break;
	}
	return val;
}

int main(){
	int H[]={0,10,20,30,25,5,40,35};  
	
	for(int i=2; i<=7; i++){
		Insert(H,i);
	} 
	
	for(int i=1; i<=7; i++){
		cout << H[i] << " ";
	}
	cout << endl;
	for(int i=7; i>1; i--){
		Delete(H,i);
	}
	 
	for(int i=1; i<=7; i++){
		cout << H[i] << " ";
	}
	return 0;
}
