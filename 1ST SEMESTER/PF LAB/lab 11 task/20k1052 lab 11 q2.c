#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int *ptr, n=5,i=4;
	float *ptr2;
	char *ptr3;
	
	if(( ptr =(int*)malloc(n*sizeof(int))) == NULL){
		printf("Memory not allocated");
	}
	else{
		printf("MEMO ALLOCATED FOR INT\n");
	}
//     ptr=&i;
//     printf("%d",*ptr);
	
	if(( ptr2 =(float*)malloc(n*sizeof(float))) == NULL){
		printf("Memory not allocated");
	}
	else{
		printf("MEMO ALLOCATED FOR FLOAT\n");
	}
	
	if(( ptr3 =(char*)malloc(n*sizeof(char))) == NULL){
		printf("Memory not allocated");
	}
	else{
		printf("MEMO ALLOCATED FOR CHAR\n");
	}
	
	
	

}
