#include<iostream>
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
	
	public:
		
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
		void preorderIterative()
		{
		
			Node *temp=root;
			stack<Node*> ob;
			
			while(temp!=NULL || !ob.empty() )
			{
				if(temp!=NULL)
				{
					cout << temp->data<< "  ";
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
			cout << endl;
		}
		void preorderRecursive(Node *tempRoot)
		{
			if(tempRoot!=NULL)
			{
				cout << tempRoot->data<< "  ";
				preorderRecursive(tempRoot->left);
				preorderRecursive(tempRoot->right);
			}	
		}
		void inorderIterative()
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
					cout << temp->data<< "  ";
					temp=temp->right;
				}
				
			}
			cout << endl;	
		}
		void inorderRecursive(Node *tempRoot)
		{
			if(tempRoot!=NULL)
			{
				inorderRecursive(tempRoot->left);
				cout << tempRoot->data<< "  ";
				inorderRecursive(tempRoot->right);
			}
		}
		void postorderRecursive(Node *tempRoot)
		{
			if(tempRoot!=NULL)
			{
				postorderRecursive(tempRoot->left);
				postorderRecursive(tempRoot->right);
				cout << tempRoot->data<< "  ";
			}
		}
};
int main()
{
	BST ob;
	ob.insert(30);
	ob.insert(40);
	ob.insert(20);
	ob.insert(25);
	ob.insert(10);
	ob.insert(35);
	ob.insert(50);
	
	ob.preorderIterative();
	ob.preorderRecursive(ob.getRoot());
	cout << endl;
	ob.inorderIterative();
	ob.inorderRecursive(ob.getRoot());
	cout << endl;
	
	ob.postorderRecursive(ob.getRoot());
	cout << endl;
	ob.search(10);
	ob.search(1);
	
	ob.Delete(ob.getRoot(),30);
	ob.preorderIterative();

}
