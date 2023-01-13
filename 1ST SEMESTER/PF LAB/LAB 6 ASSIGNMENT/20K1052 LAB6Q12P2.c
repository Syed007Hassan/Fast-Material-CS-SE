#include <stdio.h>
int main()
{
      int num,x;
      for (num=100; num>=85;num--)
      {
           printf("VARIABLE: %d\n", num);
           if (num==85)
           {
               break;
           }
      }

	 printf("OUT OF FOR LOOP");
     return 0;
}
