#include<stdio.h>
#include<string.h>
void reverse_of_String(int j, char str1[] );
int main()
{
    char str[50];
    int leng,i,c;
    
    printf(" ENTER THE STRING TO BE REVERSED \n ");
    gets(str);
    reverse_of_String(i, str);
    
}

void reverse_of_String(int j, char str1[] )
{
	int length;
    length=strlen(str1);

    for(j=length-1; j>= 0; j--) 
	{	
    printf("%c ", str1[j]);
    }
    
       
}
