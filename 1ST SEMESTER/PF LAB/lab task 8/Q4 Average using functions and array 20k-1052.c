#include <stdio.h>

int avg(int arrr[])
{
	float c;
	c=((arrr[0]+arrr[1]+arrr[2]+arrr[3]+arrr[4]+arrr[5]+arrr[6]+arrr[7]+arrr[8]+arrr[9]+arrr[10]+arrr[11]+
	arrr[12]+arrr[13]+arrr[14]+arrr[15]+arrr[16]+arrr[17]+arrr[18]+arrr[19])/20);
	return c;
}

int main()
{
	int a; 
	int arr1[] = {67, 78, 89, 90, 78, 89, 90, 54, 76, 78, 81, 86, 66, 65, 80, 60, 90, 54, 55,77};
	int arr2[] = {67, 20, 89, 90, 78, 87, 67, 87, 65, 90, 95, 99, 71, 76, 88, 80, 85, 90,66, 66};
	int arr3[] = {67, 78, 89, 90, 78, 87, 90, 80, 90, 62, 55, 78, 87, 9, 87, 68, 67, 78, 79, 80}; 
	int arr4[] = {97, 80, 76, 90, 92, 45, 78, 87, 77, 88,76, 78, 81, 86, 66, 78, 71, 76, 88, 53};
	int arr5[] = {87, 88,76, 88, 78, 86, 66, 78, 71, 78, 87, 80, 89, 90, 78, 87, 67, 78, 81, 86};
	printf("The average marks of students in PF is: %d", avg(arr1));
	printf("\nThe average marks of students in Physics is: %d", avg(arr2));
	printf("\nThe average marks of students in ECC is: %d", avg(arr3));
	printf("\nThe average marks of students in Maths is: %d", avg(arr4));
	printf("\nThe average marks of students in Pakistan Studies is: %d", avg(arr5));
	return 0;
}
