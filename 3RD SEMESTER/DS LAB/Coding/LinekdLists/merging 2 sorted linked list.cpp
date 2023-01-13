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
		
		void MergeList(linkedlist l2){
			node *p= head;
			node *q= l2.head;
			int count2= l2.count;
			
			while(q){
				int check= q->info;
				int i=0;
				
				p= head;
				while(p){
					if(check >= p->info){
						i++;
					}
					else{
						AddNewNodeAtCenter(check,i);
						break;
					}
					p=p->next;
				}
				q=q->next;
			}
		}
		
};

int main(){
	linkedlist l1;
	l1.AddNewNodeAtTail(1);
	l1.AddNewNodeAtTail(3);
	l1.AddNewNodeAtTail(7);
	
	linkedlist l2;
	l2.AddNewNodeAtTail(1);
	l2.AddNewNodeAtTail(2);
	
	l1.MergeList(l2);
	l1.display();
	
	return 0;
}
