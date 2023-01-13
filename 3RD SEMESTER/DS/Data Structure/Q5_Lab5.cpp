#include<iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next;
	public:
		Node()
		{
			
		}
		Node(int data)
		{
			this->data=data;
			next=NULL;
		}
};
class linkedList
{
	Node *head,*tail;
	int noOfNodes,number;
	
	
	public:
		linkedList(int noOfNodes)
		{
			this->noOfNodes=noOfNodes;
			head=NULL;
			tail=NULL;
		}
		void addtoTail(int value)
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
		void input()
    	{
        	cout << "Enter "<<noOfNodes<<" Elements : ";
        	for(int i=0;i<noOfNodes;i++)
        	{
            	cin >> number;
            	addtoTail(number);
        	}
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
					cout << temp->data << "  ";
				}
				cout<<endl;
			}
		}
		int getmax()
		{
			int max;
			max=head->data;
			Node *temp;
			for(temp=head->next;temp!=0;temp=temp->next)
			{
				if(max<temp->data)
				{
					max=temp->data;
				}
			}
			return max;
		}
		
		friend void fiboncci(linkedList &ob,int max);
};
void fiboncci(linkedList &ob,int max)
{
	int *ptr=new int [1],count=0;
	int first=0;
	int second=1;
	int next=0;
	int sum=0;
	
	for(int i=0;first<=max;i++,count++)
	{
		ptr[i]=first;
		next=first+second;
		first=second;
		second=next;
	}
	Node *temp;
	int countOfOdd=0;
	cout << "Odd fibonacci in the List are : ";
	for(temp=ob.head;temp!=0;temp=temp->next)
	{
		for(int i=0;i<count;i++)
		{
			if(temp->data==ptr[i]&&(temp->data)%2==1)
			{
				countOfOdd++;
				cout<<temp->data << "  ";
				sum=sum+temp->data;
			}
		}
	}
	cout << endl;
	cout << "Their Mean = "<<(float)sum/countOfOdd<<endl;

	
}
int main()
{
	linkedList ob(10);
	ob.input();
	ob.print();
	fiboncci(ob,ob.getmax());
	

}
