#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* lchild;
	Node* rchild;
};

class Queue{
private:
	int front;
	int rear;
	int size;
	Node **Q;
public:
	Queue(){
		front = rear = -1;
		size = 10;
		Q = new Node*[size];
	}
	Queue(int size){
		front = rear = -1;
		this->size = size;
		Q= new Node*[this->size];
	}
	void Enqueue(Node* x){
		if(rear==size-1)
			cout << "Queue is full";
		else
			Q[++rear] = x;
	}
	Node* dequeue(){
		Node* x= NULL;
		if(front == rear){
			cout << "Queue is empty";
		}
		else{
			x = Q[++front];
		}
		return x;
	}
	void Display(){
		for(int i=front+1; i<=rear; i++){
			cout << Q[i] << " ";
		}
		cout << endl;
	}
	bool isEmpty(){
		if(front == rear)
			return true;
		return false;
	}
};

class Tree{
public:
	Node* root;
	int *temp;
	Tree(){ root= NULL;}
	void CreateTree(){
		Node *p, *t;
		int x;
		Queue q(100);
		
		cout << "Enter root value : ";
		cin >> x;
		root = new Node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		q.Enqueue(root);
		
		while(!q.isEmpty()){
			p=q.dequeue();
			cout << "Enter the value for lchild for " << p->data << ":\t";
			cin >> x;
			if(x!=-1){
				t = new Node;
				t->data = x;
				t->lchild = t->rchild = NULL;
				p->lchild = t;
				q.Enqueue(t);
			}
			
			cout << "Enter the value for rchild for " << p->data << ":\t";
			cin >> x;
			if(x!=-1){
				t = new Node;
				t->data = x;
				t->lchild = t->rchild = NULL;
				p->rchild = t;
				q.Enqueue(t);
			}
		}
	}
	
	int countNodes(Node *p){
		if(!p)
			return 0;
		int x, y;
		x = countNodes(p->lchild);
		y = countNodes(p->rchild);
		return x+y+1;
	}
	void PreOrder(Node *p){
		if(p){
			cout << p->data << " ";
			PreOrder(p->lchild);
			PreOrder(p->rchild);
		}
	}
	
	void CreateTemp(){
		int size = countNodes(root);
		temp = new int[size];
	}
	void InOrder(Node *p){
		static int i = 0;
		if(p){
			InOrder(p->lchild);
			cout << p->data << " ";
			temp[i++] = p->data;
			InOrder(p->rchild);
		}
	}
	void PostOrder(Node *p){
		if(p){
			PreOrder(p->lchild);
			PreOrder(p->rchild);
			cout << p->data << " ";
		}
	}
	int Height(Node *p){
		int x= 0, y=0;
		if(!root)
			return 0;
		x= Height(root->lchild);
		y = Height(root->rchild);
		if(x>y)
			return x+1;
		else
			return y+1;
	}
	
	bool isBST(){
		
		int min = temp[0];
		for(int i=1; i< countNodes(root); i++){
			if(temp[i] < min)
				return false;
		}
		return true;
	}
};

//bool isBST(Tree* BT){
//	
//	Node *p = BT->root;
//	
//	if(!p->lchild && !p->rchild)
//	{
//		
//	}
//	else if(p->lchild && p->rchild){
//		if ((p->lchild->data < p->data) && (p->rchild->data > p->data)){
//			isBST(p->lchild);
//			isBST(p->rchild);
//			return true;
//		}
//		else{
//			return false;
//		}
//	}
//	else if(p->lchild && !p->rchild){
//		if(!(p->lchild->data < p->data))
//			return false;
//	}
//	else if(p->rchild && !p->lchild){
//		if(!(p->rchild > p->data))
//			return false;
//	}
//}

int main(){
	Tree T;
	T.CreateTree();
	T.CreateTemp();
//	T.PreOrder(T.root);
//	cout << endl;
	T.InOrder(T.root);
	cout << T.isBST();
//	cout << endl;
//	T.PostOrder(T.root);
//	cout << endl;
	
//	cout << isBST(&T);
	return 0;
}
