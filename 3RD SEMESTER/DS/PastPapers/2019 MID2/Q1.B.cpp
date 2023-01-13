#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class linkedlist{
	node *head, *tail;
	public:
		linkedlist(){
			head= tail= NULL;
		}
		void AddnewNode(int el){
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
			node *p=head;
			while(p){
				cout << p->info << " ";
				p= p->next;
			}
			cout << endl;
		}
		
		void CheckSum(int y){
			node* p = head;
			while(p->next!=NULL){
				if(p->info + p->next->info == y){
					cout << "YES";
					exit(0);
				}
				p=p->next;
			}
			cout << "NO";
			return;
		}
};


int main(){
	linkedlist l1;
	l1.AddnewNode(5);
	l1.AddnewNode(4);
	l1.AddnewNode(3);
	l1.AddnewNode(2);
	l1.AddnewNode(1);
	l1.AddnewNode(6);
	l1.Display();
	l1.CheckSum(11);
	return 0;
}
