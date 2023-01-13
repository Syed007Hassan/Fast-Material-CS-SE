#include<stdio.h>
#include<string.h>

int anagram_check( char *str1, char *str2);
int main()
{
	char str1[256],str2[256];
	printf("Enter the String:  ");
	gets(str1);
	printf("Enter another String:   ");
	gets(str2);
	
	if(anagram_check(str1,str1) == 1)
	{
		printf("%s And %s are ANAGRAM",str1,str2);
	}
	else
	{
		printf("%s And %s are not ANAGRAM",str1,str2);
	}
	return 0;
}

int anagram_check(char *str1, char *str2)
{
	
    int str1Ctr[256] = {0}, str2Ctr[256] = {0};
    int ctr;
    if(strlen(str1) != strlen(str2))
    {
        return 0;
    } 
    for(ctr = 0; str1[ctr] != '\0'; ctr++)
    {
        str1Ctr[str1[ctr]]++;
    } 
    for(ctr = 0; str2[ctr] != '\0'; ctr++)
    {
        str2Ctr[str2[ctr]]++;
    }
    for(ctr = 0; ctr < 256; ctr++)
    {
        if(str1Ctr[ctr] != str2Ctr[ctr])
            return 0;
    }
    return 1;
}
	
   
