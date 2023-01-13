#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	
	Node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};

class BST
{
	Node *root;
	queue<Node*>o;
	
	public:
		BST()
		{
			root=NULL;
			
		}
		void insert(int value)
		{
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
					if(value==temp->data)
					{
						cout << "Duplicates Not Allowed\n";
						return;
					}
					else if(value<temp->data)
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
		int search(int key)
		{
			Node *temp=root;
			
			while(temp!=NULL)
			{
				if(key==temp->data)
				{
					cout << key << " Found\n";
					return key;
				}
				else if(key<temp->data)
				{
					temp=temp->left;
				}
				else
				{
					temp=temp->right;
				}
			}
			cout << "Key Not Found\n";
			return -1;
		}
		Node* getRoot()
		{
			return root;
		}
		int getMax(int *p,int size)
		{
			int max=p[0];
			
			for(int i=1;i<size;i++)
			{
				if(max<p[i])
				{
					max=p[i];
				}
			}
			return max;
		}
		int getMin(int *p,int size)
		{
			int min=p[0];
			
			for(int i=1;i<size;i++)
			{
				if(min>p[i])
				{
					min=p[i];
				}
			}
			return min;
		}
		void Levelorder()
		{
			if(root==NULL)
			{
				return;
			}
			queue<Node*> ob;
			
			ob.push(root);
			ob.push(NULL);
			int i=1;
			while(!ob.empty())
			{
				Node *temp=ob.front();
				ob.pop();
				
				
				if(temp!=NULL)
				{
					o.push(temp);
					if(i==1)
					{
						o.push(NULL);
					}
										
					if(temp->left!=NULL)
					{
						ob.push(temp->left);
					}
					if(temp->right!=NULL)
					{
						ob.push(temp->right);
					}
				}
				else if(!ob.empty())
				{
					ob.push(NULL);
					if(i==1)
					{
						i++;
					}
					else
					{
						o.push(NULL);
					}
					
				}
				
			}
		}
		bool solution()
		{
			while(!o.empty())
			{				
                if(o.front()==NULL)
				{
					o.pop();
				}
				int i=0,size=0;
				int *p=new int[1];
				while(o.front()!=NULL)
				{
					Node *t=o.front();
					o.pop();
					
					p[i]=t->data;
					i++;size++;
					
				}
				if(size==1)
				{
					cout<<p[0]<<" "<<p[0]<<endl;
				}
				else if(size>1)
				{
					cout<<getMin(p,size)<<" "<<getMax(p,size)<<endl;
				}
				
				delete []p;
				p=NULL;
							
			}
		}
		
		
		
};
int main()
{
	BST ob;
	int num;
	cin>> num;
	int check;
	
	for(int i=0;i<num;i++)
	{
		cin>>check;
		ob.insert(check);
	}
	
	ob.Levelorder();
	ob.solution();
}
