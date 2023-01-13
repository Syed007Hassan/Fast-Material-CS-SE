#include<iostream>
using namespace std;

class Node{
	
	public:
		int data;
		Node *prev;
		
		Node(int val, Node *ptr = 0){
			data = val;
			prev = ptr;
		}
		
		Node(){
			data = 0;
			prev = 0;
		}
};

class Queue{
	
	Node *rear;
	Node *front;
	
	public:
		
		Queue(){
			front = 0;
			rear = 0;
		}
	
	// ADD MEMBER IN A QUEUE 
			
	void enqueue(int val){
		
		Node *temp = new Node(val);
		
		if(temp){
			
			if(rear == 0){
				rear = front = temp;
			}
			
			rear->prev = temp;
			rear = temp;
		}
		else{
			cout<<"Queue is full "<<endl;
		}	
	}
	
	  //DELETE MEMBER IN A QUEUE 
	
	int dequeue(){
		
		if(front){
		int value = front->data;
		
		Node *temp = front;
		
		front = front->prev;
		
		if(front == 0){
			rear = 0;
			delete temp;
		}
		
		return value;
		
		}
		
		else{
			cout<<"QUEUE IS EMPTY "<<endl;
		}
	
    }
	
	 //QUEUE CAPACITY CHECKL
	
	int isEmpty(){
		
		return front == 0;
	}
	
	//QUEUE FULL CHECK
	
	int isFull(){
		
	  return !rear;
	}
	
	
};


int main(){
	
	Queue q;
	
	q.enqueue(5);
	q.enqueue(2);
	
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	
}
