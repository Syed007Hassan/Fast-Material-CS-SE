#include<iostream>

using namespace std;
# define MAX 10
class stack
{
	int top;
	
	char a[MAX];
	
	public:
		stack()
		{
			top=-1;
		
		
		}
		bool push(char x)
		{
			if(top==MAX-1)
			{
				
				return false;
			}
			else
			{
				top++;
				a[top]=x;

				
				return true;
			}
		}
		bool pop()
		{
			if(top==-1)
			{
				
				return false;
			}
			else
			{
				char x;
				x=a[top];
				top--;
			
				return true;
			}
		}
		char peek()
		{
			if (top < 0) 
			{
				
				return 0;
			}
			else 
			{
				char x = a[top];
				return x;
			}
		}
		bool empty()
		{
			if(top<0)
			{
				
				return true;
			}
			else
			{
				return false;
			}
		}
};

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
void inToPost(string s)
{
	stack ob;
	
	string result;
	
	for(int i=0;i<s.length();i++)
	{
		char c=s[i];
		
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		{
			result=result+c;
		}
		else if(c=='(')
		{
			ob.push('(');
		}
		else if(c==')')
		{
			while(ob.peek()!='(')
			{
				result=result+ob.peek();
				ob.pop();
			}
			ob.pop();
		}
		else
		{
			while(!ob.empty()&&pre(s[i])<=pre(ob.peek()) )
			{
				result=result+ob.peek();
				ob.pop();
			}
			ob.push(c);
		}
	}	
	while(!ob.empty())
	{
		result=result+ob.peek();
		ob.pop();
	}
	cout << result;
}
int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	inToPost(exp);
}

