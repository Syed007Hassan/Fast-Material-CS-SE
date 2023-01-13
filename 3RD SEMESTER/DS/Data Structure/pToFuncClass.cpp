#include<iostream>

using namespace std;

class S
{
	
	public:
		int age;
		void display()
		{
			cout << "Hello World";
			cout << "\nAge : "<< age<<endl;
		}
};
int main()
{
	void (S::*pDisplay)()=&S::display;
	int (S::*pAge)=&S::age;
	
	S obj;
	S *pobj= new S;
	
	obj.*pAge=10;
	pobj->*pAge=20;
	
	(obj.*pDisplay)();
	(pobj->*pDisplay)();
	
	
}
