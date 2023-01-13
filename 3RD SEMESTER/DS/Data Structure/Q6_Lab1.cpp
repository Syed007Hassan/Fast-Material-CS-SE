#include<iostream>

using namespace std;

class Animal
{
	string name;
	int noofLegs;
	
	public:
		Animal()
		{
			name="";
			noofLegs=0;
		}
		Animal(string name,int noofLegs)
		{
			this->name= name;
			this->noofLegs=noofLegs;
		}
		
		void setter(string name,int noofLegs)
		{
			this->name= name;
			this->noofLegs=noofLegs;
		}
		void display()
		{
			cout << "Name : "<<name<<endl;
			cout << "No of Legs : "<< noofLegs<<endl<<endl;
		}
		friend void SortFunction(Animal arr[]);
};
void SortFunction(Animal *p)
{
	Animal temp;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4;j++)
		{
			if(p[j].name[0]>p[j+1].name[0])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}		
}
int main()
{
	Animal *ptr;
	ptr= new Animal[5];
	ptr[0]=Animal("Monkey",2);
	ptr[1]=Animal("Lion",4);
	ptr[2]=Animal("Cow",4);
	ptr[3]=Animal("Goat",4);
	ptr[4]=Animal("Kangaroo",2);
	SortFunction(ptr); // function to sorf object in alphabetical order
	for(int i=0; i<5 ; i++)
	{
		ptr[i].display();
	}
}
