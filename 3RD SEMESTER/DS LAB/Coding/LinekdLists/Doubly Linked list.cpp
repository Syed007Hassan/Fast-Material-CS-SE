#include <iostream>
using namespace std;

struct node{
	int info;
	node* prev, *next;
};

class DoublyLinkedList{
	node* head, *tail;
	public:
	DoublyLinkedList(){
		head=tail=NULL;
	}
	void AddnewNode(int el){
		node* temp= new node;
		temp->info = el;
		temp->next=NULL;
		temp->prev=NULL;
	
	if(!head){
		head=tail=temp;                                                                                                                                                            
	}
	else{
		temp->next=NULL;
		temp->prev=tail;
		tail->next= temp;
		tail= temp;
		}
	}
	
	void Display(){
		node* p=head;
		while(p!=NULL){
			cout << p->info << " ";
			p = p->next;
		}
		cout << endl;
	}
	
	void AddnewNodeAtHead(int el){
		node* temp= new node;
		temp->info = el;
		temp->next=NULL;
		temp->prev=NULL;
	
	if(!head){
		head=tail=temp;                                                                                                                                                            
	}
	else{
		temp->prev= NULL;
		temp->next=head;
		head->prev=temp;
		head=temp;
		}
	}
	
	void AddnewNodeAtPos(int el, int pos){
		node* temp= new node;
		temp->info = el;
		temp->next=NULL;
		temp->prev=NULL;
	
	if(!head){
		head=tail=temp;                                                                                                                                                            
	}
	else{
		int i=0;
		node *p= head;
		while(i!=pos-1){
		i++;
		p=p->next;
		}
		temp->next= p->next;
		p->next->prev=temp;
		p->next=temp;
		temp->prev=p;
		}
	}
	
	void DeleteFromHead(){
		node *temp;
		if(!head){
		cout << "Can't delete empty list";
		}
		else{
		head->next->prev=NULL;
		temp=head;
		head=head->next;
		delete temp;
		}
	}
	
	void DeleteFromTail(){
		node *temp;
		if(!head){
		cout << "Can't delete empty list";
		}
		else{
		temp=tail;
		tail->prev->next=NULL;
		tail=tail->prev;
		delete temp;
		}
	}
	
	void DeleteFromCenter(int pos){
		node *temp;
		if(!head){
		cout << "Can't delete empty list";
		}
		else{
		int i=1;
		node* p= head;
		while(i!=pos-1){
			i++;
			p= p->next;
			}
			temp=p->next;
			p->next->next->prev=p;
			p->next=p->next->next;
			
			delete temp;
		}
	}

};

int main(){
	DoublyLinkedList l1;
	l1.AddnewNode(5);
	l1.AddnewNode(10);
	l1.AddnewNode(15);
	l1.AddnewNode(20);
	l1.Display();
	l1.AddnewNodeAtHead(1);
	l1.Display();
	l1.AddnewNodeAtPos(7,3);
	l1.Display();

	l1.DeleteFromHead();
	l1.Display();
	
	l1.DeleteFromTail();
	l1.Display();
	
	l1.DeleteFromCenter(3);
	l1.Display();
	return 0;
}
