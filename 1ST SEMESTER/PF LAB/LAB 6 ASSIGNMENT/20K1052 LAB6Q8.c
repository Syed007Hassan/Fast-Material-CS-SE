#include <stdio.h>

int main()
{
	int i,j;
	
	for (i=1;i<=2;i++) 
	{
		printf(" ");
		printf(" ");
		printf(" ");
		
		for (j=1;j<=2-i;j++)
		{
		
		
			printf(" ");
	    }
		for(j=1;j<=2*i-1;j++)
		{
		
		
		    
			printf("%d",j);
        }
		printf("\n");
		
	    
	}
	
	
		for (i=1;i<=3;i++) 
	{
			printf(" ");
			printf(" ");

		
		
		
		for (j=1;j<=3-i;j++)
		
			printf(" ");
		
		for(j=1;j<=2*i-1;j++)
		
			printf("*");
		
		printf("\n");
		
	    
	}
	
	
		for (i=1;i<=4;i++) 
	{
			printf(" ");
		
		for (j=1;j<=4-i;j++)
		
			printf(" ");
		
		for(j=1;j<=2*i-1;j++)
		
			printf("*");
		
		printf("\n");
		
	    
	}
	
			for (i=1;i<=5;i++) 
	{
		
		for (j=1;j<=5-i;j++)
		
			printf(" ");
		
		for(j=1;j<=2*i-1;j++)
		
			printf("*");
		
		printf("\n");
		
	    
	}
	
	
	
	
	
	
	return 0;
	 
}
