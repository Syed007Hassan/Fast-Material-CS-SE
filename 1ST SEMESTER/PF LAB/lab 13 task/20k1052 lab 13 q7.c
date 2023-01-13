#include<stdio.h>
#include<string.h>

struct DAY{
	int date;
	char month[20];
	int year;
} d1,d2;

void main(){
	
	struct DAY d1,d2;
		printf("Enter the date, month and year for day 1 \n");
		scanf("%d %s %d",&d1.date,&d1.month,&d1.year);
		
		printf("Enter the date, month and year for day 2 \n");
		scanf("%d %s %d",&d2.date,&d2.month,&d2.year);
   
           
     if( (d1.date == d2.date) && (d1.month == d2.month) || (d1.year == d2.year) ){
     	printf("BOTH DAYS ARE SAME\n");
	 }
	 
	 else{

	 printf("BOTH DAYS ARE not SAME\n");
}
       		
	
	}
