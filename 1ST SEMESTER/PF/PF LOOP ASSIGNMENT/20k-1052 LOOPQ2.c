#include<stdio.h>
int main()

{  int no,i,j=1;
	int sum;
	printf("ENTER THE NO OF TERMS:  ");
	scanf("%d",&no);
	for (i=1;i<=no;i++)
	{ 
	 
	  sum=sum+j;
	  printf("%d + ",j);
	   j=(j*10)+1;
	  
	  
	}
	printf("\nTHE SUM OF THE SERIES IS:  %d",sum);
} 
