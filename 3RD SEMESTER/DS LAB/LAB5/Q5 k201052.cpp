#include<iostream>
#include <math.h>
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
    	
    	bool isFibNo(int n){
    		
    		 int s = sqrt(n);
             return (s*s == n);
		}
    	
      void meanof_odd_fib(int n){
      	
      	Node* temp = head;
      	float sum=0,c=0;
      	float mean = 0;
      	
      	
      	while( temp!= 0 ){
      		
      		if(isFibNo(5*temp->data*temp->data + 4) || isFibNo(5*temp->data*temp->data - 4) ){
      			
      			if(temp->data %2 != 0){
      				
      				c++;
      				sum = sum + temp->data;
				  }
      			
			  }
      		
      			temp = temp->next;
		  }
		  
		  cout<<sum<<endl;
		  mean = sum/c;
		  
		  cout<<endl<<"Mean of odd fib no are: "<<mean<<endl;
      	
         	
	  }
};

int main() {
	Singlelist list;
	
	int n,x;
	
	cout<<"Enter n: ";
	cin>>n;

	cout<<"Enter the "<<n<<" numbers: ";
	
	for(int i=0;i<n;i++){
		
	cin>>x;
	list.insertAtEnd(x);
	
   }
   
   list.meanof_odd_fib(n);
   
    


	return 0;
}
	

