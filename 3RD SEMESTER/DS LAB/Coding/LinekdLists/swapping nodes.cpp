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
	void AddnewNode(int el){
		count++;
		node * temp= new node;
		temp->info=el;
		temp->next= NULL;
		if(!head){
			head= tail= temp;
		}
		else{
			tail->next= temp;
			tail= tail->next;
		}
	}
	
	void Display(){
		node *p=head;
		while(p!=NULL){
			cout << p->info << " ";
			p=p->next;
		}
		cout << endl;
	}
	
	void SwapNodes(int pos){
		int i=1;
		node *p= head, *temp, *temp2, *temp3;
		if(pos==1){
			temp=p;
			temp2= temp->next;
			temp3= temp2->next;
			temp2->next= temp;
			temp->next=temp3;
			head= temp2;
		}
		else if(pos==count-1){
			while(i!=pos-1){
				i++;
				p=p->next;
			}
			temp=p->next;
			temp2= temp->next;
			temp3= tail;
			
			temp2->next= temp;
			p->next=temp2;
			temp->next=NULL;
			tail=temp;
		}
		else{
			while(i!=pos-1){
				p=p->next;
			}
			temp=p->next;
			temp2= temp->next;
			temp3= temp2->next;
			temp2->next= temp;
			p->next= temp2;
			temp->next=temp3;
		}
	}
};

int main(){
	linkedlist l1;
	l1.AddnewNode(0);
	l1.AddnewNode(1);
	l1.AddnewNode(2);
	l1.AddnewNode(3);
	l1.AddnewNode(4);
	l1.AddnewNode(5);
	l1.AddnewNode(6);
	l1.AddnewNode(7);
	cout << "Data in linked list before sorting :\t";
	l1.Display();
	l1.SwapNodes(3);
	l1.Display();
}
