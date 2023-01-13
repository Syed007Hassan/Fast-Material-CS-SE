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
class CircularDouble
{
	Node *head,*tail;
	int size;
	
	public:
		CircularDouble()
		{
			head=NULL;
			tail=NULL;
		}
		void addtotail(int value)
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
				tail->next=head;
				
				temp=NULL;
			}
		}
		void print()
		{
			int count=0;
			if(head==NULL&&tail==NULL)
			{
				cout << "Empty List\n";
			}
			else
			{
				cout << "Original List : ";
				Node *temp;
				for(temp=head; ;temp=temp->next)
				{
					count++;
					cout << temp->data<<"  ";
					if(temp->next==head)
					{
						break;
					}
				}
				cout <<"\n";
				cout << "Original Length = "<<count<<endl;
			}
		}
};

// if the list contains 1 2 3 then algorithm's outupt will be 1 2 3 2 3.......
int main()
{
	CircularDouble ob;
	
	int x;
	cout << "Number of elemets : ";
	cin >> x;
	int *a;
	a = new int[x];
	int check;
	cout << "Enter Elements : ";
	for(int i=0;i<x;i++)
	{
		cin >> a[i];
	}

	
	for(int i=0;i<x; )
	{
		if(i<x-2)
		{
			check=a[i];
			ob.addtotail(check);
			i=i+3;
		}
		else
		{
			check=a[i];
			ob.addtotail(check);
			i++;
		}
	}

	
	ob.print();
}
