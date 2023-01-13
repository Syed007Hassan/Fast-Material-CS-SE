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
   
   //Displaying in BST
   
   void display(){
   	 cout<<"Displaying tree in inorder: "<<endl<<endl;;
   	 inorder(root);
   	 cout<<endl<<endl;
//   	 cout<<"Displaying tree in preorder: "<<endl<<endl;;
//   	 preorder(root);
//   	 cout<<endl<<endl;
//   	 cout<<"Displaying tree in postorder: "<<endl<<endl;;
//   	 postorder(root);
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
   
   //MIN MAX IN BST
   
   void MinandMax(){
   	 Node *temp = min(root);
   	 Node *temp1 = max(root);
   	 
   	 cout<<"Minimum value in tree is: "<<temp->data<<endl;
   	 cout<<"Maximum value in tree is: "<<temp1->data<<endl;
   	 
   }
   
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
   
   Node *max(Node *r){
   	
   	if(r == 0){
   		return 0;
	   }
	else if(r->right == 0){
		return r;
		}
	else{
		return max(r->right);
	}	
	   
   }
   
   //Delete a particular Node is BST
   
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
		
		if(r->right == 0){
			r = r->right;
		}
		else if(r->left == 0){
			r = r->left;
		}
		
		delete temp;
	}
	
	
	   return r;
   }
   
   //Search in BST 
   
   void searchInTree(int val){
   	 Node *temp = find(val,root);
   	 
   	 if(temp->data == val){
   	 	cout<<"Node has been found "<<endl;
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
	
	bb.display();
//	
//	bb.delete_node(8);
//	bb.delete_node(12);
//	bb.display();
//
//    bb.MinandMax();
	
	bb.searchInTree(22);
}
