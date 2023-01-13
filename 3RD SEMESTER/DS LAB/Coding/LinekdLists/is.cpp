#include <iostream>
#include <conio.h>
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
			head = tail = NULL;
			count=0;
		}
		void AddNewNode(int el){
			count++;
			node *temp = new node;
			temp->info= el;
			temp->next = NULL;
			if(!head){
				head = tail = temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
		}
		void Display(){
			node *p= head;
			while(p!=NULL){
				cout << p->info << " ";
				p= p->next;
			}
			cout << endl;
		}
		
		void InsertionSort(){
			node* sorted = NULL;
			node* current = head;
			while(current){
				node* temp= current->next;
				sorted_Insert(sorted, current);
				current= temp;
			}
			head= sorted;
		}

		void sorted_Insert(node* head, node* temp){
			node* current;
			if(head==NULL || head->info >= temp->info){
				temp->next= head;
				head= temp;
			}
			else{
				current= head;
				while(current->next!=NULL && current->next->info < temp->info){
					current= current->next;
				}
				temp->next= current->next;
				current->next = temp;
			}
		}
		
};

int main(){
	linkedlist l1;
	l1.AddNewNode(8);
	l1.AddNewNode(6);
	l1.AddNewNode(3);
	l1.AddNewNode(10);
	l1.AddNewNode(9);
	cout << "Data in linked list before sorting :\t";
	l1.Display();
	l1.InsertionSort();
	cout << "Data in linked list after sorting :\t";
	l1.Display();
	
	return 0;	
}
