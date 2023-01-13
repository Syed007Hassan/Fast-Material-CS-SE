#include <iostream>
#include <fstream>
#include<string>
using namespace std;
 
 
class Count{
	
	public:
	
	void countlines(){

    fstream file;
	
	file.open("STORY.txt",ios::in);
	
   string str;
	
	int count=0;

	while(!file.eof())
	{
	   getline(file,str);
	  
		if(str[0]!='A'){
		
		   
			count++;
	}
			
	}
	cout<<"Number of lines not starting with A are "<<count;
	
	file.close();
}

/*	1. If the file "STORY.TXT" contains the following lines,
    2. The rose is red.
    3. A girl is playing there.
    4. There is a playground.
    5. An aeroplane is in the sky.
    6. Numbers are not allowed in the password.
    7. The function should display the output as 3.

    5 lines starting with not "A"

*/	
}; 

int main(){
	
	Count c;
	
	c.countlines();
	
}
