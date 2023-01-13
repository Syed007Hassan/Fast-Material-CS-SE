#include<stdio.h>
int fact(int n)
{
	if(n!=0)
	{
	    return n*fact(n-1);
	}
	else
	{
		return 1;
	}
}


int main(){
	int num;
	printf("Enter the no ");
	scanf("%d",&num);
	printf("The factorial of number %d is %d",num,fact(num));
	
	return 0;
}
