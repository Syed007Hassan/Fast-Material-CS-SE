#include <stdio.h>

struct Address
{
	int house_no;
	char street[10];
	char area[20];
	char city[20];
	char country[10];
};

struct EMPLOYEE
{
	char name[30];
	int ID;
	int salary;
	int age;
	char designation[20];
	struct Address ad;
} emp[10];

void func(struct EMPLOYEE *ep);
int main()
{
	struct EMPLOYEE emp[10];
	struct Address ad;
	int i, k=0;
	for(i=0;i<2;i++) {
	printf("\n\n\nEnter the details of Employee %d", k++);
	printf("\nEnter the name: ");
	gets(emp[i].name);
	printf("\nEnter the ID: ");
	scanf("%d", &emp[i].ID);
	printf("\nEnter the salary: ");
	scanf("%d", &emp[i].salary);
	printf("\n\nEnter age: ");
	scanf("%d", &emp[i].age);
	printf("\nEnter designation: ");
	getchar();
	gets(emp[i].designation);
	printf("\n\nEnter Adress Details.");
	printf("\nEnter house number: ");
	scanf("%d", &emp[i].ad.house_no);
	printf("\nEnter street: ");
	getchar();
	gets(emp[i].ad.street);
	printf("\nEnter area: ");
	getchar();
	gets(emp[i].ad.area);
	printf("\nEnter city: ");
	gets(emp[i].ad.city);
	printf("\nEnter country: ");
	gets(emp[i].ad.country);
	}
	k=0;
	for(i=0;i<2;i++)
	{
		printf("The size of structure employee is %d  \n",sizeof(struct EMPLOYEE));
		printf("\n\n\nThe details of Employee %d:", k++);
		printf("\nName: %s", emp[i].name);
		printf("\nID: %d", emp[i].ID);
		printf("\nSalary: %d", emp[i].salary);
	printf("\nage: %d", emp[i].age);
	printf("\nDesignation: %d", emp[i].designation);
	printf("\nAdress: %s %d %s %s %s", emp[i].ad.street, emp[i].ad.house_no, emp[i].ad.area, emp[i].ad.city, emp[i].ad.country);
	
	
	}
	
	func(&emp[0]);
	
	
}
void func(struct EMPLOYEE *ep){
	int i;
	float x,avg;
	for(i=0;i<2;i){
		x= ep[i].salary + x;
	}
	avg=(float)x/2;
	printf("The avergae Salaries of employee are %.2f ",avg);
}

