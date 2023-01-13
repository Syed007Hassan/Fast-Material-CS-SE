#include<iostream>
# define MAX 10
using namespace std;

class Stack
{
	int top;
	int size;
	int a[MAX];
	
	public:
		Stack()
		{
			top=-1;
			size=0;
		}
		bool push(int value)
		{
			if(top==MAX-1)
			{
				cout << "Stack Full\n";
				return false;
			}
			else
			{
				top++;
				a[top]=value;
				cout << value <<"added to stack\n";
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
				cout << x<<" poped\n";
				return true;
			}
		}
		int peek()
		{
			if(top==-1)
			{
				cout <<"Empty Stack\n";
			}
			else
			{
				return a[top];
			}
		}
		bool isEmpty()
		{
			if(top==-1)
			{
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
	Stack ob;
	ob.push(1);
	ob.push(2);
	ob.push(3);
	ob.push(4);
	ob.push(5);
	ob.push(6);
	ob.push(7);
	ob.push(8);
	ob.push(9);
	ob.push(10);
	ob.push(1);
	for(int i=1;i<=11;i++)
	{
		if(i==5)
		{
			cout << ob.peek()<<endl;
		}
		ob.pop();
	}
}
