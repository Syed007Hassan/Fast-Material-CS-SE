#include <iostream>
#include <conio.h>
using namespace std;

struct node{
	int info;
	node *next;
};

class linkedlist{
	node *head, *tail;
	int count;
	public:
		linkedlist(){
			head = tail = NULL;
			count=0;
		}
		void AddNewNode(int el){
			count++;
			node *temp = new node;
			temp->info= el;
			temp->next = NULL;
			if(!head){
				head = tail = temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
		}
		void Display(){
			node *p= head;
			while(p!=NULL){
				cout << p->info << " ";
				p= p->next;
			}
			cout << endl;
		}
		
		void SelectionSort(){
			node *temp;
			for(node *p= head; p->next!=NULL; p=p->next){
				int min= p->info;
				for(node *q= p; q!=NULL; q= q->next){
					if(q->info < min){
						min= q->info;
						temp= q;	
					}
				}
				int t = p->info;
				p->info= temp->info;
				temp->info = t;
			}
		}
};

int main(){
	linkedlist l1;
	l1.AddNewNode(8);
	l1.AddNewNode(6);
	l1.AddNewNode(3);
	l1.AddNewNode(10);
	l1.AddNewNode(9);
	l1.AddNewNode(4);
	l1.AddNewNode(12);
	l1.AddNewNode(5);
	l1.AddNewNode(2);
	l1.AddNewNode(7);
	
	l1.Display();
	l1.SelectionSort();
	l1.Display();
	
//	int Arr[]={8,6,3,10,9,4,12,5,2,7};
//	int n=10;
//	int min, index;
//	for(int i=0; i<n; i++){
//		min = Arr[i];
//		for(int j=i; j<n; j++){
//			if(Arr[j]<min){
//				min= Arr[j];
//				index= j;
//			}
//		}
//		int temp= Arr[i];
//		Arr[i]= Arr[index];
//		Arr[index]=temp;
//	}
//	
//	for(int i=0; i<n; i++)
//		cout << Arr[i] << " ";
	
	return 0;	
}
