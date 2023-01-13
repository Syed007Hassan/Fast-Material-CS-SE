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
				root = new Node(value);
				return;
			}
			else
			{
				Node *temp,*pre,*n;
				temp=root;
				
				while(temp!=NULL)
				{
					pre = temp;
					
					if(value<temp->data)
					{
						temp=temp->left;
					}
					else if(value>temp->data)
					{
						temp=temp->right;
					}
				}
				n = new Node(value);
				
				if(n->data>pre->data)
				{
					pre->right=n;
				}
				else if(n->data<pre->data)
				{
					pre->left=n;
				}
				temp=NULL;
				n=NULL;
				pre=NULL;
			}
		}
		void inOrder()
		{
			Node *temp=root;
			stack<Node*> ob;
			
			while(temp!=NULL || !ob.empty())
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
					cout << temp->data<<"  ";
					temp=temp->right;
				}
			}
			cout << "\n";
		}
		
};
int main()
{
	int array[7]={15, 10, 20, 8, 12, 16, 25};
	BT ob;
	
	for(int i=0;i<7;i++)
	{
		ob.insert(array[i]);
	}
	ob.inOrder();
}
