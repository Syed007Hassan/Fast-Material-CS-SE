#include<stdio.h>

struct student{
	char name[20];
	int rollno;
	int attendancemarks;
	int test1,test2,test3;
} s1,s2;

void func(struct student *s3);

void main(){
	
	struct student s1={"Hassan",1052,70,55,54,53};
	struct student s2={"Raza",1061,76,60,55,84};
	
	printf("The name is %s , roll no is %d , attendance is %d and marks are %d , %d and %d.\n",s1.name,s1.rollno,s1.attendancemarks,s1.test1,s1.test2,s1.test3);
	
	printf("The name is %s , roll no is %d , attendance is %d and marks are %d , %d and %d.\n",s2.name,s2.rollno,s2.attendancemarks,s2.test1,s2.test2,s2.test3);

     printf("The total marks of student 1 and 2 after incrementing are \n");

  func(&s1);
  
  func(&s2);
  

}
	void func(struct student *s3){
		int y;
         s3->test1 = s3->test1 + 3;
         s3->test2 = s3->test2 + 10;
         s3->test3 = s3->test3 + 8;
         
         
         y= s3->test1+s3->test2+s3->test3;
          printf(" %d ",y);
	}
	
	
