#include<iostream>
using namespace std;

class Student{
	private:
		int marks;
		
		public:
			
		Student(int i):marks(i){
		
		}
		
		bool operator<(Student s){
			
			if(marks < s.marks){
				return true;
			}
			else{
				return false;
			}
		}
		
		
		show(){
			cout<<"The marks are: "<<marks<<endl;
		}
		
};

int main(){
	
	Student a1(20);
	Student a2(30);
	
	if(a1<a2){
		
		cout<<"S2 is greater"<<endl;
	}
	
	else{
		
		cout<<"S1 is greater"<<endl;
	}
}
