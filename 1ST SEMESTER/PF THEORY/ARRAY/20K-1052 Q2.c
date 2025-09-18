#include<stdio.h>
int main()
{

int arr1[7],arr2[7],i,j;
	printf("Enter 7 Elements\n ");
	for (i=0;i<7;i++)
	{
		scanf("%d",&arr1[i]);
	}
	for (i= 0, j=6; i<7; i++, j--)
	{
		arr2[i] = arr1[j];
	}
	printf("\nArray after Copying in Reverse Order: ");
	for (i=0; i<7; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}
