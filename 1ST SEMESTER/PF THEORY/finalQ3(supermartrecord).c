#include<stdio.h>
#include<stdlib.h>
struct customeraddress
{   
    
    char str_adr[20];
	char area[20];
	char city[20];
};

struct customerdetails
{
	int customerid;
	char customername[20];
	struct customeraddress address;
	
}details[1];
int main()
{	int i,n;
	FILE *fp;
	//struct customerdetails;
	fp=fopen("customer_details.txt","w");
	for(i=0;i<1;i++)
	{
	fflush(stdin);
	printf("enter the name of the customer: ");
	scanf("%s",&details[i].customername);
	fflush(stdin);
	printf("enter the ID of the customer: ");
	scanf("%d",&details[i].customerid);
	fflush(stdin);
	printf("Enter customer street address: ");
	scanf("%s",&details[i].address.city);
	
	
	fwrite(&details[i],sizeof(80),1,fp);
	fclose(fp);
	}
	getch();
}
