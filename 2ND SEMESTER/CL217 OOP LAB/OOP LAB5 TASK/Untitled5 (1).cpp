#include <iostream>
using namespace std;

class data{
private:
	const string name;
	const int age;

public:
	data(string n, int a ):name(n),age(a){

		cout<<"\n\nName: "<<name;
		cout<<"\nAge: "<<age;
	}
};

int main(){
	string n;
	int a;

	cout<<"\nEnter your name: ";
	getline(cin,n);
	cout<<"\nEnter your age: ";
	cin>>a;

data p1(n,a);

}
