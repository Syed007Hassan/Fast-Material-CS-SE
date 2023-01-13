#include <iostream>
using namespace std;

class Msg
{
	private:
		string name;
	public:
		string name2;
		Msg(){
			cout<<"Hello peoples!"<<endl;
		}
		Msg(string b){
			name=b;
			cout<<name<<endl;
		}
		print(){
			cout<<"Hello world!"<<endl;;}
		print(string a){
			name2=a;
			cout<<name2<<endl;
			
		}};
int main(){
	string a,b;
	Msg m;
	cout<<"Enter a string:"<<endl;
	cin>>a;
	Msg m1(a);
	m.print();
	cout<<"Enter a string:"<<endl;
	cin>>b;
	m.print(b);
}
