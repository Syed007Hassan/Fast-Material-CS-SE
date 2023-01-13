#include<iostream>
using namespace std;

class Student{
	private:
		int marks;
		
		public:
			
		Student(int i):marks(i){
		
		}
		
		Student operator*(Student s){
	
		return(marks*s.marks);
			
			
		}
		
		
		show(){
			cout<<"The marks after multiplication are: "<<marks<<endl;
		}
		
};

int main(){
	Student a1(20);
	Student a2(30);
	
   Student a3=a1*a2;
	
	a3.show();	
	
}
