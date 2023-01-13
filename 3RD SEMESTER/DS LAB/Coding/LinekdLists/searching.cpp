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
			head=tail=NULL;
		}
		void AddElement(int el){
			node *temp = new node;
			temp->info = el;
			temp->next= NULL;
			if(head==NULL){
				head= temp;
				tail= temp;
			}
			else{
				tail->next= temp;
				tail = tail->next;
			}
		}
		
		void display(){
			node *temp;
			temp = head;
			while(temp){
				cout << temp->info << endl;
				temp= temp->next;
			}
		}
		
		bool search(int val){
			node *temp = head;
			while(temp){
				if(temp->info == val)
					return true;
				temp= temp->next;
			}
			return false;
		}
};

int main (){
	linkedlist l1;
	l1.AddElement(1);
	l1.AddElement(2);
	l1.AddElement(3);
	l1.AddElement(4);
	
	cout << l1.search(3) << endl;
	cout << l1.search(10);
	return 0;
}
