#include<iostream>
using namespace std;

class Student{
	private:
		int marks;
		
		public:
			
		Student(int i):marks(i){
		
		}
		
		bool operator==(Student s){
			
			if(marks == s.marks){
				return true;
			}
			else{
				return false;
			}
		}
		
		
		show(){
			cout<<"The marks are equal: "<<marks<<endl;
		}
		
};

int main(){
	
	Student a1(30);
	Student a2(30);
	
	if(a1==a2){
		
		cout<<a1.show()<<endl;
	}
	
	else{
		
		cout<<"Not equal"<<endl;
	}
}
