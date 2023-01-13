#include<stdio.h>
#include<math.h>

struct Area{
	float l;
} square;

struct Volume{
	float l;
} cube;

struct circumference{
	float r;
} circle;

struct hypotenuse{
	float perp;
	float base;
} triangle;

void func1(struct Area square);
void func2(struct Volume cube);
void func3(struct circumference circle);
void func4(struct hypotenuse triangle);


int main(){

  struct Area square;
  func1(square);
  
  struct Volume cube;
  func2(cube);

  struct circumference circle;
  func3(circle);
  
  struct hypotenuse triangle;
  func4(triangle);
}


void func1(struct Area square){
	
	float x;
	printf("Enter the length for the square ");
	scanf("%f",&square.l);
	
	x= square.l * square.l;
	printf("The Area of square is %.2f   \n",x);
}


void func2(struct Volume cube){
	
	float y;
	printf("Enter the length for the cube ");
	scanf("%f",&cube.l);
	
	y= cube.l * cube.l * cube.l;
	printf("The Volume of Cube is %.2f   \n",y);
}

void func3(struct circumference circle){
	
	float y;
	printf("Enter the radius of circle ");
	scanf("%f",&circle.r);
	
	y= 2*3.142*circle.r;
	printf("The Circumference of Circle is %.2f   \n",y);
}

void func4(struct hypotenuse triangle){
	
	float x,y;
	printf("Enter the base and perpendicular of triangle  ");
	scanf("%f %f ",&triangle.base,&triangle.perp);
	
	x = (triangle.base*triangle.base) + (triangle.perp*triangle.perp);
	y=sqrt(x);
	
	printf("The hypotenuse of triangle is %.2f ",y);

}





















