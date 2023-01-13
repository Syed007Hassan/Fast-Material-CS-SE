#include <stdio.h>
#include <stdlib.h>
void func(void *ptr, int n);
int main()
{
	int i,n,a;
	float b;
	char ch;
	void *ptr;
	
	
	printf("\n\n Enter a character: ");
	scanf("%c", &ch);
	func(&ch, sizeof(char));
	
	
	printf("\n\nEnter an integers: ");
	scanf("%d", &a);
	func(&a, sizeof(int));
	
	printf("\n\n Enter a float value: ");
	scanf("%f", &b);
	func(&b, 1+sizeof(float));
	

}

void func(void *ptr, int n)
{
	if(n==sizeof(char))
	{

		printf("\n\nThe adress of character is: %d",((char *)ptr));
		printf("\n\nThe value of character is: %c", *((char *)ptr));
   }
	
    else if(n==sizeof(int))
	{
		
		printf("\n\nThe adress of interger is: %d", ((int *)ptr));
		printf("\n\nThe value of interger is: %d", *((int *)ptr));
		
	}
	else if(n==1+sizeof(float))
	{
	
		printf("\n\nThe adress of float is: %d", ((float *)ptr));
		printf("\n\nThe value of float is: %f", *((float *)ptr));
		
	}
}
