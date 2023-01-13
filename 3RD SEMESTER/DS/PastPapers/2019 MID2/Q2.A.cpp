#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class Circular{
	node* head, *tail;
	
	public:
		Circular(){
			head= tail= NULL;
		}
		void AddNewElement(int el){
			node* temp= new node;
			temp->info = el;
			temp->next= head;
			if(!head){
				head = tail= temp;
				tail->next= head;
			}
			else{
				tail->next= temp;
				tail= temp;
				tail->next = head;
			}
		}
		void Display(){
			node* p =head;
			do{
				cout << p->info << " ";
				p=p->next;
			}while(p!=head);
			cout << endl;
		}
		
		void Sort(){
			node* temp= head;
			do{
				node* t= temp->next;
				while(t!=head){
					if(temp->info < t->info){
						int tt= temp->info;
						temp->info= t->info;
						t->info = tt;
					}
					t= t->next;
				}
				temp= temp->next;
				
			}while(temp->next!=head);
		}
		
		int Multiply(){
			node* p= head;
			return p->info* p->next->info * p->next->next->info;
		}
};

int main(){
	Circular l1;
	l1.AddNewElement(5);
	l1.AddNewElement(4);
	l1.AddNewElement(1);
	l1.AddNewElement(2);
	l1.AddNewElement(3);
	l1.Display();
	l1.Sort();
	l1.Display();
	cout << l1.Multiply();
	return 0;
}
