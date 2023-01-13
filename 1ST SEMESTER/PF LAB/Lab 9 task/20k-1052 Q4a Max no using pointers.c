#include <stdio.h>
int max(int *a, int *b);
 
int main()
{
   int x, y;
     
 
   printf(" Enter the two numbers ");
   scanf("%d  %d", &x,&y);
   printf(" The maximum no btw %d and %d  is %d\n\n", x, y, max(&x,&y));
   return 0;
}
int max(int *a, int *b){
    
    int high;
   if(*a>*b){
   	high=*a;
   	return high;
   }
   else
   {
   	high=*b;
   	return high;
   }
  
   
}
