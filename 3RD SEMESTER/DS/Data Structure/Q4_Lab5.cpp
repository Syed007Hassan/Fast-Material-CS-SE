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
class LinkList
{
	Node *head,*tail;
	public:
		
		LinkList()
		{
			head=NULL;
			tail=NULL;
		}
		LinkList& addtoTail(int value)
		{
			if(head==NULL&&tail==NULL)
			{
				head=tail=new Node(value);
			}
			else
			{
				tail->next=new Node(value);
				tail=tail->next;
			}
			return (*this);
		}
		void swap()
		{
			int temp1;
			bool flag1=false,flag2=false;
			Node *temp,*tempp;
			for(temp=head;temp!=NULL;temp=temp->next)
			{
				if((temp->data%2)!=0)
				{
					flag1=true;
					break;
				}
			}
			reverse();
			for(tempp=head;tempp!=NULL;tempp=tempp->next)
			{
				if((tempp->data%2)==0)
				{
					flag2=true;
					break;
				}
			}
			if(flag1==true&&flag2==true)
			{
				reverse();
				temp1=temp->data;
				temp->data=tempp->data;
				tempp->data=temp1;
			}
			else
			{
				reverse();
			}
			
		}
		void reverse()
		{
			Node *c,*p,*n;
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
		void print()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty List\n";
			}
			else
			{
				Node *temp;
				for(temp=head;temp!=NULL;temp=temp->next)
				{
					cout << temp->data<<" ";
				}
				cout << endl;
			}
		}
};

int main()
{
	LinkList ob;
	ob.addtoTail(1).addtoTail(5).addtoTail(7).addtoTail(9).addtoTail(10);
	cout << "Before Modification : ";
	ob.print();
	ob.swap();
	cout << "After Modification : ";
	ob.print();
	
}
