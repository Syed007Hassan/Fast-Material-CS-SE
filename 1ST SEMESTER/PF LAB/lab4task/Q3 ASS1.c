# include<stdio.h>
int main()
{
	int age;

	printf("ENTER THE AGE:  ");
	scanf("%d", &age);
	printf("%d is the age\n", age);
	
	if( age <= 11)
	{   
	 printf("FARE IS RS 20\n");
    }
   else if(age > 11 || age < 65)
   { 
     printf("FARE IS RS 50\n");
   }
   else if(age >= 65)
   { 
    printf("FARE IS RS 30\n");
   }
   else 
   printf("AGE IS NOT CORRECT");
   
   return 0;
   
}
