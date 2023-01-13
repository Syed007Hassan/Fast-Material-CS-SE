#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
		string data;
		Node *next;
		Node *pre;
		
		Node()
		{
			
		}
		Node(string data)
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
	void addTotail(string value)
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
		Node *temp;
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			cout << temp->data<<endl;
		}
		
		
	}
};
int main()
{
	DoubleLinkList ob;
    string str,temp;
    
    int length=0;
    fflush(stdin);
    getline(cin,str);
    
    istringstream ss(str);
  
    string word; 

    int i=0;
    while (ss >> word) 
    {
        i++;
    }
    length=i;
    string p[length];
    i=0;
    istringstream st(str);
    while (st >> word) 
    {
        p[i]=word;
        i++;
    }
    
    for(int i=0;i<length;i++)
    {
    	
    	for(int j=i+1; j<length;j++)
    	{
    		bool f1=false;
    		bool f2=false;
			if(isupper(p[i][0]))
    		{
    			p[i][0]=tolower(p[i][0]);
				f1=true;	
			}
			if(isupper(p[j][0]))
			{
				p[j][0]=tolower(p[j][0]);
				f2=true;
					
			}
			
    		if(p[i]>p[j])
    		{
    			
    			temp=p[i];
    			p[i]=p[j];
    			p[j]=temp;
    			
    			if(f1==true)
    			{
    				p[j][0]=toupper(p[j][0]);
					f1=false;	
				}
				if(f2==true)
				{
					p[i][0]=toupper(p[i][0]);
					f2=false;
				}	
			}
			if(f1==true)
			{
				p[i][0]=toupper(p[i][0]);	
				f1=false;
			}
			if(f2==true)
			{
				p[j][0]=toupper(p[j][0]);
				f2=false;
			}		
		}
		
	}
	for(i=0;i<length;i++)
	{
		for(int j=i+1;j<length;j++)
		{
			if(p[i]==p[j])
			{
				p[j]="";
			}
		}
	}
    
    for(i=0;i<length;i++)
    {
    	if(p[i]=="")
    	{
    		continue;
		}
		else
		{
				ob.addTotail(p[i]);
		}
	}
	ob.printfor();
}
