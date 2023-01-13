#include<iostream>
// min priority queue of size 5
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
class PriorityQueue
{
	Node *head,*tail;
	int size;
	
	public:
		PriorityQueue()
		{
			head=NULL;
			tail=NULL;
			size=0;
		}
		bool enqueue(int value)
		{
			if(size==5)
			{
				cout << "Queue Full\n";
				return false;
			} 
			else if(head==NULL&&tail==NULL)
			{
				head=tail=new Node(value);
				size++;
				return true;
			}
			else if(value<=head->data)
			{
				Node *temp;
				temp=new Node(value);
				size++;
				temp->next=head;
				head=temp;
				temp=NULL;
				return true;
			}
			else if(value>=tail->data)
			{
				tail->next=new Node(value);
				tail=tail->next;
				size++;
			}
			else  
			{
				Node *temp1,*temp2;
				temp1=head;
				while(temp1->next->data<value)
				{
					temp1=temp1->next;
				}
				temp2=temp1->next;
				Node * n= new Node(value);
				size++;
				temp1->next=n;
				n->next=temp2;
				temp1=NULL;
				temp2=NULL;
				return false;	
			}
		}
		bool dequeue()
		{
			if(head==NULL&&tail==NULL)
			{
				cout <<"Empty Queue\n";
			}
			else
			{
				Node *temp;
				temp=head->next;
				delete head;
				head=temp;
				temp=NULL;
				size--;
				return true;
			}
		}
		void print()
		{
			Node *temp=head;
			while(temp!=NULL)
			{
				cout << temp->data<<"  ";
				temp=temp->next;	
			}
			cout << endl<<"Size : "<<size<<endl;
			cout << "Peek : "<<head->data<<endl;
		}
};
int main()
{
	PriorityQueue ob;
	ob.enqueue(5);
	ob.enqueue(4);
	ob.enqueue(3);
	ob.enqueue(2);
	ob.enqueue(1);
	
	ob.print();
	ob.dequeue();
	ob.print();
	ob.enqueue(8);
	ob.print();
	ob.dequeue();
	ob.print();
	ob.enqueue(6);
	ob.print();
	ob.dequeue();
	ob.print();
	ob.enqueue(7);
	ob.print();
	
}
