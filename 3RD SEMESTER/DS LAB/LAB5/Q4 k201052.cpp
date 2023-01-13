#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node() {
			next=NULL;
		}
		Node(int val, Node *ptr=0) {
			data=val;
			next=ptr;
		}
};

class Singlelist {
	private:
		Node *head, *tail;
	public:
		Singlelist() {
			head= 0;
			tail = 0;
		}
		
		void insertAtFront(int val) {
			head= new Node(val,head);
			if(tail == 0) {
				tail=head;
			}
		}
		
		void insertAtEnd(int val) {
			if(tail!=0) {
				tail->next=new Node(val);
				tail=tail->next;
			}
			else {
				head=tail=new Node(val);
			}
		}
		
		int traverse() {
			Node *temp;
			if(isEmpty()) {
				cout << "List is empty.";
				return 0;
			}
			for(temp=head;temp!=NULL;temp=temp->next) {
				cout << temp->data << " ";
			}
			cout << endl;
			
		}
		
	
	//POINTER MISPLACING
		
	   void EvenOdd(){
			
	
		Node* O = 0;
		Node* E = 0;
	
		
		Node *temp = head;
		
		while(temp!=0){
			
			if(temp->data %2 == 0){
				
				if(E == 0){   //cating the head for Even
					
				
					E = temp;
					temp = temp->next;
		          
				}
				else{
					
		
					E->next = temp;
					temp = temp->next;
				
				}
			}
			
			else{
				
				if(O == 0){
		         
					O = temp;   //cating the head of odd
					temp = temp->next;
					
				}
				else{
			
					O->next = temp;
					temp = temp->next;
					
				}
					
			}
			
		}				
		

	
		E->next = O;
		
	    O->next = 0;
	    
	    while(O!=0){
	    	
	    	cout<<E->data<<" ";
	    	E = E->next;
	    	O = O->next;
		}
		
	  	
		}
		
		
		
		int isEmpty(){
			return head == 0;			
		}
		
};

int main(){
	
	Singlelist l1;
	
	l1.insertAtFront(4);
	l1.insertAtEnd(3);
	l1.insertAtEnd(5);
	l1.insertAtEnd(2);
	l1.insertAtEnd(7);
	
	
	l1.traverse();
	
	l1.EvenOdd();
	
//	l1.traverse();
}
	
	
	
