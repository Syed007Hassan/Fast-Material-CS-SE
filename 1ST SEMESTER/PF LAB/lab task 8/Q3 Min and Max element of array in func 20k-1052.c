#include<stdio.h>
int max(int *a, int n)
{    
    int i;
 	int large=a[0];
	for(i=1;i<n;i++)
	{
		if(*(a+i)>large)
			large=*(a+i);
    }
   return large;
}
int min(int *a, int n)
{
    int i;
	int small=a[0];
	for(i=1;i<n;i++)
	{
		if(*(a+i)<small)
			small=*(a+i);
	}
	
	return small;

}

int main()
{
	int a[50],i,n;
	printf("How many elements:");
	scanf("%d",&n);
	printf("Enter the Array:");
 
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	
	printf("The largest element is %d",max(&a,n));
	printf("\nThe smallest element is %d",min(&a,n));
 
	return 0;
}
