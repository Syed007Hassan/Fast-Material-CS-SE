#include<stdio.h>
int main()
{
	int r[]={9,11,33,22,5,},i,j,k=0;
 
	int r3[11];
	int r2[]={0,7,4,3,2};
	printf("\n\n");
	for(i=0;i<10;i++)
	{
	if(i>5)
	{
		r3[i]=r2[k];
		k++;
	}
	r3[i]=r[i];
}
for (i=0;i<11;i++)
{
printf("%d  ",r3[i]); 
}}
