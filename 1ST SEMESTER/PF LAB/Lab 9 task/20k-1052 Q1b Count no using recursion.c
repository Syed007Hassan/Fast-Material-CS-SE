#include<stdio.h>
int count(int n){
	static int c;
	int x;
		if(n>0){
		count(n/10);
	    c++;
       }
       else
       {
       	return c;
	   }
	

	return c;	
		
}

int main(){
	int num,c;
	printf("Enter the no  ");
	scanf("%d",&num);
	
	printf("The no of digits in this number '%d' are %d ",num,count(num));
	
	return 0;
}
