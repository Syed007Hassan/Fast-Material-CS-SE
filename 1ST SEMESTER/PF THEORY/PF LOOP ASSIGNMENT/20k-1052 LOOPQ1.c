#include<stdio.h>
void pattern(int i, int j)
{
	int k=1;
	
	for(i=1;i<=3;i++)
	{
		printf(" ");
		for(j=1;j<=3-i;j++){
			printf(" ");
		}
		
			for(j=1;j<=2*i-1;j++){
			printf("%d",k);
			k++;
		}
	printf("\n");
}
	
	k=9;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=i;j++){
			printf(" ");
		}
		
			for(j=1;j<=2*(4-i)-1;j++){
			printf("%d",k);
			k--;
		}
	printf("\n");
	
	
	}	
}

int main(){
	int a,b;
	pattern(a,b);
	
	return 0;
}
