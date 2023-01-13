#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class linkedlist{
	public:
	node *head, *tail;
	
	linkedlist(){
		head= tail= NULL;
	}
	void AddnewNode(int el){
		node * temp= new node;
		temp->info=el;
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
		while(p!=NULL){
			cout << p->info << " ";
			p=p->next;
		}
		cout << endl;
	}

	
	void swap(node *t1, node *t2){
		node *p=head;
		node *temp1, *temp2, *temp3, *temp4;
		while(p->next!=t1){ 
			p=p->next;
		}
		temp1= p;
		temp2= t1->next;
		
		p=head;
		while(p->next!=t2){
			p=p->next;
		}
		temp3= p;
		temp4= t2->next;
		t2->next= temp2;
		temp1->next= t2;
		temp2->next= t1;
		t1->next= temp2;
		
	}
	
	void SortLinkedList(){
		node *p= head;
		while(p!=NULL){
			node *q= p->next;
			while(q!=NULL){
				if(p->info > q->info){
					cout << "yes " << p->info << " " << q->info << endl;
					swap(p,q);
				}
				q=q->next;
			}
			p=p->next;
		}
	}
};

int main(){
	linkedlist l1;
	l1.AddnewNode(5);
	l1.AddnewNode(10);
	l1.AddnewNode(3);
	l1.AddnewNode(7);
	l1.AddnewNode(9);
	l1.AddnewNode(6);
	l1.Display();
//	l1.SortLinkedList();
	l1.swap(l1.head->next->next, l1.head->next->next->next->next);
	l1.Display();
}
