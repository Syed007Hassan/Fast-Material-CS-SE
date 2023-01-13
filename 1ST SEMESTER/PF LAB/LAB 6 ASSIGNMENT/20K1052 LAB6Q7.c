#include<stdio.h>
int main() 
{
	int i,j,x,y=1;
	
	for (i=5; i>=1; i--) 
	{
		for (x=y; x>=0; x--) 
		{
			printf(" ");
			
		}
		for (j=i; j>=1; j--) 
		{
			printf("*");
		}
		y++;
		printf("\n");
	}

return 0;

}
