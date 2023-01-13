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
		
		void Swap(){
			node* p=head, *q= tail;
			node* t1= p->next;
			node* t2= q->prev;
			q->next=t1;
			q->prev=NULL;
			t1->prev=q;
			t2->next= p;
			p->next= NULL;
			p->prev=t2;

			tail=p;
			head=q;
			
		}
};

int main(){
	linkedlist l1;
	l1.AddNewnode(1);
	l1.AddNewnode(2);
	l1.AddNewnode(4);
	l1.AddNewnode(3);
	l1.Display();
	l1.Swap();
	l1.Display();
}
