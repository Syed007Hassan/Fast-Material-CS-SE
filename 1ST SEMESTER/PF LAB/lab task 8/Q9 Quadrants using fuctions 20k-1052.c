#include<stdio.h>
int main()
{
	int x,y;
	printf(" For 1st Quadrant X and Y both are +ve\n For 2nd Quadrant X is -ve and Y is +ve\n For 3rd Quadrant X and Y both are -ve\n For 4th Quadrant X is +ve and Y is -ve\n "); 
	printf("Enter the value of X and Y ");
	scanf("%d%d",&x,&y);
    quadrant(x,y);	
	return 0;

	}
	
	int quadrant(int j, int k)
	{
		if(j==0 && k==0)
		{
			printf(" The point lies in origin\n");
		}
		else if(j>0 && k>0)
		{
			printf(" The point lies in 1st origin\n");
		}
		else if(j<0 && k>0)
		{
			printf(" The point lies in 2nd Quadrant\n");
		}
		else if(j<0 && k<0)
		{
			printf(" The point lies in 3rd Quadrant\n");
		}
		else if(j>0 && k<0)
		{
			printf(" The point lies in 4th Quadrant\n");
		}
 return 0;
 }
	
	




