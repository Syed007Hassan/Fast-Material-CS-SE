#include<iostream>
using namespace std;

const int TS = 250;

class Node{
	
	public:
		
		int k, v;
		Node *left;
		Node *right;
	
	
	    Node(int x , int y){
	    	k = x;
	    	v = y;
	    	left = right = 0;
		}
		
};

class BstWithHashing{
	
	Node *root;
	
	
	public:
		
		BstWithHashing(){
			root = 0;
		}
		
		int HashFunc(int key){
			return key % TS;
		}
		
		int insert(int key, int val){
			
			  int h = HashFunc(key);
			  
//			  Node *temp = search(h,root);
//			
//			if(temp->k == key){
//			   
//			    return -1; 
//			}
//			else{
//				 root = insert(h,val,root);
//			}
				  			     
			 root = insert(h,val,root);
		   
		}
		
		Node *insert(int key,int val, Node *r){
			
			if(r == 0){
				r = new Node(key,val);
			}
			else if(key < r->k ){
				r->left = insert(key,val,r->left);
			}
			else if(key > r->k ){
				r->right = insert(key,val,r->right);
		  }
		  
		  return r;
			
		}
		
		void find(int key){
			
			int h = HashFunc(key);
			Node *temp = search(h,root);
			
			if(temp->k == key){
				cout<<temp->v<<endl;
			}
			else{
				cout<<"key not found "<<endl;
			}
			
		
		}
		
		Node *search(int key,Node *r){
			
			if(r == 0){
				return 0;
			}
			else if(key > r->k){
				return search(key,r->right);
			}
			else if(key < r->k){
				return search(key,r->left);
			}
			
			return r;
			
		}
	
};

int main(){
	
	BstWithHashing h;
	
	h.insert(1,3);
	h.insert(2,4);
	h.find(2);
	
	
}
