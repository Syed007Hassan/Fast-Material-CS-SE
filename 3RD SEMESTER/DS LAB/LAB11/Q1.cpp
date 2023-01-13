#include<iostream>
#include <stack>
using namespace std;

class Node{
	
	public:
		int data;
		char c;
		int height;
		Node *left;
		Node *right;
	
	
	Node(int val,char cc){
		data = val;
		c = cc;
		left = right = 0;
	}
	
};

class BT{
	
	Node *root;
	int w,m;
	public:
		
   BT(){
   	root = 0;
   	w= m =0;
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
    void insert(int x,int cc) {
        root = insert(x,cc, root);
    }

   Node *insert(int val, char cc,Node *r){
   	
   	if( r == 0){
   		r = new Node(val,cc);
   		r->height = 1;
   		
   		
   		
	   }
	   
	else if(val < r->data){
		r->left = insert(val,cc,r->left);
	}
	
	else if(val > r->data){
		r->right = insert(val,cc,r->right);
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


   void Update(int val){
   	 Node *temp = find(val,root);
   	 cout<<endl;
   	 cout<<"Client with id: "<<val<<" was "<<temp->c<<endl;
   	 if(temp->data == val){
   	 	cout<<"Node has been found "<<endl;
   	 	temp->c = 'M';
   	 	 cout<<"Client with id: "<<val<<" is now "<<temp->c<<endl;
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
	
	 return r;	
   	  
   }
   
   
   FindDiff(int k){
   	   diff(k,root);
   	   
   	   	cout<<"WOMEN "<<w<<" MEN "<<m<<endl;
   	   	cout<<"Difference is: "<<w-m<<endl;
   	   
   }
  
    void diff(int k,Node *r){
    	
    	if(r == 0){
    	return;
		}
		else{
			if(r->data < k){
				if(r->c == 'W'){
					w++;
				}
				else if(r->c == 'M'){
					m++;
				}
			}
			
			diff(k,r->left);
			diff(k,r->right);
		}
		
	}
	
   
    
    
};


int main(){
	
	BT bb;

	bb.insert(15,'W');
	bb.Update(15);
	
	bb.insert(16,'W');
	bb.insert(17,'M');
	bb.insert(18,'M');
	
	bb.FindDiff(20);
    
   
}
  
