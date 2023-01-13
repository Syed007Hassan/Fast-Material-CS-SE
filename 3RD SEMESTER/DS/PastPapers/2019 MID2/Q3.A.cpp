#include <iostream>
using namespace std;

struct node{
	char info;
	node *next;
};

class linkedlist{
	node *head, *tail;
	public:
		linkedlist(){
			head= tail= NULL;
		}
		void AddnewNode(int el){
			node *temp= new node;
			temp->info= el;
			temp->next= NULL;
			if(!head){
				head= tail= temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
		}
		void Display(){
			node *p=head;
			while(p){
				cout << p->info << " ";
				p= p->next;
			}
			cout << endl;
		}
		
		void Copy(linkedlist l1){
			node* p= l1.head;
			while(p){
				AddnewNode(p->info);
				p=p->next;
			}
		}
		
		void Reverse(){
			node* pp, *np, *cp;
			pp= NULL;
			np= cp= head;
			
			while(np){
				np= np->next;
				cp->next = pp;
				pp= cp;
				cp= np;
			}
			head= pp;
		}
		
		bool Compare(linkedlist l1){
			node* p = l1.head;
			node* q= head;
			while(p){
				if(p->info != q->info)
					return false;
				p=p->next;
				q=q->next;
			}
			return true;
		}
		
};


int main(){
	linkedlist l1;
	l1.AddnewNode('M');
	l1.AddnewNode('A');
	l1.AddnewNode('D');
	l1.AddnewNode('A');
	l1.AddnewNode('M');
	l1.Display();
	
	linkedlist l2;
	l2.Copy(l1);
	l2.Display();
	l2.Reverse();
	cout << l2.Compare(l1);
	
	return 0;
}
