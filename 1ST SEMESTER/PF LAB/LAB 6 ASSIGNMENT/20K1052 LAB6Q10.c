#include <stdio.h>

int main()
{
	int i,j;
	
	for (i=1;i<=5;i++) 
	{
		
		for (j=1;j<=5-i;j++){
		
		
			printf(" ");
       }
		for(j=1;j<=2*i-1;j++){
		
		
			printf("*");
	}
		printf("\n");
		
	}
	
		for (i=1;i<=5;i++) 
	{
		
		for (j=1;j<=i;j++){
		
		
			printf(" ");
	}
		for(j=1;j<=2*(5-i)-1;j++){
		
		
			printf("*");
	}
		printf("\n");
		
	    
	}
	
	return 0;
	
}

	
	
 

