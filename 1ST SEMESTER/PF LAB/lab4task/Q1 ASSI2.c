# include<stdio.h>

int main()
{

int nots,t_shirt=500,tpots;
int nofs,formal_shirt=1000,tpofs;
int noww,wrist_watch=500,tpoww;
int dis, total_number,customer_provided,change;
float total_amount,dis_amount;

printf("No of T-shirts  ");
scanf("%d", &nots);

tpots=nots*t_shirt;

printf("Total price of T-Shirt, %d\n", tpots);


printf("No of Formal Shirts  ");
scanf("%d", &nofs);

tpofs=nofs*formal_shirt;

printf("Total price of Formal Shirt, %d\n", tpofs);


printf("No of Wrist Watch  ");
scanf("%d", &noww);

tpoww=noww*wrist_watch;

printf("Total price of Wrist Watch, %d\n", tpoww);

total_number=nots+nofs+noww;

printf("Total No of Items %d\n", total_number);


total_amount=tpots+tpofs+tpoww;

printf("Total amount is: %f\n", total_amount);

printf("Customer Provided  ");

scanf("%d", &customer_provided);

printf("%d Customer Provided\n", customer_provided);

if(total_amount > 3000)
{

dis=10;

dis_amount=(total_amount)-total_amount*dis/100;

printf("The discounted amount is: %f\n", dis_amount );

change=customer_provided-dis_amount;

printf("Customer Receice: %d", change);
}

else
{

change=customer_provided-total_amount;

printf("Change %d", change);
}

return 0;


}






