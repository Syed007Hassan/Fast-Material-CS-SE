#include<iostream>
using namespace std;

class Student{
	private:
		int marks;
		
		public:
			
		friend Student operator*(Student,Student);
		friend Student operator/(Student,Student);
		friend bool operator>(Student,Student);
			
		Student(int i):marks(i){
		
		}
		

		show(){
			cout<<" a1*a2 marks are: "<<marks<<endl;
		}
		
		showw(){
			cout<<" a2/a3 marks are: "<<marks<<endl;
		}
		
};

	Student operator*(Student a1,Student a2){
		return Student(a1.marks*a2.marks);
			
		}
		
		Student operator/(Student a2,Student a3){
			return Student(a2.marks/a3.marks);
		}
		
		bool operator >(Student a4, Student a5){
			if(a4.marks > a5.marks){
				return true;
			}
			else{
				return false;
			}
		}

int main(){
	Student a1(2);
	
		Student a2(20);
		Student a3(5);
	
  Student a4=a1*a2;
	
	a4.show();	
	
	Student a5=a2/a3;
	
	a5.showw();
	
	if(a4 > a5){
		cout<<" (a1*a2) > (a2/a3) is TRUE ";
		
	}
	else{
		cout<<" (a1*a2) > (a2/a3) is False ";
	}
}
