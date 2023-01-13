 #include<iostream>
using namespace std;

int main(){
	
	int num = 10;
	int *p = new int;
	*p = num;
	
	delete p;
	
	cout<<p<<endl;
	
	return 0;
}
