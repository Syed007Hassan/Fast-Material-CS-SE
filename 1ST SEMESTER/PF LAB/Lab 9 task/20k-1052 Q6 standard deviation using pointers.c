#include <stdio.h>
#include <math.h>
int sd(int i,int *ptr){
	int sum;
	float stdev,avg;
	for(i=0;i<5;i++){
		
 	sum = sum + *(ptr + i);
  }
  printf("The sum is %d  \n",sum);
  avg=sum/5;
  printf("The Average is %.3f  \n",avg);
  
   for(i=0;i<5;i++){
   stdev= stdev + pow(*(i+ptr)-avg,2);
 }
 
   stdev=sqrt(stdev/5);
   printf("The standard deviation is %.3f ",stdev);
	
}


int  main()
{
 int arr[20],i,*ptr;
 printf("Enter the 5 elements:\n");
 ptr=&arr[0];
 for(i=0;i<5;i++){
 	scanf("%d",ptr); 
 	ptr++;
 }
sd(i,&arr);
 return 0;
}


























