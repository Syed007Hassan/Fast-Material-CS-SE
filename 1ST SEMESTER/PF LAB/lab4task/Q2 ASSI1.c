#include <stdio.h>
 
int main()
{
	char ch;
  	
	printf("Enter any character :  ");
  	scanf("%c", &ch);
  
  	if (isalpha(ch))
  	{
  		printf("%c is an Alphabet\n", ch);  	
  	} 
  	else if (isdigit(ch))
  	{
  		printf("%c is a Digit\n", ch);  	
  	}
  	else
    	printf("%c is a Special Character\n", ch);
  
  	return 0;
}
