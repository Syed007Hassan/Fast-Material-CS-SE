// C++ implementation of Shell Sort
#include  <iostream>
using namespace std;


void  shellSort(int A[],int n) {
int gap,i,j,temp;

for(gap=n/2;gap>=1;gap/=2){

  for(i=gap;i<n;i++){
  	
  	
   temp=A[i];
   j=i-gap;
   
   
  while(j>=0 && A[j]>temp){

   A[j+gap]=A[j];
   j=j-gap;

   }

   A[j+gap]=temp;

  }
   }
}

 

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
 
int main()
{
   	int arr[] = { 1, 2, 5, 3, 7, 4, 8, 10, 6, 9 }, i;
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Array before sorting: \n";
    printArray(arr, n);
 
    shellSort(arr, n);
 
    cout << "\nArray after sorting: \n";
    printArray(arr, n);
 
    return 0;
}
