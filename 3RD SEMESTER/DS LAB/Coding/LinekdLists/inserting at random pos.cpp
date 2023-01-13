//#include <iostream>
//using namespace std;
//
//struct node{
//	int info;
//	node* next;
//};
//
//class linekdlist{
//	node *head, *tail;
//	
//	public:
//		linkedlist(){
//			head=tail=NULL;
//		}
//		void addElement(int val){
//			node* temp= new node;
//			temp->info= val;
//			temp->next= NULL;
//			if(head==NULL){
//				head= temp;
//				tail= temp;
//			}
//			else{
//				tail->next=temp;
//				tail= tail->next;
//			}
//		}
//		
//		void insertRandom(int pos, int val){
//			node* temp= new node;
//			node *p= head;
//			temp->info= pos;
//			for(int i=0; i<pos-1; i++){
//				p = p->next;
//			}
//			temp->next = p->next;
//			p->next= temp;
//		}
//		
//		void display(){
//			node* temp= head;
//			while(temp){
//				cout << temp->info << " ";
//				temp = temp->next;
//			}
//		}
//		
//};
//
//int main(){
//	linekdlist l1;
//	l1.addElement(2);
////	l1.AddElement(3);
////	l1.AddElement(4);
////	l1.AddElement(5);
//	
//}

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

		void display(){
			node *temp;
			temp=head;		
			while(temp!=NULL){
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		
		void insertRandom(int pos, int val){
			node* temp= new node;
			node *p= head;
			temp->data= val;
			for(int i=0; i<pos-1; i++){
				p = p->next;
			}
			temp->next = p->next;
			p->next= temp;
		}

};

int main(){
	linkedlist l1;
	l1.addElement(5);
	l1.addElement(10);
	l1.addElement(15);
	l1.display();
	cout << endl;
	
	l1.insertRandom(2,100);
	l1.display();
	return 0;
}
