#include<stdio.h>

struct CUSTOMERS{
	char name[30];
	int rollno;
	float balance;
} s1[10];

void func(struct CUSTOMERS *s2);

int main(){
	struct CUSTOMERS s1[10];
	int i;
	
	for(i=0;i<2;i++){
		printf("Enter the name  ");
		getchar();
		gets(s1[i].name);
		printf("Enter the rollno  ");
		scanf("%d",&s1[i].rollno);
		printf("Enter the balance ");
		scanf("%f",&s1[i].balance);
		printf("\n");
	
	}
	
	func(&s1[0]);
}

void func(struct CUSTOMERS *s2){
  int i; char x[2][20];
  printf("The customers having less than 2000 balance are\n");
  for(i=0;i<2;i++){
  	if( s2[i].balance < 2000){
  		puts(s2[i].name);
	  }
  }
      for(i=0;i<2;i++){
       	if( s2[i].balance > 2000){
   		s2[i].balance = s2[i].balance + 1000;
   	//	x[i][20]=s2[i].name;
   	}
	  printf("the customer %s with incremented balance is now %.2f\n",x[i][20],s2[i].balance);
	   
   		
}
}
