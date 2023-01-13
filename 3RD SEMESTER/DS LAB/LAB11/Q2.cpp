#include<iostream>
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

    //Returns the min left node
    Node *min(Node *r){
   	
   	if(r == 0){
   		return 0;
	   }
	else if(r->left == 0){
		return r;
		}
	else{
		return min(r->left);
	}	
	   
   }

   //Deletion like BST then update height for balancing the tree
    void delete_node(int val){
   	   root = remove(val,root);
   }
   
   Node *remove(int val,Node *r){
   	
   	Node *temp;
   	if(r == 0){
   		return 0;
	   }
	else if(val < r->data){
		r->left = remove(val,r->left);
	}
	else if(val > r->data){
		r->right = remove(val,r->right);
	}
	else if(r->left && r->right){
		
		temp = min(r->right);
		r->data = temp->data;
		r->right = remove(r->data, r->right);
	}
	
	else{
		
		temp = r;
		r->height = 1 + max(heightFinder(r->left),heightFinder(r->right));
	
		if(r->right == 0){
			r = r->right;
		}
		else if(r->left == 0){
			r = r->left;
		}
		
		delete temp;
	}
	

    int balancing_Factor = checkBalance(r);
     // Right rotation to be performed as nodes alligned to the left
    if (balancing_Factor > 1 && checkBalance(r->left) >= 0){
        return RightRotation(r);
		
		}
		
       // Left rotation to be performed as nodes alligned to the right
    if (balancing_Factor < -1 && checkBalance(r->right) <= 0 ){
        return LeftRotation(r);
		
		}
 
     // LR ROTATION
    if (balancing_Factor > 1 && checkBalance(r->left) < 0){
        
		r->left = LeftRotation(r->left);
        return RightRotation(r);
		
		}
 
    //  RL ROTATION
    if (balancing_Factor < -1 && checkBalance(r->right) > 0){
       
	    r->right = RightRotation(r->right);
        return LeftRotation(r);
		
		}

    return r;
   }
   
   
   //Search in BST 
   
   void searchInTree(int val){
   	 Node *temp = find(val,root);
   	 
   	 if(temp->data == val){
   	 	cout<<"  Node has been found "<<endl;
		}
	  else{
	  	cout<<"Node is not there "<<endl;
	  }	
   }
   
   Node *find(int val, Node *r){
   	 if(r == 0){
   	 	return 0;
		}
	 else if(val < r->data){
	 	return find(val,r->left);
	 }
	 else if(val > r->data){
	 	return find(val,r->right);
	 }
	 cout<<r->data;
	 return r;	
   	  
   }


   void inorder(Node *r){
   	
   	if(r == 0){
   		return;
	   }
	   
	inorder(r->left);
	cout<<r->data<<" ";
	inorder(r->right);   

   } 
  
    void display(){

   	 cout<<"Displaying tree in inorder: "<<endl<<endl;;
   	 inorder(root);
   	 cout<<endl<<endl;
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
    
    bb.delete_node(20);
    bb.delete_node(16);
    
    bb.display();
    
    
    bb.searchInTree(10);
	
}
  
