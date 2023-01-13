#include<iostream>
#include<stack>

using namespace std;
bool bracktets(string line)
{
	stack<char> ob;
	char c;
	char x;
	int i;
	int count=0;
	
	for(i=0;i<line.length();i++)
	{
		c= line[i];
		
		if(c=='['||c=='{'||c=='(')
		{
			ob.push(c);
		}
		 if(c==']'||c=='}'||c==')')
		{
			switch (c)
			{
				case ')':
					
					x=ob.top();
					ob.pop();
					if(x=='['||x=='{')
					{
						return false;
					}
					else
					{
						count++;
					}
					break;
					
				
				case '}':
					
					x=ob.top();
					ob.pop();
					if(x=='('||x=='[')
					{
						return false;
					}
					else
					{
						count++;
					}
					break;	
					
				case ']':
					
					x=ob.top();
					ob.pop();
					if(x=='('||x=='{')
					{
						return false;
					}
					else
					{
						count++;
					}
					break;		
			}		
		}
		
	}
	cout<<"Score : "<<count<<endl;
	return ob.empty();
}
int main()
{
	string sen;
	
	sen="[2+b]()";
	
	cout << bracktets(sen);	
}

