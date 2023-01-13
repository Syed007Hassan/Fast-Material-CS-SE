# include<stdio.h>
int main()
{
	int x,y;
	
	printf("ENTER X  ");
	scanf("%d", &x);
	printf("ENTERED VALUE OF X IS: %d\n", x);
	
	printf("ENTER Y  ");
	scanf("%d", &y);
	printf("ENTERED VALUE OF Y IS: %d\n", y);
	
	if(x==y)
	{
	 printf("GIVEN NUMBERS ARE EQUAL\n");
    }
    else 
    {
     printf("GIVEN NUMBERS ARE NOT EQUAL\n");
	}
	
	if(x>y)
	{
	 printf("X IS GREATER THAN Y\n");	
	}
	else
	{
	 printf("Y is GREATER THAN X");	
	}
	return 0;

}
