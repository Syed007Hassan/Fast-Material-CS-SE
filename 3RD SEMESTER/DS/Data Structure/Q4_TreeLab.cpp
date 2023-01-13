#include<iostream>
#include<stack>
static int size=0;

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

class BT
{
	Node *root;
	
	public:
		BT()
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
		Node* getRoot()
		{
			return root;
		}
		int height(Node *p)
		{
			int x,y;
			if(p==NULL)
			{
				return 0;
			}
			x=height(p->left);
			y=height(p->right);
			return x>y? x+1 : y+1;
		}
		Node* inOrderPred(Node *p)
		{
			while(p&&p->right!=NULL)
			{
				p=p->right;
			}
			return p;
		}
		Node* inOrderSucc(Node *p)
		{
			while(p&&p->left!=NULL)
			{
				p=p->left;
			}
			return p;
		}
		Node *Delete(Node *tempRoot,int key)
		{
			if(tempRoot==NULL)
			{
				return NULL;
			}
			if(tempRoot->left==NULL&&tempRoot->right==NULL)
			{
				if(tempRoot==root)
				{
					root=NULL;
				}
				delete tempRoot;
				return NULL;
			}
			if(key<tempRoot->data)
			{
				tempRoot->left=Delete(tempRoot->left,key);
			}
			else if(key>tempRoot->data)
			{
				tempRoot->right=Delete(tempRoot->right,key);
			}
			else
			{
				if(height(tempRoot->left)>height(tempRoot->right))
				{
					Node * n ;
					n = inOrderPred(tempRoot->left);
					tempRoot->data=n->data;
					tempRoot->left=Delete(tempRoot->left,n->data);
				}
				else
				{
					Node *n;
					n = inOrderSucc(tempRoot->right);
					tempRoot->data=n->data;
					tempRoot->right=Delete(tempRoot->right,n->data);
				}
			}
		}
		int* deleteoutsiderange(int start,int end,Node *temp)
		{
			int *p=new int[1];
			int i=0;
			
			stack<Node*> ob;
	
			while(temp!=NULL || !ob.empty())
			{
				if(temp!=NULL)
				{
					if(temp->data<start||temp->data>end)
					{
						p[i]=temp->data;
						i++;
					}
					ob.push(temp);
					temp=temp->left;
				}
				else
				{
					temp=ob.top();
					ob.pop();
					temp=temp->right;
				}
			}
			size=i;
			return p;
		}
		void inOrderRecurive(Node *temp)
		{
			if(temp==NULL)
			{
				return;
			}
			else
			{
				inOrderRecurive(temp->left);
				cout << temp->data<<"  ";
				inOrderRecurive(temp->right);
			}
		}
};
int main()
{
	int array[7]={15, 10, 20, 8, 12, 16, 25};
	int *a;
	BT ob;
	
	for(int i=0;i<7;i++)
	{
		ob.insert(array[i]);
	}
	
	a=ob.deleteoutsiderange(9,12,ob.getRoot());
	
	for(int i=0;i<size;i++)
	{
		ob.Delete(ob.getRoot(),a[i]);
	}
	
	ob.inOrderRecurive(ob.getRoot());
}
