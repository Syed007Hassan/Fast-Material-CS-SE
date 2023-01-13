#include<stack>
#include<bits/stdc++.h>

using namespace std;

void getNumber(string line)
{
	for(int i=0; ;i++)
	{
		if(line[i]==' ')
		{
			break;
		}
		cout<<line[i];
	}
}
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

		string* inorderIterative(int size)
		{
			string *sorted=new string [size];
			
			int i=0;
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
					sorted[i]=temp->data;
					i++;
					temp=temp->right;
				}	
			}
			return sorted;
				
		}
		
		
		
};


int main()
{
	BST ob;
	
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
	string line[m];
	string number[m];
	
	for(int i=0;i<m;i++)
	{
		fflush(stdin);
		getline(cin,line[i]);
	}
	
	for(int i=0;i<m;i++)
	{
		istringstream obj(line[i]);
		obj >> number[i];
	}
	
	
	string *p;
	p=ob.inorderIterative(n);
	for(int i=0;i<n;i++)
	{
		cout<<p[i];
		for(int j=0;j<m;j++)
		{
			if(line[j].find(p[i]) !=string::npos)
			{
				cout<<" "<<number[j];
			}
		}
		cout<<endl;
	}

}
