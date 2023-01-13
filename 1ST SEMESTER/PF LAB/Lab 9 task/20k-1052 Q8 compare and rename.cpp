#include<stdio.h>
int (*fp_comp)(int a, int b);
int compare(int a,int b);
int main(){
	int a,b,r;
	printf("Enter a: ");
	scanf("%d",&a);
		printf("Enter b: ");
		scanf("%d",&b);
	fp_comp=&compare;
	r=(*fp_comp)(a,b);
	printf("%d ",compare(a,b));
	
}
int compare(int a,int b)
{
	if(a>b){
		printf("a>b");
		return 1;	
	}

	else if(a<b)
	{
		printf("a<b");
		return -1;
	}
	else
	printf("a=b");
	return 0;
}
