#include<stdio.h>
int main(){

int seat_type,i,seats[10]={0};
int fclass,eco=6;
char name[20];  int sml=2;
printf("\tWELSOME TO PIA, THE DISASTROUS AIRLINE  ");
printf("%c\n\t",sml);
printf("Enter your name  ");
gets(name);
for(i=1;i<=11;i++){
	printf("\n\tEnter   1:For The First class\n\t\t2: For The Economy\n\t  ");
	scanf("%d",&seat_type);
	
	system("cls");
	
	if(seat_type==1){
		if(fclass>5){
			printf("First Class is Full, you can choose Economy for now\n\t");
		}
		seats[fclass]=1;
		printf("The Boarding Pass Of Firstclass\n\t");
		printf("The Traveler Name is:  ");
		puts(name);
		printf("The Seat No is: %d\n\t",fclass);
		printf("WE Donot Ensure Your Safety, Thank You For Choosing PIA\n\t");
		fclass++;
		
		
	}
	else if(seat_type==2){
		seats[eco]=6;
		if(eco>10 && fclass<=5){
			printf("Economy is Full, you can choose First class for now \n\t ");
		}
		printf("The Boarding Pass Of Economy\n\t");
		printf("The Traveler Name is:  ");
		puts(name);
		printf("The Seat No is: %d\n\t",eco);
		printf("WE Donot Ensure Your Safety, Thank You For Choosing PIA\n\t");
		eco++;
		
		
	}
	
	else if(fclass ==5 && eco == 10){
		printf("Both First class and Economy is Full,Wait Until The Next flight leaves in 3 hours.\n\t");
		}
	
	}

   
return 0;

}
