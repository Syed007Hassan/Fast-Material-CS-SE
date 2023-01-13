#include <iostream>
using namespace std;

struct Node{
	int data;
	int height;
	Node *lchild;
	Node *rchild;
};

class AVLTrees{
	
public:
	Node* root;
	
	AVLTrees(){
		root = NULL;
	}
	Node* RInsert(Node* p, int key){
		Node* temp = NULL;
		if(!p){
			temp = new Node;
			temp->data = key;
			temp->height = 1; // by default
			temp->lchild = temp->rchild= NULL;
			return temp;
		}
		if(p->data > key)
			p->lchild = RInsert(p->lchild,key);
		else if(p->data < key)
			p->rchild = RInsert(p->rchild,key);
		
		// new line yahan se baki purana kaam tha ab tk
		p->height = NodeHeight(p);
		if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1) // means left hand side pe hai to perform ll
			return LLRotation(p);
		else if (BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1) // means L-R rotation
			return LRRotation(p);
		else if (BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
			return RRRotation(p);
		else if (BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
			return RLRotation(p);
		
		return p;
	}
	
	Node* LLRotation(Node* p){
		Node *pl = p->lchild;
		Node *plr = pl->rchild;
		
		pl->rchild = p;
		p->lchild = plr;
		p->height = NodeHeight(p) ;
		pl->height = NodeHeight(pl);
		
		if(p==root)
			root = pl;
		
		return pl;
	}
	
	Node* RRRotation(Node* p){
		Node *pr = p->rchild;
		Node *prl = pr->lchild;
		
		pr->lchild = p;
		p->rchild = prl;
		p->height = NodeHeight(p) ;
		pr->height = NodeHeight(pr);
		
		if(p==root)
			root = pr;
		
		return pr;
	}
	Node* RLRotation(Node* p){
		Node* pr = p->rchild;
		Node* prl = pr->lchild;
		
		p->rchild = prl->rchild;
		pr->lchild = prl->lchild;
		prl->lchild= p;
		prl->rchild= pr;
		
		pr->height = NodeHeight(pr);
		p->height = NodeHeight(p);
		prl->height = NodeHeight(prl);
		
		if(root==p)
			root = prl;
		return prl;
	}
	
	Node* LRRotation(Node* p){
		Node *pl= p->lchild;
		Node *plr= pl->rchild;
		
		
		pl->rchild = plr->lchild;
		p->lchild = plr->rchild;
		plr->lchild= pl;
		plr->rchild= p;
		
		pl->height = NodeHeight(pl);
		p->height = NodeHeight(p);
		plr->height = NodeHeight(plr);
		
		if(root==p)
			root= plr;
		return plr;
	}
	
	int NodeHeight(Node* p){
		int hl, hr;
		hl = p && p->lchild? p->lchild->height:0;
		hr = p && p->rchild? p->rchild->height:0;
		
		return hl>hr ? hl+1 : hr+1;
	}
	
	int BalanceFactor(Node* p){
		int hl, hr;
		hl = p && p->lchild? p->lchild->height:0;
		hr = p && p->rchild? p->rchild->height:0;
		return hl-hr;
	}
	
	void PreOrder(Node *p){
		if(p){
			cout << p->data << " ";
			PreOrder(p->lchild);
			PreOrder(p->rchild);
		}
	}
	
	// need to implement this function later
	Node* Delete(Node* p, int key){
		Node* q;
		
		if(p==NULL)
			return NULL;
		
		if(key > p->data)
			p->rchild =  Delete(p->rchild, key);
		else if(key < p->data)
			p->lchild = Delete(p->lchild, key);
		else{
			if(p->lchild==NULL || p->rchild==NULL){
				Node* temp = p->lchild ? p->lchild: p->rchild;
				if(!temp){
					temp = p;
					root = NULL;
				}
//				else
			}
		}
	}
	
	void InOrder(Node *p){
		if(p){
			InOrder(p->lchild);
			InOrder(p->rchild);
			cout << p->info << " ";
		}
		cout << endl;
	}
};

int main(){
	AVLTrees Tree;
	// for ll rotation
//	Tree.root = Tree.RInsert(Tree.root,10);
//	Tree.RInsert(Tree.root,5);
//	Tree.RInsert(Tree.root,2);

	Tree.root = Tree.RInsert(Tree.root,1);
	Tree.RInsert(Tree.root,2);
	Tree.RInsert(Tree.root,3);

	Tree.InOrder((Tree.root));
	Tree.PreOrder(Tree.root);
}
