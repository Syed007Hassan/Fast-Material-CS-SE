#include<iostream>
using namespace std;

int swap(int *i,int *j){
	
	
	int temp = *i;
	*i= *j;
	*j= temp;
}

void bubble_sort(int data[],int n){
	
	bool again = true;

     for(int i = 0; i < n ; i++) {
     	int flag =0;
     
	  for(int j=0 ;j < n-1-i; j++){
	  
      
	   if ( data [ j ] > data [ j+1]) {

       swap ( data[ j ], data [ j+1 ] );
        flag = 1;
 }
 
}

  if(flag == 0){
  	break;
  }
 
 } 
 
   for(int x = 0;x<n;x++){
		
		cout<<data[x]<<" ";
	}
		
}
int main(){
	
	int arr[] = { 1, 2, 5, 3, 7, 4, 8, 10, 6, 9 };
	int n = 10;
	

	
	bubble_sort(arr,n);	
}
