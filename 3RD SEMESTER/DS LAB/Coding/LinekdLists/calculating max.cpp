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
		
		int max(){
			int max=0;
			node *temp = head;
			while(temp){
				if(max< temp->info)
					max= temp->info;
				temp= temp->next;
			}
			return max;
		}
};

int main (){
	linkedlist l1;
	l1.AddElement(1);
	l1.AddElement(2);
	l1.AddElement(3);
	l1.AddElement(4);
	cout << l1.max();
	return 0;
}
