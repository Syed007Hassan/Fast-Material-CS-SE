#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* lchild;
	Node* rchild;
};

class BST{
public:
	Node* root;
	
	BST(){
		root = NULL;
	}
	void InOrder(Node* p){
		if(p){
			InOrder(p->lchild);
			cout << p->data << " ";
			InOrder(p->rchild);
		}
	}
	
	Node* Insert(Node* p, int key){
		Node* t= NULL;
		
		if(p==NULL){
			t= new Node;
			t->data = key;
			t->lchild = t->rchild = NULL;
			return t;
		}
		if(key < p->data)
			p->lchild = Insert(p->lchild, key);
		else if(key > p->data)
			p->rchild = Insert(p->rchild, key);
		return p;
	}
	
	int Height(Node* p){
		int x,y;
		if(p==NULL) return 0;
		x= Height(p->lchild);
		y= Height(p->rchild);
		return x>y? x+1: y+1;
	}
	
	Node* InPre(Node* p){
		while(p!=NULL && p->rchild!=NULL){
			p = p->rchild;
		}
		return p;
	}
	
	Node* InSuc(Node* p){
		while(p!=NULL && p->lchild!=NULL){
			p = p->lchild;
		}
		return p;
	}
	
	Node* Delete(Node* p, int key){
		Node* q;
		
		if(p==NULL)
			return NULL;
		if(p->lchild==NULL && p->rchild==NULL){
			if(p==root)
				root = NULL;
			delete p;
			return NULL;
		}
		
		if(key > p->data)
			p->rchild =  Delete(p->rchild, key);
		else if(key < p->data)
			p->lchild = Delete(p->lchild, key);
		else{
			if(Height(p->lchild)> Height(p->rchild)){
				q= InPre(p->lchild);
				p->data = q->data;
				p->lchild = Delete(p->lchild, q->data);
			}
			else{
				q= InSuc(p->rchild);
				p->data = q->data;
				p->rchild = Delete(p->rchild, q->data);
			}
		}
		return p;
	}
	
	
};

int main(){
	BST T;
	T.root= T.Insert(T.root, 50);
	T.Insert(T.root, 10);
	T.Insert(T.root, 40);
	T.Insert(T.root, 20);
	T.Insert(T.root, 30);
	
	T.InOrder(T.root);
	cout << endl;
	Node* temp = T.Delete(T.root,50);
	T.InOrder(T.root);
	return 0;
}
