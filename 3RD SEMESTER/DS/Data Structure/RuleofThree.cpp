#include<iostream>

using namespace std;

class student
{
	int *age;
	char *name;
	
	public:
		student()
		{
			age = new int;
			name=NULL;
			
		}
		student(char *name,int ae)
		{
			this->age=new int;
			*age=ae;
			this->name=name;
		}
		void display()
		{
			cout << "Name : "<<name<<endl;
			cout << "Age : "<<*age<<endl; 
		}
		void input()
		{
			cout << "Enter name : ";
			char *tempname=new char[30];
			
			cin.getline(tempname,30);
			name=tempname;

			tempname=NULL;
			cout << "Age : ";
			cin>>*age;
		}
		student (const student &ob)
		{
			age = new int;
			*age=*ob.age;
			name=ob.name;
		}
		student& operator = (const student &ob)
		{
			if(this!=&ob)
			{
				delete age;
				age=NULL;
				age=new int;
				*age=*ob.age;
				name=ob.name;				
			}
			else 
			{
				return *this;
			}
		}
		~student()
		{

			if(age!=NULL)
			{
				delete age;
				
			}
			name=NULL;
			age=NULL;
			
		}
};
int main()
{
	student s1("Abdullah",19),s3 ;
	s1.display();
	student s2(s1);
	s2.display();
	s3=s2;
	s3.display();
	
}
