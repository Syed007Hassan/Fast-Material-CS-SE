#include<stdio.h>
int main()
{
int a[6][6],i,j;
int b[6][6];
int sum[6][6];


     for(i=0;i<6;i++)
    {
      for(j=0;j<6;j++)
       {
           printf("Enter number at %d row and %d column  ",i,j);
            scanf("%d",&a[i][j]);

    }
      printf("\n");
     
    }
     
       for (i=0; i<6;i++)
    {
        for (j=0; j<6;j++)
         {
           printf("%d   ",a[i][j]);
         }
           printf("\n");
    }
    
         for(i=0;i<6;i++)
    {
      for(j=0;j<6;j++)
       {
           printf("Enter number at %d row and %d column  ",i,j);
            scanf("%d",&b[i][j]);

    }
      printf("\n");
      
     
    }
     
       for (i=0; i<6;i++)
    {
        for (j=0; j<6;j++)
         {
           printf("%d   ",b[i][j]);
         }
           printf("\n");
           
    }
    
            printf("\n");
     
            
            for(i=0;i<6;i++)
            {
            	for(j=0;j<6;j++)
            	{
            		sum[i][j] =a[i][j] + b[i][j];
                    
					printf("%d   ",sum[i][j]);
				}
				printf("\n");
				
			}
            
        
return 0;  
     
  }

