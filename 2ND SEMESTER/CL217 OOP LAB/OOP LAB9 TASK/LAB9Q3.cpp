#include <iostream>
using namespace std;

class Perimeter;

class Printclass{
	int l,b;
	public:
		
   void peri(Perimeter &);
};

class Perimeter{
	int len,bre;
	
	public:
		Perimeter(int a,int b):len(a),bre(b){
			cout<<"LENGTH: "<<len<<endl<<endl;
			cout<<"BREATH: "<<bre<<endl<<endl;
		}
		
		
		
		friend class Printclass;
};


void Printclass::peri(Perimeter &a){
		l = l + a.len*2;
		b = b + a.bre*2;
		
		cout<<"The perimeter of object Rectangle is 2(L+B): "<<l+b<<endl;
	}


int main(){
	
	Printclass c;
	Perimeter p(10,9);

	
	c.peri(p);
}
