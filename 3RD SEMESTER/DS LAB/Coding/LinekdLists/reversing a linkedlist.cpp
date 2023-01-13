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
		
		void Reverse(){
			node *PrevNode, *NextNode, *CurrentNode;
			PrevNode=0;
			CurrentNode= NextNode=head;
			while(NextNode != 0){
				NextNode= NextNode->next;
				CurrentNode->next= PrevNode;
				PrevNode= CurrentNode;
				CurrentNode= NextNode;
			}
			head= PrevNode;
		}
};

int main(){
	linkedlist l1;
	l1.AddNewNode(10);
	l1.AddNewNode(20);
	l1.AddNewNode(30);
	l1.AddNewNode(40);
	l1.Display();
	l1.Reverse();
	l1.Display();
	return 0;
}
