#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class LinkedList{
	private:
		node *head, *tail;
		int count;
	public:
		LinkedList(){
			head= tail= NULL;
			count=0;
		}
		void AddNewNode(int el){
			count++;
			node *temp= new node;
			temp->info= el;
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
			node *p =head;
			while(p!=NULL){
				cout << p->info << " ";
				p = p->next;
			}
			cout << endl;
		}
		
		void InsertionSort(){
			node* p = head;
			for(int i=1; i<count; i++){
				node *q= p;
				p= p->next;
				int temp= p->info;
				int j=i-1;
				while(j>-1 && q->info> temp){
					q->next->info= q->info;
					j--;
					q=q->next;
				}
			}
		}
};

int main(){
	LinkedList l1;
	l1.AddNewNode(35);
	l1.AddNewNode(20);
	l1.AddNewNode(15);
	l1.AddNewNode(25);
	l1.AddNewNode(19);
	l1.AddNewNode(29);
	l1.Display();
	l1.InsertionSort();
	l1.Display();
}
