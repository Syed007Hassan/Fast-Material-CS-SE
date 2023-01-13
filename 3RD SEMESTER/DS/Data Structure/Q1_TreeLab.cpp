#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	
	Node(int value)
	{
		data=value;
		left=NULL;
		right=NULL;
	}
};
bool AutoGrader(Node *temp)
{
	if(temp==NULL)
	{
		return 1;
	}	
	else if(temp->left!=NULL&&temp->left->data > temp->data)
	{
		return 0;
	}
	else if(temp->right!=NULL && temp->right->data < temp->data)
	{
		return 0;
	}
	else if(!AutoGrader(temp->left)||!AutoGrader(temp->right))
	{
		return 0;
	}
	return 1; // means the given tree is BST
}
int main()
{
	
}
