#include<stdio.h>
#include<math.h>
double square(float *a);
double cube(float *b);
double squareroot(float *c);

int main(){
	float no;
	printf("Enter the no to find square, cube and square root of it.   ");
	scanf("%f",&no);
	
	printf(" The square of no is %.2f\n The cube of no is %.2f\n The square root of no is %.2f ", square(&no) ,cube(&no) ,squareroot(&no) );
	
}
double square(float *a){
	float x;
    x=*a * *a;
	return x;

}

double cube(float *b){
	float y;
	y=*b * *b * *b;
	return y;

}

double squareroot(float *c){
	float z;
	z=sqrt(*c);
    
	return z;
	
}

