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
class Queue
{
	Node *head,*tail;
	int size;
	
	public:
		Queue()
		{
			head=NULL;
			tail=NULL;
			size=0;
		}
		void enqueue(int value)
		{
			if(size==MAX)
			{
				cout << "Queue Full\n";
				return;
			}
			if(head==NULL&&tail==NULL)
			{
				head=tail=new Node(value);
				cout << tail->data<< " enqueued\n";
				size++;
				return;
			}
			else
			{
				tail->next=new Node(value);
				tail=tail->next;
				cout << tail->data<< " enqueued\n";
				size++;
				return;
			}
		}
		void dequeue()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty Queue\n";
				return;
			}
			if(head!=NULL&&tail!=NULL&&head==tail)
			{
				cout << head->data<<" dequeue\n";
				delete head;
				head=NULL;
				tail=NULL;
				size--;
				return;
			}
			else
			{
				cout << head->data<<" dequeue\n";
				Node *temp;
				temp=head->next;
				delete head;
				head=temp;
				temp=NULL;
				size--;
				return;
			}	
		}
		void peek()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty Queue\n";
				return;
			}
			else
			{
				cout << head->data<<endl;
				return;
				
			}
		}
		bool isempty()
		{
			if(head==NULL&&tail==NULL)
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
	Queue ob;
	ob.enqueue(1);
	ob.enqueue(2);
	ob.enqueue(3);
	ob.enqueue(4);
	ob.enqueue(5);
	ob.enqueue(6);
	ob.enqueue(7);
	ob.enqueue(8);
	ob.enqueue(9);
	ob.enqueue(10);
	ob.enqueue(11);
	ob.dequeue();
	ob.dequeue();
	ob.dequeue();
	ob.dequeue();
	ob.dequeue();
	ob.dequeue();
	ob.dequeue();
	ob.dequeue();
	ob.dequeue();
	ob.dequeue();
	ob.dequeue();
	
}
