#include<iostream>
using namespace std;

class University{
	
	
};

class Departments:public University{
	
	
};

class Marks{
	
};
class Students:public Departments,Marks{
	
	
};

int main(){
	
	Students s1;
}
