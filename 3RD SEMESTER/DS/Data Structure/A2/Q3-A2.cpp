#include<iostream>

using namespace std;

class Node
{
	public:
	string pp;
	int totalTime;
	int oneTime;
	
	Node *next;
	
	Node(string pp,int totalTime,int oneTime)
	{
		this->pp=pp;
		this->totalTime=totalTime;
		this->oneTime=oneTime;
		
		next=NULL;
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
		void add(string pp,int tt,int ot)
		{
			if(head==NULL&&tail==NULL)
			{
				
				head=tail=new Node(pp,tt,ot);
				tail->next=head;
				
			}
			else
			{
			
				tail->next=new Node(pp,tt,ot);
				tail=tail->next;
				tail->next=head;
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
				
				head=NULL;
				tail=NULL;
				
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
				head=NULL;
				tail=NULL;
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
				if(head==tail)
				{
					head=NULL;
					tail=NULL;
					return;
				}
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
		bool print()
		{
			Node *temp;
			int i=1;
			for(temp=head; ;temp=temp->next,i++)
			{
				if(head==NULL&&tail==NULL)
				{
					return false;
				}
				if(temp->totalTime==0)
				{
					deletespecific(i);
					
				}
				else
				{
					cout << temp->pp<<endl;
					temp->totalTime=temp->totalTime-temp->oneTime;
				}
				
				
				if(temp->next==head)
				{
					return true;
//					deletespecific(1);
//					temp=head
//					return true;
				}
			}
			cout << endl;
		
		}

};
int main()
{
	Circular ob;
	int num;
	cin >> num;
	string check;
	int total,one;
	
	for(int i=0;i<num;i++)
	{
		fflush(stdin);
		cin >> check;
		cin >> total;
		cin >> one;
		ob.add(check,total,one);	
	}
	while(ob.print());
}

