#include<iostream>
#include<stack>

using namespace std;

int pre(char c)
{
	if(c=='^')
	{
		return 3;
	}
	else if(c=='*'||c=='/')
	{
		return 2;
	}
	else if(c=='+'||c=='-')
	{
		return 1;
	}
	else 
	{
		return -1;
	}
}
void hehe(string s)
{
	char c;
	string so;
	stack<char> ob;
	
	for(int i=0;i<s.length();i++)
	{
		c=s[i];
		
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		{
			so=so+c;
		}
		else if(c=='(')
		{
			ob.push(c);
		}
		else if(c==')')
		{
			while(ob.top()!='(')
			{
				so=so+ob.top();
				ob.pop();
			}
			ob.pop();
		}
		else
		{
			while(!ob.empty()&&pre(s[i])<=pre(ob.top()))
			{
				so=so+ob.top();
				ob.pop();
			}
			ob.push(c);
		}
	}
	while(!ob.empty())
	{
		so=so+ob.top();
		ob.pop();
	}
	cout << so<<endl;
}
int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	hehe(exp);
}
