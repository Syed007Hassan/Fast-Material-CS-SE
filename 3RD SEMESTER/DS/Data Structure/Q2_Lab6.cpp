#include<iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node *pre;
		
		Node()
		{
			
		}
		Node(int data)
		{
			this->data=data;
			next=NULL;
			pre=NULL;
		}
		
};
class DoubleLinkList
{
	Node *head,*tail;
	
	public:
		DoubleLinkList()
		{
			head=NULL;
			tail=NULL;
		}
		void addTotail(int value)
		{
			if(head==NULL&&tail==NULL)
			{
				head=tail=new Node(value);
				head->pre=NULL;
			}
			else
			{
				Node *temp;
				tail->next=new Node(value);
				temp=tail;
				tail=tail->next;
				tail->pre=temp;
				
				temp=NULL;
			}
		}
		void printfor()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty List\n";
			}
			else
			{
				cout << "Forward : ";
				Node *temp;
				for(temp=head;temp!=NULL;temp=temp->next)
				{
					cout << temp->data<<"  ";
				}
				cout <<"\n";
			}
		}
		void printback()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty List\n";
			}
			else
			{
				cout << "Backward : ";
				Node *temp;
				for(temp=tail;temp!=NULL;temp=temp->pre)
				{
					cout << temp->data<<"  ";
				}
				cout <<"\n";
			}
		}
		void middlePrint()
		{
			int count=0;
			int middle=0,i;
			Node *temp;
			for(temp=head;temp!=NULL;temp=temp->next)
			{
				count++;
			}
			if((count%2)!=0)
			{
				middle=count/2;
				middle++;
				temp=head;
				for(i=1;temp!=NULL;temp=temp->next,i++)
				{
					
					if(i==middle)
					{
						cout << "Middle Element : "<<temp->data<<endl;
						break;
					}
					
				}
			}
			else
			{
				middle=count/2;
				middle++;
				temp=head;
				for(i=1;temp!=NULL;temp=temp->next,i++)
				{
					
					if(i==middle)
					{
						cout << "Middle Element : "<<temp->data<<endl;
						break;
					}
					
				}
			}
			
		}
};
int main()
{
	DoubleLinkList ob;
	ob.addTotail(1);
	ob.addTotail(2);
	ob.addTotail(3);
	ob.addTotail(4);
	ob.addTotail(5);

	ob.printfor();
	ob.printback();
	ob.middlePrint();
	
}
