#include<bits/stdc++.h>

using namespace std;

void getNumber(string line)
{
	for(int i=0; ; i++)
	{
		if(line[i]==' ')
		{
			break;
		}
		cout<<line[i];
	}
	cout<<" ";
}
int main()
{
	int n;
	cin >> n;
	
	string term[n];
	for(int i=0;i<n;i++)
	{
		fflush(stdin);
		getline(cin,term[i]);
	}
	int m;
	cin >> m;
	string text[m];
	
	for(int i=0;i<m;i++)
	{
		fflush(stdin);
		getline(cin,text[i]);
	}
	string temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(term[j]>term[j+1])
			{
				temp=term[j];
				term[j]=term[j+1];
				term[j+1]=temp;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<term[i]<<" ";
		
		for(int j=0;j<m;j++)
		{
			if(text[j].find(term[i]) !=string::npos)
			{
				getNumber(text[j]);
			}
		}
		cout<<endl;
	}
	
}
