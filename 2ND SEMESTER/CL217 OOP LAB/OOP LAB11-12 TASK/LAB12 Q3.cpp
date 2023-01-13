#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class person {
	private:
		string name;
		int age;
	
	public:
		setdata(string n, int a){
			name=n;
			age=a;
		}

		getdata(){

			cout<< "\n Name = " << name;

			cout<< "\n Age = " << age;
		}

};

int main() {

	person person1;
	fstream file;
	file.open("person.bin", ios::out);
	person1.setdata("SYED HASSAN",20);
	file.write( ( char*) &person1, sizeof(person1));
	file.close();
	cout<< "\n Data Saved";
	
	cout<< "\n\n Reading data from file: ";
	file.open("person.bin", ios::in);
	file.read((char*) &person1, sizeof(person1));
	person1.getdata();
	cout<<"\n\n";
	file.close();

	return 0;
}
