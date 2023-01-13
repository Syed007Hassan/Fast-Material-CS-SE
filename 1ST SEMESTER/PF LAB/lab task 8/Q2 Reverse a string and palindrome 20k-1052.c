void reverse_of_String(int leng, int i, char str[] );
int main()
{
    char str[50];
    int leng,i,c;
    
    printf(" ENTER THE STRING TO BE REVERSED \n ");
    scanf("%s",&str);
    reverse_of_String(leng, i, str);
    
}

void reverse_of_String(int leng, int i, char str[] )
{
    int c;
    leng=strlen(str);

    for(i=leng-1; i>= 0; i--) 
	{	
    printf("%c ", str[i]);
    }
     for(i=0;i<leng/2;i++)  
    {
    	if(str[i]==str[leng-i-1])
    	c++;
 
 	}
 	if(c==i)
 	    printf("string is palindrome");
    else
        printf("string is not palindrome");
    return 0;
       
}
