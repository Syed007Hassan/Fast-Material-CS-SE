# include<stdio.h>
int main()
{ 
    int amount,notdn;
    printf("Enter the amount");
    scanf("%d", &amount);
    printf("The entered amount is: %d\n", amount);
	if(amount < 999)
	{
		if(amount % 20==0)
		{
			printf("The amount is divisible by 20\n");
		    notdn=amount/20;
		    printf("The no of 20 dollar notes are: %d\n", notdn);
		}
		else 
		{
			printf("Enter multiple of 20 only\n");
		}
			
	}
	else
	{
		printf("Amount entered is not in range");
	}
    

    return 0;
       
}
