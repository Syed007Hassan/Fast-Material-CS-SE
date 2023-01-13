#include <iostream>
#include <conio.h>
using namespace std;

struct node{
	int info;
	node* next;
};

class linkedlist{
	node *head, *tail;
	public:
		linkedlist(){
			head = tail = NULL;
		}
		
		void AddNewNode(int el){
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
		
		void swap(int el){
			node* temp, *p = head, * temp2;
			while(p->next->info!=el){
				p=p->next;
			}
		
			temp = p->next;
			temp2= temp->next;
			node* temp3= temp2->next;
			p->next= temp2;
			temp2->next=temp;
			temp->next= temp3;
		}
};

int main(){
	linkedlist l1;
	l1.AddNewNode(10);
	l1.AddNewNode(20);
	l1.AddNewNode(30);
	l1.AddNewNode(40);
	l1.AddNewNode(50);
	l1.Display();
	l1.swap(40);
	l1.Display();
	
	return 0;
}
