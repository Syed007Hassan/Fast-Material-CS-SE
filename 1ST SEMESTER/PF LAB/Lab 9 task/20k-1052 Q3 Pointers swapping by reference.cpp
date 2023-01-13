#include<stdio.h>
void swap(int *x, int *y);

int main(){
	
	int a,b;
	a=12; b=3;
	printf("a is %d and b is %d before swapping\n",a,b);
	swap(&a,&b);
	
	printf("a is %d and b is %d after swapping\n",a,b);
	
	return 0;
}

void swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	
		
	
}






