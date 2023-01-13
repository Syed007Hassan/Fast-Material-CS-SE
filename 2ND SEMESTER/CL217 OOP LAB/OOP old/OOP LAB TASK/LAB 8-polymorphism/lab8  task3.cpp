#include <iostream>
using namespace std;

class shape
{
	public:
		int length;
		int breadth,ar;
	shape(int a ,int b ){
		length =a;
		breadth=b;
		}
	area(){
		ar=length*breadth;
	}
	};
class rec:public shape{
	public:
	rec(int a,int b) : shape(a,b){}
	area(){
		ar=length*breadth;
		cout<<endl<<"\nArea of a rectangle is "<<ar;
	}	
	
};
class sq:public shape{
	public:
	sq(int a,int b): shape(a,b){
		}
		area(){
		ar=length*breadth;
		cout<<endl<<"\nArea of a Square is "<<ar;
	}	
};

int main(){
	int a,b;
	char ch;
	do{
	cout<<endl<<"Do you want to calculate area of a square or area of a rectangle"<<endl<<"Press r for rectangle\nPress s for square\nPress q for quit "<<endl;
	cin>>ch;
	switch(ch){
		case 'r':
			{
				cout<<"Enter length and breadth for reactangle respectively:";
				cin>>a>>b;
				rec r(a,b);
				r.area();
			}break;
		case 's':
			{
				do{
				cout<<"Enter length of sides of square"<<endl<<"Side 1:";
				cin>>a;
				cout<<"\nSide 2";
				cin>>b;
			}while(a != b);
				sq s(a,b);
				s.area();
			}break;
	}
	}while(ch != 'q');
}
