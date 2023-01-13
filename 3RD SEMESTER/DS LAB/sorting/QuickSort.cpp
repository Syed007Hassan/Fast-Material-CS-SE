#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}

int partition(int A[],int l,int h){
	
   int pivot=A[l];
   int i=l,j=h;

   do{
   	
   do{i++;}while(A[i]<=pivot);

   do{j--;}while(A[j]>pivot);

   if(i<j) swap(&A[i],&A[j]);

   } 
     while(i<j);
  
    swap(&A[l],&A[j]);

    return j;
}

//void QuickSort(int A[],int l,int h){
//	
//   int j;
//
//   if(l<h){
//   	
//   	
//   j=partition(A,l,h);
//   
//   QuickSort(A,l,j);
//
//   QuickSort(A,j+1,h);
//
//  }
//
//}


void print(int arr[],int n){
		 
	 for(int i=0;i<n;i++){
	 	cout<<arr[i] <<" ";
	 }
}
 	

int partittion(int arr[],int l,int h){
	
	int pivot = arr[l];
	
	int i =l;
	int j =h;
	
	
	do{
	
	do{i++;} while(arr[i]<pivot);
	do{j--;} while(arr[j]>pivot);	
	
	if(i<j) swap(&arr[i],&arr[j]);
 		
	} while(i<j);
	
	swap(&arr[l],&arr[h]);
	
	return j;
	
}


void Quick_Sort(int arr[],int l,int h){
	
	int j;
	if(l < h){
		
	
	j = partition(arr,l,h);
	
	Quick_Sort(arr,l,j);
	Quick_Sort(arr,j+1,h);
		
		
	}
			
}



int main()
{
int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
Quick_Sort(A,0,n);
	print(A,n); 
return 0;
}
