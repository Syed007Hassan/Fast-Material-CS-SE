#include <iostream>
using namespace std;

struct node{
	int info;
	node* next;
};

class linkedlist{
	node* head, *tail;
	static int count;
	public:
		linkedlist(){
			head= tail= NULL;
		}
		void AddNewNode(int el){
			node *temp = new node;
			temp->info= el;
			temp->next= NULL;
			if(head==NULL){
				head= tail= temp;
			}
			else{
				tail->next= temp;
				tail= temp;
			}
		}
		void Display(){
			node* temp= head;
			while(temp!=NULL){
				count++;
				cout << temp->info << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		
		void DeleteFromHead(){
			node* temp;
			temp=head;
			head= head->next;
			delete temp;
		}
		
		void DeleteFromTail(){
			node* temp, *p=head;
			temp=tail;
			while(p->next->next!=NULL){
				p= p->next;
			}
			p->next= NULL;
			tail=p;
			delete temp;
		}
		
		void DeleteFromCenter(int pos){
			node* temp, *p=head;
			int i=0;
			while(i!= pos-1){
				i++;
				p = p->next;
			}
			temp= p->next;
			p->next= p->next->next;
		}
		
		void RemoveAdjacent(){
			node* p= head, *q=head;
			int val= 20;
			
			while(q!=NULL){
				val=q->info;
				
				int i=0, c=0;
				while(p!=NULL){
					if(p->info==val)
						c++;
					p=p->next;
				}
				p=head;
				if(c>1){
					int check=0;
					while(p!=NULL){
						if(p->info== val)
						{
							check++;
							if(check>1)
							{
								if(i==count)
									DeleteFromTail();
								else
									DeleteFromCenter(i);
							}
						}
						i++;
						p= p->next;
					}
				}
				q=q->next;
			}
			
		}
		
		void Reverse(){
			node *prevNode, *NextNode, *CurrentNode;
			prevNode=0;
			NextNode=CurrentNode=head;
			
			while(NextNode!=NULL){
				NextNode= NextNode->next;
				CurrentNode->next= prevNode;
				prevNode= CurrentNode;
				CurrentNode= NextNode;
			}
			head= prevNode;
		}
};
int linkedlist :: count=0;

int main(){
	linkedlist l1;
	l1.AddNewNode(10);
	l1.AddNewNode(20);
	l1.AddNewNode(30);
	l1.AddNewNode(30);
	l1.AddNewNode(20);
	l1.AddNewNode(40);
	l1.Display();
	l1.RemoveAdjacent();
	l1.Display();
	l1.Reverse();
	l1.Display();
}
