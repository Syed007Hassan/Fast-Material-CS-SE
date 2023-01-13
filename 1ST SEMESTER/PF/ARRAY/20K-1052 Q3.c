
#include<stdio.h>
int main()
{
	int i,j;
	int a[3][3];
	int max=a[0][0];
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter number at %d row and %d column  ",i,j);
			scanf("%d",&a[i][j]);
		}
		
		printf("\n");
	}
	
	
		for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d      ",a[i][j]);
		
		}
		
		printf("\n");
	} 
	
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++) 
     {
           if(max<a[i][j])      
                max=a[i][j];        
     }
}
       printf("\nThe largest number in matrix is: %d",max);
	
	

return 0;
}
