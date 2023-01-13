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
			head=tail=NULL;
		}
		
		void AddNewNode(int el){
			node* temp= new node;
			temp->info=el;
			temp->next=NULL;
			if(head==NULL){
				head=tail=temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
		}
		
		void Display(){
			node *temp=head;
			while(temp!=NULL){
				cout << temp->info << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		
		void swap(int pos1, int pos2){
			node *temp1, *temp2, *p=head;
			int i=1,j=1;
			node* prevtemp1=0, *prevtemp2=0, *nexttemp1, *nexttemp2;
			
			while((i!=pos1-1) && (p!=NULL)){
				i++;
				p=p->next;
			}
			temp1 = p->next;
			prevtemp1= p;
			nexttemp1= temp1->next;
			
			p=head;
			while((j!=pos2-1) && (p!=NULL)){
				j++;
				p=p->next;
			}
			temp2= p->next;
			prevtemp2= p;
			nexttemp2= temp2->next;
			
			prevtemp1->next= temp2;
			temp2->next= temp1->next;
			nexttemp1->next= temp1;
			temp1->next= nexttemp2;
		}

		void swap(node* p1, node* p2){
			int temp= p1->info;
			p1->info= p2->info;
			p2->info= temp;
		}
		
		void Bubble_Sort(){
			node* temp1, *temp2, *p=head, *q;
			int i,j;
			
			for(int i=1; p!=NULL; i++){
				q=p->next;
				for(int j=i+1; q!=NULL; j++, q=q->next){ 
					if(p->info > q->info){
						swap(p,q);
					}
				}
				p=p->next;
			}
		}
};

int main(){
	linkedlist l1;
	l1.AddNewNode(6);
	l1.AddNewNode(4);
	l1.AddNewNode(2);
	l1.AddNewNode(5);
	l1.AddNewNode(1);
	l1.AddNewNode(3);	
	l1.Display();
	
//	l1.swap(3,5);
//	l1.Display();
	
	l1.Bubble_Sort();
	l1.Display();
	
}
