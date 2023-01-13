#include<iostream>
#include<string.h>

using namespace std;

bool recursive(char *p,int start,int end);
int main()
{
	char array[10];
	int length;
	cout << "Enter string : ";
	cin.getline(array,10);
	length=strlen(array);
	cout << "length : "<<length <<endl;
	int lastindex=length-1;
	if(recursive(array,0,lastindex))
	{
		cout << array << " is palindrome";
	}
	else
	{
		cout << array << " is not palindrome";
	}

}
bool recursive(char *p,int start,int end)
{
	if(start<end)
	{
		if(p[start]==p[end])
		{
			recursive(p,start+1,end-1);	
			
		}
		else
		{
			return false;
		}
	}
	
	
}
