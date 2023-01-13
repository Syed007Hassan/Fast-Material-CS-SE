#include<iostream>
#include<string>
using namespace std;

class binary{
	
	private:
	string s;
	
	public:
		void instring();
		void checkstr();
		void strrev();
	
};

void binary::instring(){
	
	cout<<"Enter the binary string ";
	cin>>s;
	
}

void binary::checkstr(){
	
for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary::strrev(){
	for(int i=0;i<s.length();i++){
		if(s[i]== '0'){
			s[i]='1';
		}
		else if(s[i]== '1'){
			s[i]='0';
		}
	 }
	 
	 cout<<"The string after reversing 0 and 1 is "<<s;
}

int main(){
	
	binary one;
	one.instring();
	one.checkstr();
	one.strrev();
	
	return 0;
}
