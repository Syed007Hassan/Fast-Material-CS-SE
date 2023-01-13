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
		
		void count(){
			int count=0, sum=0;
			node *temp = head;
			while(temp){
				count++;
				sum += temp->info;
				temp= temp->next;
			}
			cout << "Total elements are : " << count;
			cout << "\nTotal sum is : " << sum << endl;
		}
};

int main (){
	linkedlist l1;
	l1.AddElement(1);
	l1.AddElement(2);
	l1.AddElement(3);
	l1.AddElement(4);
	l1.count();
	return 0;
}
