#include<stdio.h>
 void fibonacci_Series(int range)
{
   int w,x=0,y=1,z;
   for(w=1;w<=range;w++)
   {
     printf("%d, ", x);
     z = x+y;
     x = y;
     y = z;
   }
}

 int main()
 {
   int range;

   printf("Enter range: ");
   scanf("%d", &range);

   printf("The fibonacci series is: \n");

   fibonacci_Series(range);

   return 0;
 }
