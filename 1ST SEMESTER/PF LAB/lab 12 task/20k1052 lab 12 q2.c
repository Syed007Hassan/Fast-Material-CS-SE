#include<stdio.h>
FILE*fptr;
FILE*fptr2;
void input();
void output();
main()
{
	input();
	output();
}
void input()
{
	int num,i,n;
	fptr=fopen("input.txt","w");
	
	printf("ENTER NUMBER OF VALUES TO BE ENTER : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the value : ");
		scanf("%d",&num);
		fprintf(fptr,"%d\n",num);
	}
	fclose(fptr);
}
void output()
{
	int factorial=1,num,n,i;
	fptr=fopen("input.txt","r");
	fptr2=fopen("output.txt","w");
	
	while(fscanf(fptr,"%d\n",&num)!=EOF)
	{
		for(i=0;i<num;i++)
		{
			factorial=factorial*(num-i);
		}
		fprintf(fptr2,"%d\n",factorial);
	}
	
	fclose(fptr2);
	fclose(fptr);
}
