#include<stdio.h>

 
int main()
{
   int n, i, arr[100];
   int *ptr;
 
   ptr = &arr[0];
 
   printf("Enter the size of array: ");
   scanf("%d", &n);
 
   printf("\nEnter %d integers into array:\n", n);
   for (i = 0; i<n; i++)
  {
      scanf("%d", (ptr + i)); 
      
   }
 
   ptr = &arr[n-1];
 
   printf("\nElements of array in reverse order are:\n");
 
   for (i=n-1; i>=0;i--) {
      printf("\nElement %d is %d  ", i+1, *(ptr -i));
    
   }
 
 return 0;
}
