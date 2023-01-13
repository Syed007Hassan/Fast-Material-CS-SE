#include<iostream>
using namespace std;

class Node{
	
	public:
		
		Node *next;
		int data;
		int p;
		
		
		Node(int d,int pp,Node *ptr = 0){
			data = d;
			p = pp;
			next = ptr;
		}

};

class P_Q{
	
	Node *front;
	
	public:
		
		P_Q(){
			front = 0;
		}
		
		
		void enqueue(int val, int p){
			Node *temp, *temp2;
			temp = new Node(val,p);
			
			if(front == 0 || p < front->p){
				temp->next = front;
				front = temp;
			}
			
			else{
				temp2 = front;
				
				while(temp2->next != 0 && temp2->next->p <= p ){
					temp2 = temp2->next;
				}
				
				temp->next = temp2->next;
				temp2->next = temp;
			}
		}
		
		
		void dequeue(int val){
			
			Node *temp = front;
			
			if(temp == 0){
				cout<<"Queue under flow "<<endl;
			}
			else{
				cout<<"Deleted val is "<<temp->data<<endl;
				front = front->next;
				
				delete temp;
			}
	
			
		}
		
		void print(){
			
			Node *temp = front;
			
			if(temp == 0){
				cout<<"Front is NUll "<<endl;
			}
			else{
				
				while(temp!= 0){
					
					cout<<temp->data<<" "<<temp->p<<endl;
					
					temp = temp->next;
				}
							
			}
			
		}

};

int main(){
	
	P_Q h1;
	
	h1.enqueue(2,5);
	
	h1.enqueue(1,5);
	
	h1.enqueue(3,6);
	
	h1.print();
	h1.dequeue(3);
	h1.print();
}
