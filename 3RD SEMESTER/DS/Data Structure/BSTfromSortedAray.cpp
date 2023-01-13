#include<iostream>

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
Node* BST(int a[],int start,int end)
{
	if(start>end)
	{
		return NULL;
	}
	int mid = (start+end)/2;
	Node *root = new Node(a[mid]);
	
	root->left = BST(a,start,mid-1);
	root->right= BST(a,mid+1,end);
	return root;
}
void preorder(Node *root)
{
	if(root==NULL)
	{
		return;
	}
	cout << root->data<<"  ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	int array[9] = {1,2,3,4,5,6,7,8,9};
	
	Node *root = BST(array,0,8);
	preorder(root);
}
