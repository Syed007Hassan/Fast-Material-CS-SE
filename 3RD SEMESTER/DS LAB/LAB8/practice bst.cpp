#include<iostream>
using namespace std;

class Node{
	
	public:
		int data;
		Node *left;
		Node *right;
		
		Node(int val){
			data = val;
			left = right = 0;
		}	
};

class BST{
	
	public:
	Node *root;
	
	BST(){
		root = 0;
	}
		
	int isBst(Node *r){
		
		if(r == 0){
			return 1;
		}
		
		if(r->left != 0 && r->left->data > r->data ){
				return  0;
		}
		
		if(r->right != 0 && r->right->data < r->data ){
				return  0;
		}
		
		if( !(isBst(r->left)) || !(isBst(r->right)) ){
				return  0;
		}
		
			return  1;
		
	}

};
int main(){
	
	BST a;
	
	a.root = new Node(10);
		
	a.root->left = new Node(9);
	
	//cout<<a.check();
	
	cout<< a.isBst(a.root);
	
	
}
