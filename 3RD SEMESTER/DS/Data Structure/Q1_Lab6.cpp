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
			
			temp=NULL;
		}
	}
	void addtoHead(int value)
	{
		if(head==NULL&&tail==NULL)
		{
			head=tail=new Node(value);
			head->pre=NULL;
		}
		else
		{
			Node *temp;
			temp=new Node(value);
			temp->next=head;
			head->pre=temp;
			head=temp;
			head->pre=NULL;
			
			temp=NULL;
		}
	}
	void addtospecic(int pos,int value)
	{
		int count=0,i;
		bool flag=false;
		if(pos==1)
		{
			addtoHead(value);
			flag=true;
			
		}
		Node *temp;
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			count++;
		}
		if(pos==count+1&&flag==false)
		{
			addtotail(value);
			flag=true;
		}
		
		temp=head;
		for(i=2;temp!=NULL;i++,temp=temp->next)
		{
			if(pos==i&&flag==false)
			{
				Node *n;
				n=new Node(value);
				n->next=temp->next;
				n->pre=temp;
				temp->next->pre=n;
				temp->next=n;
				
				n=NULL;	
				break;
			}
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
	void mean()
	{
		int sum=0,count=0;
		Node *temp;
		
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			sum=sum+temp->data;
			count++;
		}
		cout << "Mean : "<<(float)sum/count<<endl;
		
		
	}
	void max()
	{
		int max=head->data;
		
		Node *temp;
		
		for(temp=head->next;temp!=NULL;temp=temp->next)
		{
			if(max<temp->data)
			{
				max=temp->data;
			}
		}
		cout << "Maximum : "<<max<<endl;
	}
	void sort()
	{
		Node *temp1,*temp2;
		int tempVar;
		for(temp1=head;temp1!=NULL;temp1=temp1->next)
		{
			for(temp2=head;temp2!=tail;temp2=temp2->next)
			{
				if(temp2->data>temp2->next->data)
				{
					tempVar=temp2->data;
					temp2->data=temp2->next->data;
					temp2->next->data=tempVar;
				}
			}
		}
	}
	void reverse()
	{
		Node *p,*c,*n;
		
		p=head;
		c=head->next;
		
		while(c!=NULL)
		{
			n=c->next;
			c->next=p;
			p->pre=c;
			
			p=c;
			c=n;
			
		}
		tail=head;
		head=p;
		head->pre=NULL;
		tail->next=NULL;
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
};
int main()
{
	DoubleLinkList ob;
	ob.addtotail(4);
	ob.addtoHead(3);
	ob.addtotail(6);
	ob.addtotail(7);
	ob.addtospecic(1,1);
	ob.deletetail();
	ob.deletespecific(4);
	ob.addtospecic(2,2);
	
	ob.reverse();
	ob.sort();
	ob.printfor();
	ob.printback();
	ob.max();
	ob.mean();
}
