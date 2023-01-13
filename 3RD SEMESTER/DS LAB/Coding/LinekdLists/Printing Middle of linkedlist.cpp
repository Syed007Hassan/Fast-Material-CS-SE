#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class linkedlist{
	node *head, *tail;
	int count=0;
	public:
		linkedlist(){
			head= tail = NULL;
		}
		void AddNewElement(int el){
			count++;
			node *temp= new node;
			temp->info= el;
			temp->next=NULL;
			if(!head){
				head= tail= temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
		}
		void displaY(){
			node *p= head;
			while(p){
				cout << p->info << " ";
				p= p->next;
			}
			cout << endl;
		}
		void PrintMiddle(){
			if(count%2==1){
				int t=count/2;
				node *p = head;
				int i=0;
				while(i!=t-1){
					i++;
					p=p->next;
				}
				cout << "Middle node of linked list : " << p->next->info << endl;
			}
			else{
				int t=count/2;
				node *p = head;
				int i=0;
				while(i!=t-1){
					i++;
					p=p->next;
				}
				cout << "Middle node of linked list : " << p->info << endl;
				cout << "Middle node of linked list : " << p->next->info << endl;
			}
		}
};

int main(){
	linkedlist l1;
	l1.AddNewElement(5);
	l1.AddNewElement(10);
	l1.AddNewElement(15);
	l1.AddNewElement(20);
	l1.AddNewElement(25);
	l1.AddNewElement(30);
	l1.displaY();
	l1.PrintMiddle();
	return 0;
}
