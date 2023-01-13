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
		next=NULL;
	}
};
class LL
{
	Node *head,*tail;
	
	public:
		LL()
		{
			head=NULL;
			tail=NULL;
		}
		void add(int value)
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
		}
		void print()
		{
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty list\n";
			}
			else
			{
				Node *temp;
				for(temp=head;temp!=NULL;temp=temp->next)
				{
					cout << temp->data<<"  ";
				}
				cout << "\n";
			}
		}
		void swap(int &a,int &b)
		{
			int temp;
			
			temp=a;
			a=b;
			b=temp;
			

		}
		void sort()
		{
			Node *temp1,*temp2,*temp3;
			int min;
			for(temp1=head;temp1!=tail;temp1=temp1->next)
			{
				min=temp1->data;
				temp3=temp1;
				
				for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
				{
					if(min>temp2->data)
					{
						min=temp2->data;
						temp3=temp2;
					}
				}
				
				swap(temp1->data,temp3->data);
			}
		}
	
};
int main()
{
	LL ob;
	
	ob.add(0);
	ob.add(1);
	ob.add(0);
	ob.add(9);
	ob.add(0);
	ob.print();
	ob.sort();
	ob.print();
	
}
