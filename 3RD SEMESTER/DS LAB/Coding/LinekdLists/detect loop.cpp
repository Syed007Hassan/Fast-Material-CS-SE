/*
//insert at head
//insert at tail
//delete at head
//delete at tail
//print
//search
//total count
average
//delete from center
//insert at center
*/

#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class linkedlist{
public:
	node *head, *tail;
	int count;
public:
		linkedlist(){
			head= tail= NULL;
			count=0;
		}
		void AddNewNodeAtTail(int el){
			count++;
			node * temp= new node;
			temp->info= el;
			temp->next= NULL;
			if(!head){
				head= tail = temp;
			}
			else{
				tail->next = temp;
				tail= tail->next;
			}
		}
		void display(){
			node *p=head;
			while(p){
				cout << p->info << " ";
				p= p->next;
			}
			cout << endl;
		}
		void AddNewNodeAtHead(int el){
			count++;
			node * temp= new node;
			temp->info= el;
			temp->next= NULL;
			if(!head){
				head= tail = temp;
			}
			else{
				temp->next= head;
				head= temp;
			}
		}
		void AddNewNodeAtCenter(int el, int pos){
			count++;
			node * temp= new node;
			temp->info= el;
			temp->next= NULL;
			if(!head){
				head= tail = temp;
			}
			else{
				int i=0;
				node* p=head;
				while(i!=pos-1){
					i++;
					p=p->next;
				}
				temp->next= p->next;
				p->next= temp;
			}
		}
		
		int getCount(){
			return count;
		}
		
		void DeletefromHead(){
			if(!head){
				cout << "Can't delete from empty list.\n";
				exit(0);
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
		
		void DeleteFromCenter(int pos){
			if(!head){
				cout << "Can't delete from empty list.\n";
				
			}
			else{
				int i=0;
				node *p= head;
				while(i!=pos-1){
					p=p->next;
					i++;
				}
				node *temp= p->next;
				p->next=temp->next;
				delete temp;
				count--;
			}
		}
		bool DetectLoop(){
			node *p= head;
			node *q= p;
			do{
				p=p->next;
				q=q->next;
				if(q!=NULL){
					q=q->next;
					if(p==q)
						return true;
				}
			}while(p&&q);
			
			return false;
		}
		
		void DeleteLinkedlist(){
			int i=0;
			while(i!=count){
				i++;
				DeletefromHead();
				display();
			}
		}		
};

int main(){
	linkedlist l1;
	l1.AddNewNodeAtTail(1);
	l1.AddNewNodeAtTail(2);
	l1.AddNewNodeAtTail(2);
	l1.AddNewNodeAtTail(4);
	l1.AddNewNodeAtTail(5);
	l1.AddNewNodeAtHead(4);
	l1.AddNewNodeAtCenter(7,2);
	l1.display();
	
	l1.tail->next= l1.head->next->next;
	
	cout << l1.DetectLoop();
//	l1.DeleteLinkedlist();
//	l1.display();
	
	return 0;
}
