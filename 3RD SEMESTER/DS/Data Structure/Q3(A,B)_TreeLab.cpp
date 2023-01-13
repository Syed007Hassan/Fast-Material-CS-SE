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

void preOrderRecursive(Node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	else
	{
		cout << temp->data<<"  ";
		preOrderRecursive(temp->left);
		preOrderRecursive(temp->right);
	}
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
void preOrderIterative(Node *temp)
{
	stack<Node*> ob;
	
	while(temp!=NULL || !ob.empty())
	{
		if(temp!=NULL)
		{
			cout << temp->data<<"  ";
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
	cout << "\n";
}
int main()
{
	
}
