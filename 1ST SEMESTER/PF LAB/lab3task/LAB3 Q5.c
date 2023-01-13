# include<stdio.h>

int main()

{
	int n1=40,n2=20;
	int sum,subt,multi,div,mod;
	
	sum=n1+n2;
	printf("The SUM of N1 and N2 IS: %d\n", sum);
	
	subt=(n1-n2);
	printf("Subtraction of N1 and N2 IS: %d\n", subt);
	
	multi=(n1*n2);
	printf("Multiplication of N1 and N2 is: %d\n", multi);
	
	div=(n1/n2);
	printf("Divison of N1 by N2 is: %d\n", div);
	
	mod=(n1%n2);
	printf("Modulus of N1 and N2 is: %d ", mod);
	
	return 0;
}
