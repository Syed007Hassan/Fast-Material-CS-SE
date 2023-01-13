#include<iostream>
using namespace std;

int main(){
	
	int r,c,r1,c1,value;
	
	int **a1,**a2;
	
	int **a3;


	
	cout<<"Enter the rows and columns for 2d-array 1: "<<endl;
	cin>>r>>c;
	
	a1 = new int*[r];
	
	for(int i=0;i<r;i++){
		
		a1[i]= new int[c];
	}
	
	
	cout<<"Enter the elements for 2d-array 1: "<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			
			cout<<i<<j<<" ";
			cin>>a1[i][j];
		}
	}
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			
			cout<<a1[i][j]<<endl;
			
		}
	}
	
	cout<<"Enter the rows and columns for 2d-array 2: "<<endl;
	cin>>r1>>c1;
	
		
	a2 = new int*[r1];
	
	for(int i=0;i<r1;i++){
		
		a2[i]= new int[c1];
	}
	
	
	cout<<"Enter the elements for 2d-array 2: "<<endl;
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			
			cout<<i<<j<<" ";
			cin>>a2[i][j];
		}
	}
	
		for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			
			cout<<a2[i][j]<<endl;
			
		}
	}
	
	int r2 = r;
	int c2 = c+c1+r1;
	
	 a3 = new int*[r2];
	
	for(int i=0;i<r2;i++){
		
		a3[i]= new int[c2];
	}
	
		for(int i=0;i<r2;i++){
		for(int j=0;j<c2;j++){
			
	
	        
			a3[i][j]= NULL;
			
		}
		
	}
	
	cout<<"Copying elements of a1 into a3: "<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			
	
	        value = a1[i][j]; 
			a3[i][j]= value;
			
		}
		
	}
	
	  	
		cout<<"Copying elements of a2 into a3: "<<endl;
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			
			value = a2[i][j];
			a3[r-1][c+j]= value;
			
		}
	}
	
	  	
		for(int i=0;i<r2;i++){
		for(int j=0;j<c2;j++){
		
			cout<<a3[i][j]<<endl;
		}
	}
	
	
	
	
	
	
}
