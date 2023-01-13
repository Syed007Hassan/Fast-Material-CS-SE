#include<iostream>
#include<queue>
#include<stack>
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
			int c = 0;
		BST(){
			
			root = 0;
		}
		
		
		void insert(int val){
			root = insert(val,root);
		}
		
		Node *insert(int val,Node *r){
			
			if(r == 0){
				r = new Node(val);
			}
			
			else if(val < r->data){
				r->left = insert(val,r->left);
			}
			else if(val > r->data){
				r->right = insert(val,r->right);
			}
			
			return r;
				
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
		
		
		void remove(int val){
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
			
			else if (r->left && r->right){
				
				temp = min(r->right);
				r->data = temp->data;
				r->right = remove(r->data,r->right);
				
			}
			
			else{
				
				temp = r;
				
				if(r->right == 0){
					r= r->right;
				}
				else if(r->left == 0){
					r = r->left;
				}
				
				delete temp;
					
			}	
			
			return r;
		}
		
		
		find(int val){
			
			Node *temp = find(val,root);
			
			cout<<temp->data<<endl;
			
		}
		
		Node *find(int val, Node *r){
			
			if(r == 0){
				return 0;
			}
			else if(val < r->data){
				return find(val, r->left);
			}
			else if(val > r->data){
				return find(val, r->right);
			}
			return r;
			
		}
		
		
		void print(){
			cout<<"Inorder "<<endl;
			inorder(root);
			cout<<endl;
			cout<<"Postorder "<<endl;
			postorder(root);
			cout<<endl;
			cout<<"Preorder "<<endl;
			preorder(root);
			cout<<endl;
		}
		
	  void inorder(Node *r){
   	   
		if(r == 0){
   		return; }
	   
	    inorder(r->left);
	   // cout<<r->data<<" ";
	   c++;
	    inorder(r->right);   

   }
   
   void preorder(Node *r){
   	   
		if(r == 0){
   		return; }
	   
	    cout<<r->data<<" ";
	    preorder(r->left);
	    preorder(r->right);   

   }
   
     void postorder(Node *r){
   	   
		if(r == 0){
   		return; }
	   
	    postorder(r->left);
	    postorder(r->right); 
		cout<<r->data<<" ";  

   }
   
   
   void display(){
   	
   	 cout<<"BFS "<<endl;
   	 BFS();
   	 cout<<endl;
   	 
   	 cout<<"Iterative preorder "<<endl;
   	 
   	 iterativepreorder();  cout<<endl;
   	 
   	  cout<<"Iterative inorder "<<endl;
   	 
   	 iterativeinorder();  cout<<endl;

   }
   
   int BFS(){
   	
   	Node *r = root;
   	
   	queue<Node *> q;
   	
   	if(r != 0 ){
   	q.push(r);
   	
   	while(!q.empty()){
   	 
		 r = q.front();
		 q.pop();
		 
		 cout<<r->data<<" ";
		 
		if(r->left){
			q.push(r->left);
		} 	
   		if(r->right){
   			q.push(r->right);
		   }
   		
	   }
	   
	   
    }
   	
   }
   
    iterativepreorder(){
    	
    Node *r = root;
   	
   	stack<Node *> q;
   	
   	if(r != 0 ){
   	q.push(r);
   	
   	while(!q.empty()){
   	 
		 r = q.top();
		 q.pop();
		 
		 cout<<r->data<<" ";
		 
		 
		if(r->right != 0){
   			q.push(r->right);
		   }
   		 
		if(r->left != 0){
			q.push(r->left);
		} 	
   		
	   }
	   
	   
    }	
  	
	}
	
	
	iterativeinorder(){
    	
    Node *r = root;
   	
   	stack<Node *> q;
   	
   	while(r!= 0 || !q.empty()){
   		
   		
   		while(r!=0){
   			
   			q.push(r);
   			
   			r = r->left;
		   }
		   
		   r = q.top();
		   q.pop();
		   cout<<r->data<<" ";
   		
   		  r = r->right;
   		
	   }
   
        } 
        
        void ff(int a, int b){
        	
        	Node *temp = ancestor(a,b,root);
        	
        	if(temp){
        		cout<<temp->data;
			}
		}
		
		
		Node *ancestor(int a, int b, Node *r){
			
			if(r == 0 ){
				return 0;
			}
			else if(r->data > a && r->data > b){
				return ancestor(a,b,r->left);
			}
			else if(r->data < a && r->data < b){
				return ancestor(a,b,r->right);
			}
			else{
				return r;
		   }	
		}
		
		int count(Node *r){
			
			if(r == 0 ){
				return 0;
			}
			else{
				return (1 + count(r->left) + count(r->right) );
			}
		}
		
		bool checkcompletebst(Node *r, int i, int no){
			
			if(r == 0){
				return 1;
			}
			else if( i >= no ){
				return 0;
			}
			else{
				
				return (checkcompletebst(r->left, 2*i + 1, no) && checkcompletebst(r->right, 2*i + 2, no) );
			}
			
		}
		
		bool identicalStructure(Node *r, Node *n){
			
			if(r == 0 && n == 0){
				return 1;
			}
			else if(r!= 0 && n != 0){
				return (identicalStructure(r->left,n->left) && identicalStructure(r->right,n->right) );
			}
			else{
				return 0;
			}
				
		}
   	
   		int countleaves(Node *r){
			if(r == 0){
				return 0;
			}
			else if(r->left == 0 && r->right == 0){
		             return 1;	
			}else{
					return (countleaves(r->left) + countleaves(r->right) );
			}	
			
		}
	
   
   
};

int main(){
	
	BST b,b2;
	
	b.insert(10);
	b.insert(9);
	b.insert(11);
	
	b2.insert(15);
	b2.insert(21);
	b2.insert(6);
	b2.insert(11);
	
	b2.inorder(b2.root);
	cout<<b2.c<<endl;

    
//	b.remove(9);
//	b.print();
	
  //  b.find(9);
  
 // b.display();
 
  //   b.ff(11,6);
	 cout<<endl;
 
int no = b.count(b.root);

  
 // cout<<b.checkcompletebst(b.root,0,no);
  
  cout<<endl;
  
  
  //cout<<b.identicalStructure(b.root,b2.root);
    
     cout<<endl;
     
     cout<<b.countleaves(b.root)<<endl;
	
}

