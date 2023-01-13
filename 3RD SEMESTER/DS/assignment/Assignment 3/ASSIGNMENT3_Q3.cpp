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

class BT{
	
	Node *root;
	
	public:
		
   BT(){
   	root = 0;
   }
   
   //Inserting in BST
   
    void insert(int x) {
        root = insert(x, root);
    }

   Node *insert(int val,Node *r){
   	
   	if( r == 0){
   		r = new Node(val);
   		r->left = r->right = 0;
	   }
	   
	else if(val < r->data){
		r->left = insert(val,r->left);
	}
	
	else if(val > r->data){
		r->right = insert(val,r->right);
	}
	
	return r;      
   	
   }
   
   
   void lorder(){
   	
   	LevelOrder(root);
   	
   }
   
   
  void LevelOrder(Node *r){
 	
 	Node *n = r;
 	Node *q;
 	Node *p;
 	Node *x,*y;
 	
 	if(r!= 0){
 		cout<<r->data<<" "<<r->data<<endl;
 		
 		while(r->left || r->right || n->right || n->left ){
 			
 			if(r->left){	
 			cout<<r->left->data<<" ";
 			
 			x = r->left;
 			
 			if(x->left){
 				
 				if(x->left->right == 0 && x->left->left == 0 ){
 					if(x->right->left){
 						y = x->right->left;
					 }
					 else{
					 	y = x->right->right;
					 }
				 }
			 }
 			
 			r = r->left;
 			
 		   }
 		   else if(r->left == 0 && r->right != 0){
 	
 				cout<<r->right->data<<" ";
 				r = r->right;
			 }
			 
			else if(r->right == 0 && r->left == 0 ){
 		 
 			  cout<<y->data<<" ";
 			  r = y;
			 } 
  
  			 
   
 		   if(n->right){
 			cout<<n->right->data<<" ";
 			q = n->right;
 			
 			if(q->right){
 				
 				if(q->right->right == 0 && q->right->left == 0 ){
 					if(q->left->right){
 						p = q->left->right;
					 }
					 else{
					 	p = q->left->left;
					 }
				 }
			 }
 			
 			n = n->right;
 			
 		   }
 		   
 		   else if(n->right == 0 && n->left !=0){
 		 
 			  cout<<n->left->data<<" ";
 			  n = n->left;
			 }
			 
		   else if(n->right == 0 && n->left == 0 ){
 		 
 			  cout<<p->data<<" ";
 			  n = p;
			 }
			 	 
 		   
 		   cout<<endl;
 		   
		 }
		 
		 
	 }
 	
 }
 

};


int main(){
	
	

 int n;
 cin>>n;
 int arr[n];
 
 BT bb;

for(int i=0;i<n;i++){
	cin>>arr[i];
}

for(int i=0;i<n;i++){
	bb.insert(arr[i]);
}

    bb.lorder();
   // bb.printLevelOrder();
}
