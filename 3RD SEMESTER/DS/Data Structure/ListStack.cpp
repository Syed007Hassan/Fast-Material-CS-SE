#include<iostream>
#define MAX 10
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
	
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}	
};
class Stack
{
	Node *head,*top;
	int size;
	public:
		Stack()
		{
			head=NULL;
			top=NULL;
			size=0;
		}
		bool push(int value)
		{
			if(size==MAX)
			{
				cout << "Stack Full\n";
				return false;
			}
			if(head==NULL&&top==NULL)
			{
				head=top=new Node(value);
				cout << top->data<<" added to stack\n";
				size++;
				return true;
			}
			else
			{
				top->next=new Node(value);
				top=top->next;
				cout << top->data<<" added to stack\n";
				size++;
				return true;
			}
		}
		bool pop()
		{
			if(top==NULL)
			{
				cout << "Empty Stack\n";
				return false;
			}
			if(head!=NULL&&top!=NULL&&top==head)
			{
				cout << head->data<<" poped\n";
				delete head;
				head=NULL;
				top=NULL;
				size--;
				return true;
			}
			else
			{
				Node *temp;
				for(temp=head;temp->next!=top;temp=temp->next)
				{
					
				}
				cout << top->data<<" poped\n";
				delete top;
				top=temp;
				temp=NULL;
				size--;
				return true;
			}
		}
		int peek()
		{
			if(top==NULL)
			{
				cout <<"Empty Stack\n";
				return 0;
			}
			else
			{
				return top->data;
			}
		}
		bool isEmpty()
		{
			if(head==NULL&&top==NULL)
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
	ob.push(11);
	ob.push(12);
	
	for(int i=1;i<=11;i++)
	{
		if(i==5)
		{
			cout << ob.peek()<<endl;
		}
		ob.pop();
	}
	
}


