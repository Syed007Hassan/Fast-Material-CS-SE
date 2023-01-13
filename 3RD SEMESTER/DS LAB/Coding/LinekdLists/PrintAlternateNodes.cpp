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
		node * temp= new node;
		temp->info=el;
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
		while(p!=NULL){
			cout << p->info << " ";
			p=p->next;
		}
		cout << endl;
	}
	
	void PrintAlternateNodes(){
		node *p=head;
		int i=1;
		while(p!=NULL){
			if(i%2==1){
				cout << p->info << " ";
			}
			i++;
			p=p->next;
		}
	}
};

int main(){
	linkedlist l1;
	l1.AddnewNode(5);
	l1.AddnewNode(10);
	l1.AddnewNode(15);
	l1.AddnewNode(20);
	l1.Display();
	
	l1.PrintAlternateNodes();
}
