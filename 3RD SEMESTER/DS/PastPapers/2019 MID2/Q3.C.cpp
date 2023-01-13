#include <iostream>
using namespace std;

struct node{
	int info;
	node* prev;
	node* next;
};

class linkedlist{
	node* head, *tail;
	public:
		linkedlist(){
			head= tail= NULL;
		}
		void AddNewnode(int el){
			node* temp= new node;
			temp->info= el;
			temp->next= NULL;
			temp->prev= NULL;
			if(!head){
				head= tail= temp;
			}
			else{
				tail->next= temp;
				temp->prev= tail;
				tail= tail->next;
			}
		}
		void Display(){
			node* p=head;
			while(p){
				cout << p->info << " ";
				p=p->next;
			}
			cout << endl;
		}
		
		void Swap(int el1, int el2){
			node* p = head;
			while(p->next->info != el1){
				p=p->next;
			}
			node* t1= p;
			p=p->next;
			
			node* q= head;
			while(q->next->info != el2){
				q=q->next;
			}
			q=q->next;
			node* t2= q->next;
			
			t1->next= q;
			q->prev= t1;
			q->next= p;
			p->next= t2;
			p->prev=q;
		}
};

int main(){
	linkedlist l1;
	l1.AddNewnode(1);
	l1.AddNewnode(2);
	l1.AddNewnode(4);
	l1.AddNewnode(3);
	l1.AddNewnode(7);
	l1.AddNewnode(6);
	l1.Display();
	l1.Swap(3,7);
	l1.Display();
}
