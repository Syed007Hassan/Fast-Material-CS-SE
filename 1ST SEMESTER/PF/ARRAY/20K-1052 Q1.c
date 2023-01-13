#include<stdio.h>
int main()
{
	int marks[10],sum,avg,i,max;
	for(i=1;i<=10;i++)
	{
		printf("Enter the no %d: ",i);
		scanf("%d", &marks[i]);
		printf(" Mark is: %d\n ",marks[i]);
		sum=sum+marks[i];
		
	}
	for(i=1;i<=10;i++){
		max=marks[0];
		if ( max < marks[i])
          max = marks[i];		
	
	}
	
	printf(" SUM IS %d ",sum);
	avg=sum/10;
	printf("\n  AVERAGE IS %d ",avg);
	printf("The highest marks are %d ",max);
	
	return 0;
}
