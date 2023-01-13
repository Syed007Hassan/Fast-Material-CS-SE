#include<stdio.h>
int main()
{
int num,sum=0;

do
{
printf("Enter the no: ");
scanf("%d", &num);
sum=sum+num;

   printf("SUM IS %d\n", sum);

}

while(num!=0);




return 0;

}
