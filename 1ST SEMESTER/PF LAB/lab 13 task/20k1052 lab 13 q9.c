#include<stdio.h>
struct student {
    char firstName[30];
    int age;
    int roll;
    char address[30];
} s1[10];

void func(struct student *s2 );
void func1(struct student *s2 );
void func2(struct student *s2 );

int main() {
    int i;
    struct student s1[10];
    for(i=0;i<2;i++){
    	printf("Enter the first name:  ");
    	getchar();
        gets(s1[i].firstName);
    	printf("Enter the age btw 11-14: ");
    	scanf("%d",&s1[i].age);
    	printf("Enter the address ");
    	scanf("%s",&s1[i].address);
    	printf("Enter the roll no ");
    	scanf("%d",&s1[i].roll);
    	printf("\n");
    }
    
    func(&s1[0]);
    
    func1(&s1[0]);
    
    func2(&s1[0]);
    
}
    
void func(struct student *s2 ){
	
	int i;
	
	printf("The students who have age equal to 14\n");
	for(i=0;i<2;i++){
		if(s2[i].age == 14){
		puts(s2[i].firstName);
		}
	}
	
	
}

void func1(struct student *s2 ){
	
	int i;
	
	printf("The students who have even roll no\n");
	for(i=0;i<2;i++){
		if(s2[i].roll %2 ==0){
		puts(s2[i].firstName);
		}
	}
	
	
}

void func2(struct student *s2 ){
	
	int i;
	
	printf("\tThe detail of each student is \n");
	for(i=0;i<2;i++){
			printf("\tNAME IS\t\t",puts(s2[i].firstName),"\n"); 
			printf("\tADDRESS IS %s\n",s2[i].address);
			printf("\tNAME IS %d\n",s2[i].roll);
			printf("\n");
		}
	}
	
	
