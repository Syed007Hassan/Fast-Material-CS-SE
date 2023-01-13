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
class Circular
{
	Node *head,*tail;
	
	public:
		Circular()
		{
			head=NULL;
			tail=NULL;
		}
		void addTotail(int value)
		{
			if(head==NULL&&tail==NULL)
			{
				head=tail=new Node(value);
			}
			else
			{
				tail->next=new Node(value);
				tail=tail->next;
				tail->next=head;
			}
		}
		void addToHead(int value)
		{
			if(head==NULL&&tail==NULL)
			{
				head=tail=new Node(value);
			}
			else
			{
				Node *temp=new Node(value);
				temp->next=head;
				head=temp;
				tail->next=head;
				
				temp=NULL;
				delete temp;
			}
		}
		void addtospecic(int pos,int value)
		{
			int count=0,i;
			bool flag=false;
			if(pos==1)
			{
				addToHead(value);
				flag=true;
				
			}
			Node *temp;
			for(temp=head;;temp=temp->next)
			{
				count++;
				if(temp->next==head)
				{
					break;		
				}	
			}
			if(pos==count+1&&flag==false)
			{
				addTotail(value);
				flag=true;
			}
			
			temp=head;
			for(i=2; ;i++,temp=temp->next)
			{
				if(pos==i&&flag==false)
				{
					Node *n;
					n=new Node(value);
					n->next=temp->next;
					temp->next=n;
					
					n=NULL;
					break;
				}
				if(temp->next==head)
				{
					break;		
				}
			}
			
		}
		void deletefromhead()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty List\n";
			}
			else if(head== tail)
			{
				delete head;
				head=tail=0;
			}
			else
			{
				Node *temp;
				temp=head;
				head=head->next;
				delete temp;
				tail->next=head;
				temp=NULL;
			}
		}
		void deletefromtail()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty List\n";
			}
			else if(head== tail)
			{
				delete head;
				head=tail=0;
			}
			else
			{
				Node *temp;
				for(temp=head;temp->next!=tail;temp=temp->next)
				{
					
				}
				delete tail;
				tail=temp;
				tail->next=head;
				temp=NULL;
				
			}
		}
		void deletespecific(int pos)
		{
			int count=0,i;
			bool flag=false;
			if(pos==1)
			{
				deletefromhead();
				flag=true;
				
			}
			Node *temp,*current;
			for(temp=head;;temp=temp->next)
			{
				count++;
				if(temp->next==head)
				{
					break;		
				}
			}
			if(pos==count&&flag==false)
			{
				deletefromtail();
				flag=true;
			}
			if (flag==false)
			{
				temp=head;
				current=head->next;
				for(i=2; ;i++,temp=temp->next,current=current->next)
				{
					if(temp->next==head)
					{
						break;		
					}
					if(pos==i)
					{
						temp->next=current->next;
						delete current;
					
						temp=NULL;
						current=NULL;
						break;
					}
					
				}
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
				for(temp=head; ;temp=temp->next)
				{
					cout << temp->data<<"  ";
					if(temp->next==head)
					{
						break;
					}
				}
				cout << endl;
			}
		}
		
};
int main()
{
	Circular ob;
	ob.addTotail(1);
	ob.addTotail(2);
	ob.addTotail(3);
	ob.addTotail(4);
	ob.addTotail(5);
	ob.addToHead(0);
	ob.addtospecic(1,10);
	ob.deletefromhead();
	ob.deletefromhead();
	ob.deletefromtail();
	ob.deletespecific(2);
	ob.print();
}
