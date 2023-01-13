#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *ptr, *fptr;
	int i=0;
	char ch;
	fptr=fopen("alpha.txt","w");
	if((ptr=fopen("input.txt","r"))==NULL)
	{
		puts("cannot open file");
	}
	else {
		while(!feof(ptr))
		{
			ch=fgetc(ptr);
			if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
			{
				i++;
			}
		}
	}
	fprintf(fptr, "Their are %d vowels in the read file.", i);
	fclose(ptr);
	fclose(fptr);
	return 0;
}
