#include <stdio.h>
int main()
{
	int i,j,k,l=1;

	for (i=1; i<=5; i++) 
	{
		for (j=5; j>=i; j--) 
		{
			printf(" ");
		}
		for (k=1; k<=i; k++) 
		{
			printf("*");
		
		}
		printf("\n");
	}
	return 0;
	
}
