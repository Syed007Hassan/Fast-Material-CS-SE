#include <iostream>
using namespace std;

struct node{
	int info;
	node* next;
};

class circularlinekdlist{
	node* head, *tail;
	public:
		circularlinekdlist(){
			head=NULL;
		}
		void AddnewNote(int el){
			node *temp= new node;
			temp->info=el;
			if(!head){
				head=temp;
				temp->next=head;
			}
			else{
				node* p=head;
				while(p->next!=head){
					p=p->next;
				}
				p->next=temp;
				temp->next=head;
			}
		}
		void AddNewNodeAtHead(int el){
			node* temp= new node;
			temp->info= el;
			temp->next=head;
			if(!head){
				head=temp;
			}
			else{
				node* p=head;
				while(p->next!=head){
					p=p->next;
				}
				p->next=temp;
				head=temp;
			}
		}
		
		void DeleteFromHead(){
			node* p=head, *temp;
			while(p->next!=head){
				p=p->next;
			}
			temp=head;
			head=head->next;
			p->next=head;
		}
		
		void DeleteFromTail(){
			node* p=head, *temp;
			while(p->next->next!=head){
				p=p->next;
			}
			temp=p->next;
			p->next=head;
			delete temp;
		}
		void Display(){
			node* p=head;
			do{
				cout << p->info << " ";
				p= p->next;
			}while(p!=head);
			cout << endl;
		}
	int countNodes(){
		node *t = head;
		
		if(!head)	
			return 0;
		int count = 0;
		do{
			count++;
//			if(t->next!=head)
				t=t->next;
		}while(t!=head);
		return count;
	}
};

int main(){
	circularlinekdlist l1;
	l1.AddnewNote(10);
	l1.AddnewNote(20);
	l1.AddnewNote(30);
	l1.Display();
	l1.AddNewNodeAtHead(5);
	l1.Display();
	cout << l1.countNodes();
	
//	l1.DeleteFromHead();
//	l1.Display();
//	l1.DeleteFromTail();
//	l1.Display();
	return 0;
}
