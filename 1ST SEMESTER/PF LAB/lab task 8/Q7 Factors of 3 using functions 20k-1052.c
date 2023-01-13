#include<stdio.h>
void factors(int s, int e)
{
	int a;
	for(s;s<=e;s++)
	{
		if(s % 3 == 0)
		{
			printf("one of the factor of three is %d  \n",s);
			a++;
		}
	}
	printf("The total factors are %d ",a);
	
}
	

int main()
{
	int s,e,a;
	printf("Enter the starting value of range: ");
	scanf("%d",&s);
	printf("Enter the end value of range: ");
	scanf("%d",&e);
	
     factors(s,e);
	return 0;
}
