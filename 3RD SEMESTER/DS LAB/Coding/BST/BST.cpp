#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};

class BinarySearchTree{
	Node* root;
public:
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
};

int main(){
	BinarySearchTree B1;
	B1.insert(10);
	B1.insert(5);
	B1.insert(20);
	B1.insert(8);
	B1.insert(30);
	
	B1.InOrder(B1.getRoot());
	
	Node* temp = B1.Search(100);
	if(temp){
		cout << "\nElement " << temp->data << " found.\n";
	}
	else{
		cout << "\nElement is not found.\n";
	}
	return 0;
}
