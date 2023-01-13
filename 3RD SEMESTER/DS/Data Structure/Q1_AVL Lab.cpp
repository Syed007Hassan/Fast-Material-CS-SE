#include<iostream>
#include<stack>
static int size=0;

using namespace std;

struct Node
{
	int id;
	string gender;
	Node *left;
	Node *right;
	
	Node(int id)
	{
		this->id=id;
		gender="Woman";
		left=NULL;
		right=NULL;
	}
};

class BST
{
	Node *root;
	
	public:
		BT()
		{
			root=NULL;
		}
		void insert(int checkid)
		{
			if(root==NULL)
			{
				root=new Node(checkid);
				return;
			}
			else 
			{
				Node *temp,*pre;
				temp=root;
				
				while(temp!=NULL)
				{
					pre=temp;
					if(checkid==temp->id)
					{
						cout << "Duplicates Not Allowed\n";
						return;
					}
					else if(checkid<temp->id)
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
				Node *n = new Node (checkid);
				// check that where the value should go left or right.
				
				if(n->id>pre->id)
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
		bool Update(int checkid)
		{
			Node *temp=root;
			
			while(temp!=NULL)
			{
				if(checkid==temp->id)
				{
					temp->gender="Male";
					return true;
				}
				else if(checkid<temp->id)
				{
					temp=temp->left;
				}
				else
				{
					temp=temp->right;
				}
			}
			return false;
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
				cout << "Id : "<<temp->id<<" Gender : "<<temp->gender<<endl;
				inOrderRecurive(temp->right);
			}
		}
};
int main()
{
	BST ob;
	ob.insert(123);
	ob.insert(122);
	ob.insert(125);
	ob.inOrderRecurive(ob.getRoot());
	ob.Update(125);
	cout<<endl;
	ob.inOrderRecurive(ob.getRoot());
}

