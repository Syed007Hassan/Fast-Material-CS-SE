#include<iostream>
using namespace std;

int main() {
	
	int n,x=0,y=0,max_sum,val=0;
//	cout<<"Enter n: ";
	cin>>n; 
	int r = n*(n+1)/2;
	int arr[n];
	
	int sum[r]={0};
	
	int arr2[r][n] ;
    
    for(int i=0;i<r;i++){
    	for(int j=0;j<n;j++){
    		arr2[i][j] = 0;
		}
	}
	
    for(int i=0;i<n;i++){
    	cin>>arr[i];
	}
	
	for(int i=0;i<n;i++){			
		for(int j=i;j<n;j++){						
			for(int k=i;k<=j;k++){								
	             arr2[x][y++] = arr[k];	              
	          	}
	          	y=0;
	          	++x;	          					
			}			
		}
	
	
	 for(int i=0;i<r;i++){
    	for(int j=0;j<n;j++){
  		
		  sum[i] = sum[i] + arr2[i][j];
		}
	}
	 
	 	
//	 for(int i=0;i<r;i++){         //just for printing purpose
//    	for(int j=0;j<n;j++){
//  		
//		  cout<<arr2[i][j]<<"  "; 
//		}
//		cout<<"sum: "<<sum[i];
//		cout<<endl;
//	}
	
	for(int i=0;i<r;i++) {
			if(sum[i]>max_sum) {
				max_sum=sum[i];
				val=i;
			}		
	}
	
//	cout << "\n\n\n Sub array is: ";
	for(int i=0;i<n;i++) {
		if(arr2[val][i]!='\0')
		cout << arr2[val][i] << " ";
	}
	
	cout << endl << endl<< max_sum;
		
	return 0;	
}
	

