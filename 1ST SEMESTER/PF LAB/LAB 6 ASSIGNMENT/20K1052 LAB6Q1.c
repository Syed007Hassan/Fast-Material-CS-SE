#include<stdio.h>
int main()
{
int x,y;
printf("ENTER THE STARTINMG NO: ");
scanf("%d", &x);
printf("ENTER THE LAST NO: ");
scanf("%d", &y);


do
{
if(x%5==0)
{
printf("%d\n",x);
}

x++;

}
while(x<=y);


return 0;
}

