#include<iostream>

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
class linkList
{
	Node *head,*tail;
	int top;
	int size;
	
	public:
		linkList(int size)
		{
			head=NULL;
			tail=NULL;
			this->size=size;
			top=0;
			
		}
		bool addtohead(int value)
		{
			if(head==NULL&&tail==NULL)
			{
				if(top<size)
				{
					head=tail=new Node(value);
					top++;
					cout << "Value Inserted\n";
					return true;
				}
				else
				{
					cout << "Overflow\n";
					return false;
				}
				
			}
			else
			{
				if(top<size)
				{
					Node *temp;
					temp=new Node(value);
					temp->next=head;
					head=temp;
					
					temp=NULL;
					top++;
					cout << "Value Inserted\n";
					return true;
				}
				else
				{
					cout << "Overflow\n";
					return false;
				}
				
			}
		}
		void deletehead()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty List\n";
			}
			else if(head==tail)
			{
				cout<<head->data<<" Deleted\n";
				delete head;
				head=NULL;
				tail=NULL;
			}
			else
			{
				Node *temp;
				cout<<head->data<<" Deleted\n";
				temp=head->next;
				delete head;
				head=temp;
				
				temp=NULL;
			}
		}
		void print()
		{
			if(head==NULL&&tail==NULL)
			{
				cout<<"Empty List\n";
			}
			else
			{
				Node *temp;
				reverse();
				cout << "List : ";
				for(temp=head;temp!=NULL;temp=temp->next)
				{
					cout << temp->data<<"  ";
					
				}
				cout << endl;
				reverse();
			}
		}
		void reverse()
		{
			Node *p,*n,*c;
			
			p=NULL;
			c=head;
			while(c!=NULL)
			{
				n=c->next;
				c->next=p;
				p=c;
				c=n;
			}
			tail=head;
			head=p;
		}
		bool isempty()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty List\n";
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
	linkList ob(10);
	int num;
	
	cout << "Enter 10 elements : ";
	for(int i=0;i<12;i++)
	{
		cin >> num;
		ob.addtohead(num);
	}
	
	ob.print();
	while(1)
	{
		if(ob.isempty())
		{
			
			break;
		}
		else
		{
			ob.deletehead();
		}
	}
	
	 
}
