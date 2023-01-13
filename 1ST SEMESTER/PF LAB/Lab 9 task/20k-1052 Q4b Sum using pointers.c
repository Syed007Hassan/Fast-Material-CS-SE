#include <stdio.h>
int sum(int *a, int *b);
 
int main()
{
   int x, y;
   
   printf("Pointer : Add two numbers using call by reference\n");    
 
   printf(" Input the first number : ");
   scanf("%d", &x);
   printf(" Input the second  number : ");
   scanf("%d", &y);   
   printf(" The sum of %d and %d  is %d\n\n", x, y, sum(&x,&y));
   return 0;
}
int sum(int *a, int *b){

   int add;
   add = *a + *b;
   return add;
}
