#include<iostream>
using namespace std;

class Node{
	
	public:
	
	int data;
	Node *link;
	
	Node()
	{
		data = 0;
		link = 0;
	}
		
	Node(int val, Node* ptr = 0){
		
		data = val;
		link = ptr;		
	}
	
};

class Stack_List{
	
	Node *top;
	Node* tail;
	
	public:

	Stack_List(){
		
		top = 0;
	   tail = 0;
	}
	
	void push(int val){
		
	    top =  new Node(val,top);
		if(!top){
			cout<<"Stack over flow "<<endl;
			exit(0);
		}
		
	}
	
	void display(){
		
		Node *temp = top;
		
		if(isEmpty()){
			cout<<"STACK IS EMPTY "<<endl;
		}
		
		
		while(temp!= 0){
			
			cout<<temp->data<<endl;
			temp = temp->link;
			
		}
			
	}
	
	void end(int val){
		
		if(tail != 0){
			tail->link = new Node(val);
			cout<<tail->data<<endl;
			tail = tail->link;
		
		}
		else{
			
			tail = new Node(val);
			cout<<tail->data<<endl;	
			tail = tail->link;
		}
		
	}
	
	
	void reverseStack(){
		
		reverse(top);
	}
	
	void reverse(Node *n){
		
		if(n == 0){
			cout<<"EMPTY STACK "<<endl;
	
		}
		
		else{
			
			reverse(n->link);
			end(n->data);
		}
		
	}
	
	void pop(){
		
		if(isEmpty()){
		
			cout<<"Stack under flow "<<endl;
			exit(0);
			
		}
		else{
			
			while(top!= 0){
			
			cout<<"The popped element is: "<<top->data<<endl;
			top = top->link;
			
		   }
		}
			
	}
	
		bool isEmpty(){
		
		return ( top == 0);
	}
		
};

int main(){
	
	Stack_List sl;
	
	
	sl.push(1);
	sl.push(2);
	sl.push(3);
	sl.push(4);
	sl.push(5);


   sl.display(); 
   
   cout<<endl;
   sl.reverseStack();

   	while(!sl.isEmpty()){

      sl.pop();
	
   }
   
  
 
	
	
}
