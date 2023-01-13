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
	
	int isBST(Node *r){
    	if(r == 0){
    		return 10;
		}
		
		if(r->left != 0 && r->left->data > r->data){
			return 0;
		}
		
		if(r->right != 0 && r->right->data < r->data){
			return 0;
		}
		
		if( !(isBST(r->left)) || !(isBST(r->right)) ){
			return 0;
		}
		
		return 10;
		
	}
	
	
   void inorder(Node *r){
   	
   	if(r == 0){
   		return;
	   }
	   
	inorder(r->left);
	cout<<r->data<<" ";
	inorder(r->right);   

   }
	
		
};

int main(){
   
   	
   Node *root = new Node(6);
   
   root->left = new Node(3); 
   root->right = new Node(9); 
   root->left->left = new Node(1); 
    root->left->right = new Node(5);  
	
	root->inorder(root);   
    
    if(root->isBST(root)) 
        cout<<"Is BST"<<endl; 
    else
        cout<<"Not a BST"<<endl;
    
	
	 Node *root1 = new Node(5);
   
   root1->left = new Node(2); 
   root1->right = new Node(7); 
   root1->left->left = new Node(8); 
    root1->left->right = new Node(3);  
	
	root1->inorder(root1);   
    
    if(root1->isBST(root1)) 
        cout<<"Is BST"<<endl; 
    else
        cout<<"Not a BST"<<endl;    
        
        
        
    return 0; 

}
