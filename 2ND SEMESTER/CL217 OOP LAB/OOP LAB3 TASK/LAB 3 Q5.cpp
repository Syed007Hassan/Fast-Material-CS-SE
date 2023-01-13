#include <iostream>
#include <iomanip>

using namespace std;

class Book{
	public:
		string name;
		int ISBN;
		string aut_name;
		string pub_name;
		
		void getinfo()
		{
			cout << "\n\nEnter name of book: ";
			cin >> name;
			cout << "\nEnter ISBN: ";
			cin >> ISBN;
			cout << "\nEnter author name: ";
			cin >> aut_name;
			cout << "\nEnter publisher name: ";
			cin >> pub_name;
	}
		
		void BookTest()
		{
		cout << "\n\nName: ";
		cout << name;
		cout << "\nISBN: ";
		cout << ISBN;
		cout << "\nAuthor name: ";
		cout << aut_name;
		cout << "\nPublisher name: ";
		cout << pub_name;
	}
		
		
};


int main()
{
	Book user[3];
	int i,id;
	
	for(i=0;i<3;i++) {
		user[i].getinfo();
	}
	
	cout << "\n\nEnter ISBN number to search a book: ";
	cin >> id;
	for(i=0;i<3;i++) {
	if(id == user[i].ISBN ){
	
	user[i].BookTest();
	
    }
}
}
