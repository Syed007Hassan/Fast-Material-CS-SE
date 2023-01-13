#include<stdio.h>
int main(){
	void *ptr;
	int i;
	float x;
	char a;
	
	ptr=&a;
	printf("Enter any character  ");	
	scanf("%c",ptr);
	printf("The character is %c and address is %d \n", *((char *)ptr),((char *)ptr));
	

    ptr=&i;
	printf("Enter any integer  ");
	scanf("%d",ptr);
	printf("The interger is %d and address is %d \n  \n", *((int *)ptr),((int *)ptr));
	
	ptr=&x;	
	printf("Enter any float no  ");
	scanf("%f",ptr);
	printf("The float no is %.2f and address is %d \n \n", *((float *)ptr),((float *)ptr));
	


	
	return 0;
}
