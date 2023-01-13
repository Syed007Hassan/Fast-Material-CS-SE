#include<iostream>
#include<string>
using namespace std;


class Books{
	public:
		string name[2];
		string pname[2];
		string isbn[2];
		string genre[2];

};

class B1:public Books{
	
	public:
		
	B1(){
	
	cout<<"Enter the genre of the book: ";
	getline(cin,genre[0]);
	
	cout<<"Enter the Book name: ";
	getline(cin,name[0]);
	
	cout<<"Enter the publisher name: ";
	getline(cin,pname[0]);
	

	cout<<"Enter the isbn no: ";
	getline(cin,isbn[0]);
	
	cout<<endl;
 }
	
};

class B2: public Books{
	
	public:
		
		B2(){
			
	cout<<"Enter the genre of the book: ";
	getline(cin,genre[1]);
	
	cout<<"Enter the Book name: ";
	getline(cin,name[1]);
	
	cout<<"Enter the publisher name: ";
	getline(cin,pname[1]);
	

	cout<<"Enter the isbn no: ";
	getline(cin,isbn[1]);
	
	cout<<endl;
	
	}
		
};

int main(){
	
	B1 b;
	B2 a;
	int i;

	cout<<"The genre of the Book "<<i++<<" is:"<<b.genre[0]<<endl;
	cout<<"The name of the Book is: "<<b.name[0]<<endl;
	cout<<"The publisher name is: "<<b.pname[0]<<endl;
	cout<<"The isbn no of the book is: "<<b.isbn[0]<<endl<<endl;
	
		cout<<"The genre of the Book "<<i<<" is:"<<a.genre[1]<<endl;
	cout<<"The name of the Book is: "<<a.name[1]<<endl;
	cout<<"The publisher name is: "<<a.pname[1]<<endl;
	cout<<"The isbn no of the book is: "<<a.isbn[1]<<endl<<endl;

}
