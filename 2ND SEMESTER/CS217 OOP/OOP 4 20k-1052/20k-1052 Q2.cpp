#include<iostream>
using namespace std;

class Student{
	private:
		int marks;
		
		public:
			
		Student(int i):marks(i){
		
		}
		
		void operator+(int i){
			
			marks = marks + i;
		}
		
	
		show(){
			cout<<"The marks after increment are: "<<marks<<endl;
		}
		
};

int main(){
	Student a1(20);
	
	a1 + 20;
	
	a1.show();
	
	
}
