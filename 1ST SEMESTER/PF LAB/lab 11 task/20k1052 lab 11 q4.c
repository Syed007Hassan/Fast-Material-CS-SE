#include<stdio.h>
#include<stdlib.h>

void main(){
	int *ptr,n;
	int i,max,sum;
	float avg;
	
		printf("Enter the no of marks");
	    scanf("%d",&n);
		
		if(( ptr =(int*)malloc(n*sizeof(int))) == NULL){
		   printf("Memory not allocated");
	}
	printf("Enter the marks \n");
	for(i=0;i<n;i++){
		scanf("%d",(ptr + i));
	}
	
	
	for(i=0;i<n;i++){
		
		sum= sum + *(ptr +i);
		if(*(ptr) < *(ptr +i)){
			
			max=*(ptr + i);
		}
		
	}
	
	avg=(float)sum/n;
	
	printf("the max mark is %d\n",max);
	printf("the avg of marks is %.2f ",avg);
	
		
}
	
