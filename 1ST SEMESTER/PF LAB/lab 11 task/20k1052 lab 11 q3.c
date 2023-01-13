#include<stdio.h>
#include<stdlib.h>

void main(){
	int *ptr,n;
	int i,max;
	
		printf("Enter the no of elements ");
	    scanf("%d",&n);
		
		if(( ptr =(int*)malloc(n*sizeof(int))) == NULL){
		   printf("Memory not allocated");
	}
	printf("Enter the elements btw the range of 1-50 \n");
	for(i=0;i<n;i++){
		scanf("%d",(ptr + i));
	}
	
	
	for(i=0;i<n;i++){
		
		if(*(ptr + i) < *(ptr +i +i)){
			
			max=*(ptr + i);
		}
		
	}
	
	printf("the max element is %d",max);
	
	
	
	
}
	
	
	
	

