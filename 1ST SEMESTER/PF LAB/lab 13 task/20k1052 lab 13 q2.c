#include<stdio.h>

struct time{
	
	float s1;
	float e1;
	float elapsed;
} elp;

void main(){
	struct time elp;
	
	printf("enter the starting time of the race in minutes    ");
    scanf("%f",&elp.s1);
    
    printf("enter the ending time of the race in minutes    ");
    scanf("%f",&elp.e1);
    
    elp.elapsed= elp.e1 - elp.s1;
    
    printf("The elapsed time of the race in minutes is %.2f ",elp.elapsed);
    
}
