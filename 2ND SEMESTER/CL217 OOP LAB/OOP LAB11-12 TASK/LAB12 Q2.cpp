#include <iostream>
#include <fstream>
#include<string>
using namespace std;
 
int main()
{
    string line;
   
    fstream file("original.txt", ios::in);
    fstream temp("copy.txt", ios::out);
 
    if(file && temp){
 
        while(getline(file, line)){
            
			temp << line << "\n";
        }
 
        cout << "String copied!! \n\n";
        }
		 
	 else 
	 {
	 	cout<<"String not copied!! \n\n";
     }
 
    file.close();
    temp.close();
 
    return 0;
}
