#include<iostream>
using namespace std;

int main(){
	
	int r=7,c;
	
	int **arr = new int*[r];
	int *number = new int[c];
	
	cout<<"Enter the no row "<<endl;
	cin>>r;
	

	for(int i=0;i<r;i++){
		cout<<"Enter the no of columns for row "<<i<<": ";
		cin>>number[i];
		arr[i] = new int[number[i]];	
	}
	

	for(int i=0;i<r;i++){
		
		for(int j=0;j<number[i];j++){
		cout<<"arr["<<i<<"]["<<j<<"]: ";
		cin>>arr[i][j];
		}
		
	}
		
		
			for(int i=0;i<r;i++){
		for(int j=0;j<number[i];j++){
		cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	
	}
	
}
