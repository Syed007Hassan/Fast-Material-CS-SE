#include <iostream>
#include <conio.h>
using namespace std;

struct node{
	int info;
	node* next;
};

class linkedlist{
	node *head, *tail;
	int count;
	public:
		linkedlist(){
			head = tail = NULL;
			count=0;
		}
		
		void AddNewNode(int el){
			count++;
			node* temp= new node;
			temp->info= el;
			temp->next=NULL;
			if(!head){
				head= tail = temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
		}
		
		void Display(){
			node* temp= head;
			while(temp!=NULL){
				cout << temp->info << " ";
				temp= temp->next;
			}
			cout << endl;
		}
		
		void removeDuplicates(){
			node* p= head, *q=head;
			
			while(q!=NULL){
				int val, c=0, check=0, i=0;
				val= q->info;
				p=head;
				while(p!=NULL){
					if(p->info==val){
						c++;
					}
					p= p->next;
				}
				p=head;
				if(c>1){
					while(p!=NULL){
						if(p->info==val){
							check++;
							if(check>1){
								if(i==count){
									deletefromtail();
								}
								else{
									deletefromcenter(i);
								}
							}
						}
						i++;
						p=p->next;
					}
				}
				q=q->next;
			}
			
			
			
		}
		
		void deletefromtail(){
			node* p=head, *temp;
			while(p->next->next!=NULL){
				p=p->next;
			}
			temp=p->next;
			p->next=NULL;
			tail=p;
		}
		
		void deletefromcenter(int pos){
			node* p=head, *temp;
			int i=1;
			if(pos==i){
				temp= head;
				head= head->next;
				delete temp;
			}
			else{
				while(i!= pos-1){
					i++;
					p= p->next;
				}
				
				temp=p->next;
				p->next=p->next->next;
//				delete temp;
			}
			
		}
};

int main(){
	linkedlist l1;
	l1.AddNewNode(3);
	l1.AddNewNode(5);
	l1.AddNewNode(5);
	l1.AddNewNode(8);
	l1.AddNewNode(8);
	l1.AddNewNode(8);
	
	l1.Display();
	l1.removeDuplicates();
	l1.Display();
	return 0;
}

