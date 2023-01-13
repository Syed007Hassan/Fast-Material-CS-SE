#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};

class BinarySearchTree{
	
public:
	Node* root;
	
	BinarySearchTree(){
		root=NULL;
	}
	void insert(int key){
		Node* t = root, *r, *p;
		if(root==NULL){
			p = new Node;
			p->data= key;
			p->lchild = p->rchild = NULL;
			root = p;
			return;
		}
		while(t!=NULL){
			r=t;
			if(key<t->data)
				t= t->lchild;
			else if(key > t->data)
				t=t->rchild;
			else
				return;
		}
		p = new Node;
		p->data= key;
		p->lchild = p->rchild = NULL;
		
		if(key<r->data)	r->lchild = p;
		else r->rchild = p;
	}
	
	void InOrder(struct Node* p){
		
		if(p){
			InOrder(p->lchild);
			cout << p->data << " ";
			InOrder(p->rchild);
		}
	}
	Node* getRoot(){
		return root;
	}
	
	Node* Search(int key){
		Node* t = root;
		while(t!=NULL){
			if(key==t->data)
				return t;
			else if (key<t->data)
				t = t->lchild;
			else
				t = t->rchild;
		}
		return NULL;
	}
	
	Node* RInsert(Node* p, int key){
		Node* t= NULL;
		
		
		if(p==NULL){
			t = new Node;
			t->data = key;
			t->lchild = t->rchild = NULL;
			return t;
		}
		if(key<p->data)
			p->lchild= RInsert(p->lchild, key);
		else if(key> p->data)
			p->rchild= RInsert(p->rchild, key);
		return p;
		
	}
	
	Node *findlca(Node *p, int n1, int n2){
		if(!p)
			return NULL;
		if(p->data == n1 || p->data == n2)
			return p;
		
		Node *left_lca = findlca(p->lchild, n1,n2);
		Node *right_lca = findlca(p->rchild, n1,n2);
		
		if(left_lca && right_lca)
			return p;
		
		return (left_lca !=NULL) ? left_lca : right_lca;
	}
	
};

int main(){
	BinarySearchTree B1;
	B1.root = B1.RInsert(B1.getRoot(), 50);
	B1.RInsert(B1.getRoot(),17);
	B1.RInsert(B1.getRoot(),72);
	B1.RInsert(B1.getRoot(),12);
	B1.RInsert(B1.getRoot(), 23);
	B1.RInsert(B1.getRoot(), 54);
	
	B1.RInsert(B1.getRoot(), 76);
	B1.RInsert(B1.getRoot(), 67);
	B1.RInsert(B1.getRoot(), 9);
	B1.RInsert(B1.getRoot(), 14);
	B1.RInsert(B1.getRoot(), 19);
	
//	B1.InOrder(B1.getRoot());
	
	Node *p = B1.findlca(B1.root,14,23);
	cout << p->data << endl;
	return 0;
}
