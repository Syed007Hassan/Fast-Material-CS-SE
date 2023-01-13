#include<iostream>
#include<stdexcept>

using namespace std;

class AverageLinkList;
class LinkList; 
class Node
{
    public:
    	
    float data;
    Node *next;
	Node()
	{
		
	}
    Node(float data)
    {
        this->data=data;
        next=NULL;
    }
};

class LinkList
{
    Node *head,*tail;
	int noOfNodes;
    int number;
    public:
    LinkList(int no)
    {
        try
        {
            if(no<1)
            {
                throw out_of_range("Invalid Input");
            }
            noOfNodes=no;
            head=NULL;
            tail=NULL;
        }
        catch(out_of_range &ex)
        {
            cout << ex.what();
        }
        
    }
    void input()
    {
        cout << "Enter "<<noOfNodes<<" Elements\n";
        for(int i=0;i<noOfNodes;i++)
        {
            cin >> number;
            addtoTail(number);
        }
    }
    void addtoTail(float value)
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
            cout << "Empty Link List\n";
        }
        else
        {
            Node *temp;
            cout << "Link List : ";
            for(temp=head;temp!=NULL;temp=temp->next)
            {
                cout << temp->data << " ";
            }
            cout<<endl;
        }
    }
    friend void average(LinkList L,AverageLinkList &A);
	
};
class AverageLinkList
{
	Node *head,*tail;
	public:
		AverageLinkList()
		{
			head=NULL;
			tail=NULL;
		}
		void addtoTail(float value)
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
            cout << "Empty  Average List\n";
        }
        else
        {
            Node *temp;
            cout << "Average Link List : ";
            for(temp=head;temp!=NULL;temp=temp->next)
            {
                cout << temp->data << " ";
            }
            cout<<endl;
        }
    }
    friend void average(LinkList L,AverageLinkList &A);
};
void average(LinkList L,AverageLinkList &A)
{
	float average,sum;
	Node *temp;
	Node *successor;
	temp=L.head;
	for(int i=0;i<9;i++,temp=temp->next)
	{
		average=0;sum=0;
		successor=temp;
		for(int j=0;j<4;j++,successor=successor->next)
		{
			sum=sum+successor->data;
		}
		A.addtoTail(sum/4);
		
	}
}
int main()
{
    LinkList ob(12);
    AverageLinkList ob1;
    ob.input();
    average(ob,ob1);
    ob.print();
    ob1.print();
    
    
}
