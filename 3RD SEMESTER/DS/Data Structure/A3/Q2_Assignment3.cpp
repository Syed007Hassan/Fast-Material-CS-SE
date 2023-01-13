#include<bits/stdc++.h>
#include<stack>


using namespace std;

struct Node
{
	string data;
	Node *left;
	Node *right;
	
	Node(string data)
	{
		fflush(stdin);
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
class NodeTerms
{
	public:
	string num;
	string text;
	NodeTerms *next;
	
	NodeTerms(string num,string text)
	{
		this->num=num;
		this->text=text;
		next=NULL;
	}
};
class LL
{
	NodeTerms *head,*tail;
	
	public:
		LL()
		{
			head=NULL;
			tail=NULL;
		}
		void insert(string line)
		{
			istringstream o(line);
			string word;
			o>>word;
			
			if(head==NULL&&tail==NULL)
			{
				head=tail=new NodeTerms(word,line);
				return;
			}
			else
			{
				tail->next=new NodeTerms(word,line);
				tail=tail->next;
				return;
			}
		}
		NodeTerms* getHead()
		{
			return head;
		}
		void print(string terminology)
		{
			NodeTerms *temp;
			
			for(temp=head;temp!=NULL;temp=temp->next)
			{
				if(temp->text.find(terminology) != string::npos)
				{
					cout<<" "<< temp->num;
				}
			}
			
			cout<<endl;	
		}

			
			
		
};
class BST
{
	Node *root;
	
	public:
		
		BST()
		{
			root=NULL;
		}
		void insert(string value)
		{
			fflush(stdin);
			if(root==NULL)
			{
				root=new Node(value);
				return;
			}
			else 
			{
				Node *temp,*pre;
				temp=root;
				
				while(temp!=NULL)
				{
					pre=temp;
					
					if(value<temp->data)
					{
						temp=temp->left;
					}
					else
					{
						temp=temp->right;
					}
				}
				// pre is currently holding the address of previous node of temp
				// and temp has become NULL
				Node *n = new Node (value);
				// check that where the value should go left or right.
				
				if(n->data>pre->data)
				{
					pre->right=n;
				}
				else 
				{
					pre->left=n;
				}
				
				temp=NULL;
				pre=NULL;
				n=NULL;
			}
		}
		
		Node* getRoot()
		{
			return root;
		}
		
		void inorderIterative(LL &obb)
		{
			
			stack<Node*> ob;
			Node *temp;
			temp=root;
			
			while(temp!=NULL||!ob.empty())
			{
				
				if(temp!=NULL)
				{
					ob.push(temp);
					temp=temp->left;
				}
				else
				{
					temp=ob.top();
					ob.pop();
					cout << temp->data;
					obb.print(temp->data);
					temp=temp->right;
				}
				
			}
				
		}
		
		
};

int main()
{
	BST ob;
	LL o;
	int n;
	
	cin >> n;
	string check;
	
	for(int i=0;i<n;i++)
	{
		fflush(stdin);
		getline(cin,check);
		ob.insert(check);
	}
	int m;
	cin >> m;
	string line;
	
	for(int i=0;i<m;i++)
	{
		fflush(stdin);
		getline(cin,line);
		o.insert(line);
	}
	

	ob.inorderIterative(o);
	

}
