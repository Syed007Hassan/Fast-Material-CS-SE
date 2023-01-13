#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		int height;
		node* left;
		node* right;
		
		node()
		{
			data=0;
			height=0;
			left=NULL;
			right=NULL;
		}
		
		node(int d)
		{
			data=d;
			height=0;
			left=NULL;
			right=NULL;
		}
};
class AVL
{
	public:
		node* root;
		AVL()
		{
			root=NULL;
		}
		
		int nodeHeight(node *temp)
		{
			int hl,hr;
			
			hl=temp && temp->left?temp->left->height:0;
			hr=temp && temp->right?temp->right->height:0;
			
			return hl>hr?hl+1:hr+1;
		}
		
		int balanceFactor(node *temp)
		{
			int hl,hr;
			
			hl=temp && temp->left?temp->left->height:0;
			hr=temp && temp->right?temp->right->height:0;
			
			return hl-hr;
		}
		
		node* LLRotation(node *temp)
		{
			node *pl=temp->left;
			node *plr=pl->right;
			
			pl->right=temp;
			temp->left=plr;
			temp->height=nodeHeight(temp);
			pl->height=nodeHeight(pl);
			
			if(root==temp)
			{
				root=pl;
			}
			return pl;
		}
		
		node* RRRotation(node *temp)
		{
			node *pr=temp->right;
			node *prl=pr->left;
			
			pr->left=temp;
			temp->right=prl;
			temp->height=nodeHeight(temp);
			pr->height=nodeHeight(pr);
			
			if(root==temp)
			{
				root=pr;
			}
			return pr;
		}
		
		node* LRRotation(node *temp)
		{
			node *pl=temp->left;
			node *plr=pl->right;
			
			pl->right=plr->left;
			temp->left=plr->right;
			plr->left=pl;
			plr->right=temp;
			
			pl->height=nodeHeight(pl);
			temp->height=nodeHeight(temp);
			plr->height=nodeHeight(plr);
			
			if(root==temp)
			{
				root=plr;
			}
			return plr;
		}
		
		node* RLRotation(node *temp)
		{
			node *pr=temp->right;
			node *prl=pr->left;
			
			pr->left=prl->right;
			temp->right=prl->left;
			prl->right=pr;
			prl->left=temp;
			
			pr->height=nodeHeight(pr);
			temp->height=nodeHeight(temp);
			prl->height=nodeHeight(prl);
			
			if(root==temp)
			{
				root=prl;
			}
			return prl;
		}

		node* insert(node* temp, int d)
		{
			node*t = NULL;
			if(temp==NULL)
			{
				t=new node(d);
				t->data=d;
				t->height=1;
				t->left=t->right=NULL;
				return t;
			}
			if(d < temp->data)
			{
				temp->left=insert(temp->left,d);
			}
			
			else if(d > temp->data)
			{
				temp->right=insert(temp->right,d);
			}
			
			temp->height=nodeHeight(temp);
			
			if(balanceFactor(temp)==2 && balanceFactor(temp->left)==1)
			{
				return LLRotation(temp);
			}
			
			else if(balanceFactor(temp)==2 && balanceFactor(temp->left)==-1)
			{
				return LRRotation(temp);
			}
			
			else if(balanceFactor(temp)==-2 && balanceFactor(temp->right)==-1)
			{
				return RRRotation(temp);
			}
			
			else if(balanceFactor(temp)==-2 && balanceFactor(temp->right)==1)
			{
				return RLRotation(temp);
			}
			
			return temp;
		}
		
		node * minValueNode(node* n)
		{
			node* current = n;
		
			/* loop down to find the leftmost leaf */
			while (current->left != NULL)
			{
				current = current->left;
			}
		
			return current;
		}

		node* search(node* temp, int key)
		{
			if(temp==NULL)
			{
				return NULL;
			}
			if(key==temp->data)
			{
				return temp;
			}
			else if(key < temp->data)
			{
				return search(temp->left, key);
			}
			else if(key > temp->data)
			{
				return search(temp->right, key);
			}
		}

