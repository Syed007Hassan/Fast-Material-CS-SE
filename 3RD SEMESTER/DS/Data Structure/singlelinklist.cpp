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
//				tail->next=head;
			}
		}
		bool checkloop()
		{
			if(head==tail->next)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void evenodd()
		{
			Node *temp;
			int count=0;
			
			for(temp=head;temp!=0;temp=temp->next)
			{
				count++;
			}
			if((count%2)==0)
			{
				cout << "Even";
			}
			else
			{
				cout << "Odd";
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
				
				temp=NULL;
				delete temp;
			}
		}
		void addAfter(int value,int after)
		{
			if(isEmpty())
			{
				cout << "Empty list";
			}
			else
			{
				Node *temp;
				for(temp=head;temp!=0&&temp->data!=after;temp=temp->next)
				{
					
				}
				if(temp==0)
				{
					addToTail(value);
				}
				else
				{
					Node *n =new Node(value);
					n->next=temp->next;
					temp->next=n;
					
					n=NULL;
					delete n;

				}
			}
		}
		void deletefromhead()
		{
			if(isEmpty())
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
				temp=NULL;
			}
		}
		void deletespecific(int value)
		{
			if(isEmpty())
			{
				cout << "Empty List\n";
			}
			else if(head==tail&&value==head->data)
			{
				delete head;
				head=tail=NULL;
			}
			else if(value==head->data)
			{
				deletefromhead();
			}
			else
			{
				Node *temp,*prede;
				for(prede=head,temp=head->next;temp!=0&&temp->data!=value;temp=temp->next,prede=prede->next)
				{
				}
				if(tail==temp)
				{
					deletefromtail();
				}
				else if(temp==0)
				{
					cout << "Not in list"<<endl;
				}
				else
				{
					prede->next=temp->next;
					delete temp;
				}	
			}	
		}
		void deletefromtail()
		{
			if(isEmpty())
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
				tail->next=0;
				temp=NULL;
				
			}
		}
		void maximum()
		{
			int max;
			Node *temp;
			max=head->data;
			for(temp=head->next;temp!=0;temp=temp->next)
			{
				if(max<temp->data)
				{
					max=temp->data;
				}
			}
			cout << "The maximum = "<<max<<endl;
			temp=NULL;
			
		}
		void MeanSum()
		{
			int sum=0;
			int count=0;
			Node *temp;
			for(temp=head;temp!=0;temp=temp->next)
			{
				sum=sum+temp->data;
				count++;
			}
			cout << "Sum = "<<sum<<endl;
			cout << "Mean = "<<(float)sum/count<<endl;	
			temp=NULL;
		}
		void sortassecend()
		{
			int tempvalue;
			Node *temp,*temp2;
			for(temp=head;temp!=0;temp=temp->next)
			{
				for(temp2=head;temp2!=tail;temp2=temp2->next)
				{
					if(temp2->data>temp2->next->data)
					{
						tempvalue=temp2->data;
						temp2->data=temp2->next->data;
						temp2->next->data=tempvalue;
					}
				}
			}
		}
		void reverse()
		{
			Node *p,*c,*n;
			
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
		bool isEmpty()
		{
			if(head==0&&tail==0)
			{
				return 1;
			}
			else
			{
				return 0;
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
};
int main()
{
	LinkedList ob;
	ob.addToTail(1);
	ob.addToTail(2);
	ob.addToTail(3);
	ob.addToHead(0);
	ob.evenodd();
	
	

	
}
