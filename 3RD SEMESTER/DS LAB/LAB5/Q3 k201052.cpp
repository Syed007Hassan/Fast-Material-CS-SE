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
	
				
		int isEmpty()
    	{
        	return head == 0;
    	}
    	
    	
    	void Avg(Singlelist &Al){
    		
    		Node* temp = head;
    		Node* n = temp;
    		float sum=0;
    		float avg=0;
    		
    		
    		while(temp->next->next->next != 0){
			
    		for(int i=0;i<4;i++){
    			sum = sum + temp->data;
    			temp = temp->next;
			}
			avg = sum/4;
		//	cout<<avg<<" ";
			
			Al.insertAtEnd(avg);
			avg = 0,sum = 0;
			
			n = n->next;
			temp = n;
		}
				
		}
		
		
		void add(Singlelist &A, Singlelist &B){
			
			Node *n = A.head;
			Node *q = B.head;
			
			
			while(q!=0){
				
				A.insertAtEnd(q->data);
				q = q->next;
			}
			
			
		//	A.traverse();
		
		}
			
			
		
};

int main() {
	Singlelist Number_list,Average_list;
	
	int n;
	cout<<"Enter the 12 numbers: ";
	
	for(int i=0;i<12;i++){
		
	cin>>n;
	Number_list.insertAtEnd(n);
	
   }
   
    Number_list.Avg(Average_list);
    
    cout<<"Printing the numbers of Average list: "<<endl;
    Average_list.traverse();


//   Singlelist A,B,C;
//   
//   A.insertAtEnd(5);
//   A.insertAtEnd(4);
//   A.insertAtEnd(6);
//   
//   B.insertAtEnd(3);
//   B.insertAtEnd(2);
//   
//   
//   C.add(A,B);
//
//  A.traverse();
	return 0;
}
