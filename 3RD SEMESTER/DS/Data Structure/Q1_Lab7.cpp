#include<iostream>

using namespace std;

#define MAX 10
class stack
{
	int top;
	
	int a[MAX];
	
	public:
		stack()
		{
			top=-1;
		
		
		}
		bool push(int x)
		{
			if(top==MAX-1)
			{
				cout << "Stack Is full\n";
				return false;
			}
			else
			{
				top++;
				a[top]=x;
				cout<<"value inserted\n";
				
				return true;
			}
		}
		bool pop()
		{
			if(top==-1)
			{
				cout << "Empty Stack\n";
				return false;
			}
			else
			{
				int x;
				x=a[top];
				top--;
				cout<<x<<" Deleted\n";
				return true;
			}
		}
		int peek()
		{
			if (top < 0) 
			{
				cout << "Stack is Empty\n";
				return 0;
			}
			else 
			{
				int x = a[top];
				return x;
			}
		}
		bool empty()
		{
			if(top<0)
			{
				cout<<"Empty Stack\n";
				return true;
			}
			else
			{
				return false;
			}
		}
};
int main()
{
	stack ob;
	int x;
	cout << "Enter 10 elements : ";
	for(int i=0;i<12;i++)
	{
		cin >> x;	
		ob.push(x);
	}
	while(1)
	{
		if(ob.empty())
		{	
			break;
		}
		else
		{
			ob.pop();
		}
	}
}
