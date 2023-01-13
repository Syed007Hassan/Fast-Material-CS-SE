#include<iostream>
#include <stack>
using namespace std;

class Node{
	
	public:
		int data;
		int height;
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
   
   //Inserting in AVL like BST
   
   //Returns the height of the tree
     int heightFinder(Node *n){
  	if(n == 0)
  		return 0;
	
		return n->height;
  }
  
  //Returns max of two heights given 
     int max(int a, int b){    
    return (a > b)? a : b;
	}

   //Checks whether left-sub tree is heavier or right one 
    int checkBalance(Node *r){
 	if(r == 0){
 		return 0;
	 }
	 else{
	 	return ( heightFinder(r->left) - heightFinder(r->right) );
	 }
   }
   
   //Insertion starts from here
    void insert(int x) {
        root = insert(x, root);
    }

   Node *insert(int val,Node *r){
   	
   	if( r == 0){
   		r = new Node(val);
   		r->height = 1;
	   }
	   
	else if(val < r->data){
		r->left = insert(val,r->left);
	}
	
	else if(val > r->data){
		r->right = insert(val,r->right);
	}
	else{
			return r;  
		
	}
    
	r->height = 1 + max(heightFinder(r->left),heightFinder(r->right));   //updating height of ancestor
	
	int balancing_Factor = checkBalance(r);  //checking balancing factor
    
    // Right rotation to be performed as nodes alligned to the left
    if (balancing_Factor > 1 && val < r->left->data){
	
        return RightRotation(r);
		
		}
		
     // Left rotation to be performed as nodes alligned to the right
    if (balancing_Factor < -1 && val > r->right->data){
	
        return LeftRotation(r);
		
		}
 
     // LR ROTATION
    if (balancing_Factor > 1 && val > r->left->data){
        
		r->left = LeftRotation(r->left);
        return RightRotation(r);
		
		}
 
    //  RL ROTATION
    if (balancing_Factor < -1 && val < r->right->data){
       
	    r->right = RightRotation(r->right);
        return LeftRotation(r);
		
		}

    return r;
   	
   }
   
   Node *RightRotation(Node *y){
	Node *x = y->left;         //   y             x
	Node *z = x->right;        //  x            n   y
	                           // n  z             z
	x->right = y;
	y->left = z; 
	
	
    y->height = max(heightFinder(y->left) , heightFinder(y->right)) + 1;
    x->height = max(heightFinder(x->left) , heightFinder(x->right)) + 1;

    return x;
}
 

   Node *LeftRotation(Node *x){
	Node *y = x->right;  // x            y
	Node *z = y->left;  //   y        x    n
 	                   //  z   n       z
	y->left = x;
	x->right = z;
	
    x->height = max(heightFinder(x->left) , heightFinder(x->right)) + 1;
    y->height = max(heightFinder(y->left) , heightFinder(y->right)) + 1;

    return y;
}

    //Displaying in BST
   
   void display(){
   	 cout<<"DEPTH FIRST"<<endl;
   	 cout<<"Displaying tree in inorder: "<<endl<<endl;;
   	 inorder(root);
   	 cout<<endl<<endl;
   	 cout<<"Displaying tree in preorder: "<<endl<<endl;;
   	 preorder(root);
   	 cout<<endl<<endl;
   	 cout<<"Displaying tree in postorder: "<<endl<<endl;;
   	 postorder(root);
   	 cout<<endl<<endl;
   	 cout<<"BREADTH FIRST"<<endl;
   	 
   	 int h = heightFinder(root);
   	 for(int i=0;i<=h;i++){
   	 levelorder(root,i);
      }
   }
	
   void inorder(Node *r){
   	
   	if(r == 0){
   		return;
	   }
	   
	inorder(r->left);
	cout<<r->data<<" ";
	inorder(r->right);   

   }
   
   void preorder(Node *r){
   	
   		if(r == 0){
   		return;
	   }
	   
	cout<<r->data<<" ";   
	preorder(r->left);
	preorder(r->right);   
   	
   }
   
    void postorder(Node *r){
   	
   		if(r == 0){
   		return;
	   }
	     
	postorder(r->left);
	postorder(r->right);
	cout<<r->data<<" ";    
   	
   }
   
   void levelorder(Node *r,int level){
   	
	   if(r==0){
   		return;
	   }
	if(level  == 1){
		cout<<r->data<<" ";
	}
	else if( level > 1){
	
		levelorder(r->left,level-1);
		levelorder(r->right,level - 1);
	} 

	   
   }
 

    
    
};


int main(){
	
	BT bb;

	bb.insert(15);
	bb.insert(10);
	bb.insert(20);
    bb.insert(8);
    bb.insert(12);
    bb.insert(16);
    bb.insert(25);
    bb.insert(31);
    bb.insert(40);
    

    bb.display();
    
   
}
  
