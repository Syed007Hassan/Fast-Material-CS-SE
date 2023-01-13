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
	void deletehead()
	{
		if(head==tail)
		{
			delete head;
			head=NULL;
			tail=NULL;
		}
		else if(head==NULL&&tail==NULL)
		{
			cout << "Empty List\n";
		}
		else
		{
			Node *temp;
			temp=head->next;
			delete head;
			head=NULL;
			head=temp;
			head->pre=NULL;
			temp=NULL;
		}
		
	}
	void deletetail()
	{
		if(head==tail)
		{
			delete head;
			head=NULL;
			tail=NULL;
		}
		else if(head==NULL&&tail==NULL)
		{
			cout << "Empty List\n";
		}
		else
		{
			Node *temp;
			temp=tail->pre;
			delete tail;
			tail=NULL;
			tail=temp;
			tail->next=NULL;
			temp=NULL;
			
		}
	}
	void deletespecific(int pos)
	{
		int count=0,i;
		bool flag=false;
		if(pos==1)
		{
			deletehead();
			flag=true;
			
		}
		Node *temp,*current;
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			count++;
		}
		if(pos==count&&flag==false)
		{
			deletetail();
			flag=true;
		}
		if (flag==false)
		{
			temp=head;
			current=head->next;
			for(i=2;temp!=NULL;i++,temp=temp->next,current=current->next)
			{
				if(pos==i)
				{
					temp->next=current->next;
					temp->next->pre=temp;
				
					temp=NULL;
					current=NULL;
					break;
				}
			}
		}
		
	}
	bool removeduplicate()
	{
		Node *temp1,*temp2;
		int i,j,check=0;
		j=1;
		for(temp1=head;temp1!=NULL;temp1=temp1->next,j++)
		{
			i=j;
			for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next,i++)
			{
				if(temp1->data==temp2->data)
				{
					check=i+1;

					deletespecific(check);
					return true;
					
				}
			}
		
			
		}
		
	}
};
int main()
{
	DoubleLinkList ob;
	
	ob.addTotail(12);
	ob.addTotail(11);
	ob.addTotail(12);
	ob.addTotail(21);
	ob.addTotail(41);
	ob.addTotail(43);
	ob.addTotail(21);

	ob.printfor();
	ob.printback();
	
	while(ob.removeduplicate());
	
	cout << "\nAfter calling duplicate function\n\n";
	
	ob.printfor();
}
