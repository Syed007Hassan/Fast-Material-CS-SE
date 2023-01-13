#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	char *c="Abdullah";	
	char *b="aftab";
	int length1=strlen(c);
	int length2=strlen(b);
	
	char *temp=new char[length1+length2];
	
	for(int i=0;i<length1;i++)
	{
		temp[i]=c[i];
	}
	for(int i=length1,j=0;j<length2;i++,j++)
	{
		temp[i]=b[j];
	}
	
//	delete[]c;
//	delete[]b;
	c=temp;
	temp=b=NULL;
	cout << c;
	
	
	
	
	
}
