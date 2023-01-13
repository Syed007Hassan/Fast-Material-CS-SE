#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class linkedlist{
	node* head, * tail;
	
	public:
		linkedlist(){
			head= tail= NULL;
		}
		void addElement(int val){
			node* temp= new node;
			temp->data= val;
			temp->next= NULL;
			if(head==NULL){
				head= temp;
				tail= temp;
			}
			else{
				tail->next=temp;
				tail= tail->next;
			}
		}
		void AddElementatHead(int el){
			node *temp= new node;
			temp->data=el;
			if(head==NULL){
				head=temp;
				tail=temp;
			}
			else{
				temp->next= head;
				head=temp;
			}
		}
		void AddElementatTail(int el){
			node* temp= new node;
			temp->data= el;
			
			if(tail !=NULL){
				tail->next= temp;
				tail= tail->next;
			}
			else{
				head = tail = temp;
			}
		}
		void display(){
			node *temp;
			temp=head;		
			while(temp!=NULL){
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		
		void deletefromhead(){
			node* temp= head;
			if(head==tail){
				head= tail = NULL;
			}
			else{
				head= head->next;
				delete temp;
			}
		}
		
		void DeletefromTail(){
			if(head==tail){
				delete head;
				head=tail=NULL;
			}
			else{
				node* temp= head;
				while(temp->next != tail){
					temp= temp->next;
				}
				
				delete tail;
				tail= temp;
				tail->next= NULL;
			}	
		}
		
		void Delete(int el){
			if(head==)
		}
};

int main(){
	linkedlist l1;
	l1.addElement(5);
	l1.addElement(10);
	l1.addElement(15);
	l1.AddElementatHead(20);
	l1.addElement(25);
	l1.AddElementatHead(30);
	l1.display();
	cout << endl;
	
//	l1.AddElementatTail(90);
//	l1.display();
	l1.deletefromhead();
	l1.display();
	l1.DeletefromTail();
	cout << endl;
	l1.display();
	return 0;
}
