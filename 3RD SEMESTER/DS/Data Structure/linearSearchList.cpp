#include<iostream>

using namespace std;

class Node
{
	public:
		
		int data;
		Node *next;
	
	Node()
	{
		
	}
	Node(int data)
	{
		this->data=data;
		next=0;
	}
};
class LinkedList
{
	Node *head,*tail;
	
	public:
		LinkedList()
		{
			head=tail=0;
		}
		void addToTail(int value)
		{
			if(head==0 && tail==0)
			{
				head=tail=new Node(value);
			}
			else
			{
				tail->next=new Node(value);
				tail=tail->next;

			}
		}
		void print()
		{
			if(head==0&&tail==0)
			{
				cout << "Empty List\n";
			}
			else
			{
				Node *temp;
				for(temp=head;temp!=0;temp=temp->next)
				{
					cout<<temp->data<<" ";
				}
				cout<<endl;
			}
		}
		Node* gethead()
		{
			return head;
		}
};
void search(LinkedList ob,int key)
{
	Node *temp;
	
	
	for(temp=ob.gethead();temp!=NULL;temp=temp->next)
	{
		if(temp->data==key)
		{
			cout << "Key found : "<<temp->data;
			return;
		}
	}
	if(temp==NULL)
	{
		cout << "Key Not found";
	}
	
}
int main()
{
	LinkedList ob;
	ob.addToTail(1);
	ob.addToTail(2);
	ob.addToTail(3);
	ob.addToTail(4);
	ob.print();
	
	search(ob,6);
	
	
}
