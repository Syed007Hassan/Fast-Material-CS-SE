#include<iostream>
using namespace std;

class Ins{
	
	int no1;
	public:
		string name;
		string type;
		int price;
		
		Ins(int aa,string a,string b,int c):no1(aa),name(a),type(b),price(c){
			
		}
		
		virtual display(){
			cout<<no1<<endl;
			cout<<name<<endl;
			cout<<type<<endl;
			cout<<price<<endl;
		}
	
};

class Piano:public Ins{
	int no2;
	
	public:
			string name;
		string type;
		int price;
		Piano(int aa,string a,string b,int c,int aaa,string aaaa,string bb,int cc):no2(aa),name(a),type(b),price(c),
		Ins(aaa,aaaa,bb,cc){
			
		}
	 display(){
			cout<<no2<<endl;
			cout<<name<<endl;
			cout<<type<<endl;
			cout<<price<<endl;
		}
	
};

int main(){
	
	Piano a1(512,"cool","elecric",333,513,"Instruments","music",3333);
}
