#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Student
{
	int roll;
	char name[20];
	int age;
	float height;
	
	public:
	Student()
	{
	}
	
	Student(int a, char b[20], int c, float d )
	{
		roll = a;
		strcpy(name, b);
		age = c;
		height = d;
	}
	
	display()
	{
		cout<<roll<<endl<<name<<endl<<age<<endl<<height<<endl;
	}
	
	store()
	{
		
	ofstream o;
	o.open("C:/Users/basit/Desktop/student.txt", ios::app);
	if(o.is_open())
	{
		cout<<"File opened"<<endl;
		o.write((char*)this, sizeof(*this));
		o.close();	
	}
	
	else
	{
		cout<<"File didn't open"<<endl;
	}
		
	}
	
	read()
	{
	ifstream i;
	i.open("C:/Users/basit/Desktop/student.txt");

	while(!i.eof())
	{	
	//i.read((char*)this, sizeof(*this));
	if((i.read((char*)this, sizeof(*this))))
	{
		display();
	}
	
	else
	{
		break;
	}
	} 

	} 
		
};



int main()
{
	Student s1(1, "abc", 18, 5.4);
	
	Student s2(2, "xyz", 15, 4.8);
	
	Student s3(3, "abc", 16, 5.3);
	
//	s1.display();
//	s2.display();
//	s3.display();

	s1.store();
	s2.store();
	s3.store();

	Student s;
	s.read();
	
	Student s4(5,"asdasd", 67, 9.8);
	s4.store();
	
	s.read();
	
	return 1;
}
