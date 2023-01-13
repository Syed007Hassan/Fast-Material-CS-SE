#include<iostream>
#include<fstream>
#include<string>


using namespace std;

int main()
{
	
	ifstream i;
	ofstream o;
	fstream f;
	
	i.open("C:/Users/basit/Desktop/file.txt");
//	o.open("C:/Users/basit/Desktop/file1.txt")
	
	char ch = ' ';
	string line;
	
	if(i.is_open())
	{
		cout<<"File opened"<<endl;
		
		while(!i.eof())
		{
//			cout<<ch<<endl;
//			i.get(ch);
			
			//i.get(ch);

			getline(i, line);
			cout<<line;
		
		}
		i.close();

	}
	else
	{
		cout<<"File didn't open"<<endl;
	}
	
	return 0;
}
