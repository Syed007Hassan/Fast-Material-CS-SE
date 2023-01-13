#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *lchild;
	Node *rchild;
};

class BST{
	Node* root;
public:
	
	BST(){
		root = NULL;
	}
	Node* Search(Node* p, int key){
		if(p==NULL)
			return p;
		if(p->data == key)
			return p;
		if(key > p->data)
			return Search(p->rchild,key);
		else
			return Search(p->lchild,key);
	}
	
	void Insert(int key){
		Node* t = root;
		Node* r;
		Node* temp;
		
		if(root==NULL){
			temp = new Node;
			temp->data = key;
			temp->lchild = temp->rchild = NULL;
			root = temp;
			return;
		}
		while(t){
			r = t;
			if(t->data == key)
				return;
			if(key > t->data)
				t= t->rchild;
			else
				t= t->lchild;
		}
		temp = new Node;
		temp->data = key;
		temp->lchild = temp->rchild = NULL;
		if(key > r->data)
			r->rchild = temp;
		else
			r->lchild = temp;
	}
	
	void InOrder(Node* ptr){
		if(ptr){
			InOrder(ptr->lchild);
			cout << ptr->data << " ";
			InOrder(ptr->rchild);
		}
	}
	Node* getRoot(){
		return root;
	}
};

int main(){
	BST T;
	T.Insert(1);
	T.Insert(2);
	T.Insert(7);
	T.Insert(20);
	T.Insert(13);
	T.Insert(25);
	T.Insert(17);
	T.InOrder(T.getRoot());
}