		node* deleteNode(node* root, int data)
		{
			
			if (root == NULL)
			{
				return root;
			}
		
		
			if ( data < root->data )
			{
				root->left = deleteNode(root->left, data);
			}
		
			else if( data > root->data )
			{
				root->right = deleteNode(root->right, data);
			}
	
			else
			{
				if( (root->left == NULL) ||	(root->right == NULL) )
				{
					node *temp = root->left ? root->left : root->right;
		

					if (temp == NULL)
					{
						temp = root;
						root = NULL;
					}
					else 
					{
						*root = *temp;
					}
					delete(temp);
				}
				else
				{
					node* temp = minValueNode(root->right);
	
					root->data = temp->data;
					
					root->right = deleteNode(root->right,
											temp->data);
				}
			}
		
		
			if (root == NULL)
			{
				return root;
			}
		
		
			root->height = 1 + max(nodeHeight(root->left), nodeHeight(root->right));
		
		
			int balance = balanceFactor(root);
		
		
		
		
			if (balance > 1 && balanceFactor(root->left) >= 0)
			{
				return RRRotation(root);
			}
		
		
			if (balance > 1 && balanceFactor(root->left) < 0)
			{
				root->left = LLRotation(root->left);
				return RLRotation(root);
			}
		
		
			if (balance < -1 &&	balanceFactor(root->right) <= 0)
			{
				return LLRotation(root);
			}	
		
		
			if (balance < -1 &&	balanceFactor(root->right) > 0)
			{
				root->right = LRRotation(root->right);
				return LRRotation(root);
			}
		
			return root;
		}

		void preOrder(node* temp)
		{
			if(temp == NULL)
			{
				return ;
			}
			else
			{
				cout<<temp->data<<" ";
				preOrder(temp->left);
				preOrder(temp->right);
			}
		}
		void inOrder(node* temp)
		{
			if(temp==NULL)
			{
				return ;
			}
			else
			{
				inOrder(temp->left);
				cout<<temp->data<<" ";
				inOrder(temp->right);
			}
		}
		void postOrder(node* temp)
		{
			if(temp==NULL)
			{
				return ;
			}
			else
			{
				postOrder(temp->left);
				postOrder(temp->right);
				cout<<temp->data<<" ";
			}
		}
		
};

int main()
{
	AVL a1;
	node* root=NULL;
	node* s;
	int h=0;
	a1.root=a1.insert(a1.root, 55);
	a1.insert(a1.root, 66);
	a1.insert(a1.root, 77);
	a1.insert(a1.root, 11);
	a1.insert(a1.root, 33);
	a1.insert(a1.root, 22);
	a1.insert(a1.root, 35);
	a1.insert(a1.root, 25);
	a1.insert(a1.root, 44);
	a1.insert(a1.root, 88);
	a1.insert(a1.root, 99);
	cout<<"Initial AVL tree"<<endl;
	a1.preOrder(a1.root);
	h = a1.nodeHeight(a1.root);
	cout<<"\nHeight of tree: "<<h<<endl;
	
	cout<<"Searching 66, 22, 44 in the tree constructed above"<<endl;
	s=a1.search(a1.root, 66);
	if(s==NULL)
	{
		cout<<"Not found";
	}
	else
	{
		cout<<"found: "<<s->data<<endl;
	}
	
	s=a1.search(a1.root, 22);
	if(s==NULL)
	{
		cout<<"Not found";
	}
	else
	{
		cout<<"found: "<<s->data<<endl;
	}
	s=a1.search(a1.root, 44);
	if(s==NULL)
	{
		cout<<"Not found";
	}
	else
	{
		cout<<"found: "<<s->data<<endl;
	}
	
	cout<<"Deleting 35 and 99 from the tree constructed above"<<endl;
	a1.deleteNode(a1.root, 35);
	a1.deleteNode(a1.root, 99);
	
	cout<<"Preorder"<<endl;
	a1.preOrder(a1.root);
	cout<<"\n";
	
	cout<<"Inorder"<<endl;
	a1.inOrder(a1.root);
	cout<<"\n";
	
	cout<<"Postorder"<<endl;
	a1.postOrder(a1.root);
	cout<<"\n";
	
}

