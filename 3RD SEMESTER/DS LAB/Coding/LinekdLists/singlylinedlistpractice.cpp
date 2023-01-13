#include <iostream>
#include <conio.h>
using namespace std;

struct node{
	int info;
	node *next;
};

class linkedlist{
	node* head, *tail;
	int count;
	public:
		linkedlist(){
			head= tail= NULL;
			count=0;
		}
		void display(){
			node *p=head;
			while(p!=NULL){
				cout << p->info << " ";
				p= p->next;
			}
			cout << endl;
		}
		void AddnewNode(int el){
			count++;
			node *temp= new node;
			temp->info= el;
			temp->next=NULL;
			if(!head){
				head=tail=temp;
			}
			else{
				node* p=head;
				while(p->next!=NULL){
					p=p->next;
				}
				p->next=temp;
				tail=temp;
			}
		}
		void AddnewNodeAtHead(int el){
			count++;
			node *temp= new node;
			temp->info= el;
			temp->next=NULL;
			if(!head){
				head=tail=temp;
			}
			else{
				temp->next=head;
				head=temp;
			}
		}
		void AddNewNodeAtCenter(int pos, int el){
			count++;
			if(pos==1){
				AddnewNodeAtHead(el);
			}
			else{
				int i=0;
				node * temp= new node;
				temp->info= el;
				temp->next=NULL;
				if(!head){
					head= temp= NULL;
				}
				else{
					node *p=head;
					while(i!=pos-1){
						i++;
						p=p->next;
					}
					temp->next = p->next;
					p->next= temp;
				}
			}
		}
		void deletefromHead(){
			node *temp;
			node *p=head;
			temp=head;
			head= head->next;
			delete temp;
			
		}
		
		void deletefromTail(){
			node *temp, *p=head;
			while(p->next->next!=NULL){
				p=p->next;
			}
			temp= p->next;
			p->next=NULL;
			delete temp;
		}
		void deletefromcenter(int pos){
			int i=0;
			node* p = head, *temp;
			while(i!=pos-1){
				i++;
				p=p->next;
			}
			temp= p->next;
			p->next= p->next->next;
//			delete temp;
		}
				
		
		void reverse(){
			node *pp, *np, *cp;
			pp=0;
			np=cp=head;
			while(np!=NULL){
				np= np->next;
				cp->next=pp;
				pp = cp;
				cp = np;
			}
			head= pp;
		}
		
		void removeDuplicates(){
			node *p=head, *q=head;
			while(q!=NULL){
				int val= q->info;
				int c=0, check=0, i=0;
				while(p!=NULL){
					if(p->info==val){
						c++;
					}
					p=p->next;
				}
				p=head;
				if(c>0){
					while(p!=NULL){
						if(p->info==val){
							check++;
							if(check>1){
								if(i==count)
									deletefromTail();
								else
									deletefromcenter(i);
							}
						}	
						i++;
						p=p->next;
					}
				}
				q=q->next;
			}
		}
};

int main(){
	linkedlist l1;
	l1.AddnewNode(1);
	l1.AddnewNode(3);
	l1.AddnewNode(5);
	l1.AddnewNodeAtHead(5);
	l1.AddNewNodeAtCenter(2,7);
	l1.AddNewNodeAtCenter(2,3);
	l1.display();
	
	l1.removeDuplicates();
	l1.display();
	return 0;
}
