#include<stdio.h>
#include<stdlib.h>

void main(){
	
	char *ptr;
	
	      if(( ptr =(char*)malloc(50*sizeof(char))) == NULL){
		   printf("Memory not allocated");
	}
	
	
  printf("Enter the array ");
  gets(ptr);
  printf("The entered string is\n\t");
  puts(ptr);
  
  free(ptr);
  
 
  
}
