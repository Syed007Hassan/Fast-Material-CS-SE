#include <stdio.h>

int main()
{
    int i,no,sum;

    printf("ENTER THE NO TO CHECK WHETHER IT IS A PERFECT NO OR NOT: ");
    scanf("%d", &no);

    for(i=2; i<=no/2; i++)
    {
        if(no%i == 0)
        
       {   printf("%d + ",i);
           sum=sum+i;
       }
    }
    printf("SUM IS %d\n",sum);
    

    if(sum==no)
    {
        printf("%d is PERFECT NUMBER", no);
    }
    else
    {
        printf("%d is NOT PERFECT NUMBER", no);
    }

    return 0;
}
