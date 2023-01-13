#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class linkedlist{
	node *head, *tail;
	int count=0;
	public:
		linkedlist(){
			head= tail = NULL;
		}
		void AddNewElement(int el){
			count++;
			node *temp= new node;
			temp->info= el;
			temp->next=NULL;
			if(!head){
				head= tail= temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
		}
		void displaY(){
			node *p= head;
			while(p){
				cout << p->info << " ";
				p= p->next;
			}
			cout << endl;
		}
		void deleteSum(){
			node* p = head;
			int sum=0;
			while(p){
				for(node *q= p->next; q; q=q->next){
					sum = p->info + q->info;
					if(sum==0){
						deletenode(p);
						deletenode(q);
						cout << "okay";
					}
				}
				p=p->next;
			}
		}
		void deletenode(node *p){
			if(p==head)
				DeletefromHead();
			else if(p==tail)
				DeletefromTail();
			else{
				node *t= head;
				while(t->next!=p){
					t=t->next;
				}
				node *temp= p;
				t->next= temp->next;
				delete temp;
			}
		}
		
		void DeletefromHead(){
			if(!head){
				cout << "Can't delete from empty list.\n";
			}
			else{
				node *temp= head;
				head= head->next;
				delete temp;
				count--;
			}
		}
		
		void DeletefromTail(){
			if(!head){
				cout << "Can't delete from empty list.\n";
			}
			else{
				node* p= head;
				while(p->next->next!=NULL){
					p=p->next;
				}
				node *temp= p->next;
				p->next= NULL;
				tail=p;
				delete temp;
				count--;
			}
		}
};

int main(){
	linkedlist l1;
	l1.AddNewElement(6);
	l1.AddNewElement(-6);
	l1.AddNewElement(8);
	l1.AddNewElement(4);
	l1.AddNewElement(-12);
	l1.AddNewElement(9);
	l1.AddNewElement(8);
	l1.AddNewElement(-8);
	l1.displaY();
	l1.deleteSum();
	l1.displaY();
	return 0;
}
