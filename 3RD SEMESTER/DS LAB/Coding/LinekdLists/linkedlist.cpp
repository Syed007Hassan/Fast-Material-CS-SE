#include <iostream>
using namespace std;

struct node{
	int info;
	node* next;
};

class linkedlist{
	node *head, *tail;
	public:
		linkedlist(){
			head=tail=NULL;
		}
		void AddNewNode(int el){
			node* temp = new node;
			temp->info = el;
			temp->next = NULL;
			if(!head){
				head= temp;
				tail= temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
		}
		
		void AddNewNodeToHead(int el){
			node* temp = new node;
			temp->info = el;
			temp->next= NULL;
			if(!head){
				head= temp;
				tail= temp;
			}
			else{
				temp->next= head;
				head= temp;
			}
		}
		
		void AddNewNodeToTail(int el){
			node* temp = new node;
			temp->info = el;
			temp->next= NULL;
			if(!head){
				head= temp;
				tail= temp;
			}
			else{
				tail->next= temp;
				tail = temp;
			}
		}
		
		void AddNewNodeToCenter(int pos, int el){
			node* temp = new node;
			temp->info = el;
			temp->next= NULL;
			node *p= head;
			if(!head){
				head= temp;
				tail= temp;
			}
			else{
				int i=0;
				while(i!=pos-1){
					i++;
					p= p->next;
				}
				temp->next= p->next;
				p->next= temp;
			}
		}
		
		void DeleteFromHead(){
			node* temp= head;
			head= head->next;
			delete temp;
		}
		
		void DeleteFromTail(){
			node* temp;
			node* p = head;
			
			if(head==NULL){
				temp= head;
				head= tail= NULL;
				delete temp;
			}
			else{
				while(p->next->next != NULL){
					p = p->next;
				}
				temp= p->next;
				p->next= NULL;
				tail=p;
				delete temp;
			}
			
		}
		
		void DeleteFromCenter(int pos){
			node* temp;
			node *p= head;
			if(!head){
				temp= head;
				head=tail=NULL;
				delete temp;				
			}
			else{
				int i=0;
				while(i!= pos-1){
					i++;
					p = p->next;
				}
				p->next = p->next->next;
			}
		}
		
		void display(){
			node* temp= head;
			while(temp!=NULL){
				cout << temp->info << " ";
				temp= temp->next;
			}
			cout << endl;
		}
};

int main(){
	linkedlist l1;
	l1.display();
	l1.AddNewNode(10);
	l1.display();
	l1.AddNewNode(20);
	l1.display();
	l1.AddNewNodeToHead(90);
	l1.display();
	l1.AddNewNodeToTail(50);
	l1.display();
	l1.AddNewNodeToCenter(2,15);
	l1.display();
	l1.DeleteFromHead();
	l1.display();
	l1.DeleteFromTail();
	l1.display();
	l1.DeleteFromCenter(1);
	l1.display();
	return 0;
}
