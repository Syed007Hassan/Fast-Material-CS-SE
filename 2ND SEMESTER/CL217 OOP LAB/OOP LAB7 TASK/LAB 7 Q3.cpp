#include <iostream>
using namespace std;

class Student{
	public:
		string name;
		string cls;
		int rollno;
		
		Student(){
			cout<<"Enter the name: ";
			cin>>name;
			cout<<"Enter the class: ";
			cin>>cls;
			cout<<"Enter the roll no: ";
			cin>>rollno;
			
		}
};

class Marks: public Student{
	public:
		
		int markse;
		int marksm;
		int marksp;
		
		Marks(){
			cout<<"Enter marks of eng: ";
			cin>>markse;
				cout<<"Enter marks of maths: ";
			cin>>marksm;
				cout<<"Enter marks of physics: ";
			cin>>marksp;
			
		}
};

class Result: public Marks{
	public:
		int tt;
		Result(){
			
		//	cout<<"The student info is: "<<infostd()<<endl;
		infostd();
			cout<<"The total marks are "<<tmarks()<<endl;
			cout<<"The avg marks are "<<avgmarks()<<endl;
				
		}
		
		 infostd(){
			
			cout<<endl<<name<<endl<<cls<<endl<<rollno<<endl;
		}
		
		
		
	  int tmarks(){
			
			tt=markse+marksm+marksp;
				return tt;
			
		}
		
	  float avgmarks(){
	  	 float ttt;
	  	 ttt=(tt/3);
	  	 return ttt;
	  }
	  	
};

int main(){
	
	Result r1;

}
