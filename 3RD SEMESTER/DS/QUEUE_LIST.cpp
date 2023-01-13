#include<iostream>
using namespace std;

class Node{
	
	public:
	
	int info;
	Node *prev;
	
	Node()
	{
		info = 0;
		prev = 0;
	}
		
	Node(int val, Node* ptr = 0){
		
		info = val;
		prev = ptr;		
	}
	
};

class Queue{
	
	Node *rear;
	Node *front;
	
	public:

	Queue(){
		
	  rear = front  = 0; 
	}
	
	
	void enqueue ( int element ) {
	 
	 Node *temp = new Node ( element );

       if ( temp ) {
         if ( rear == NULL ) {
      
	   front = rear = temp;
       return ;
      }

     rear -> prev = temp;
     rear = temp; 
	 } 
    else
     cout << "Queue is full "<<endl;
     }
     
     
     
     int dequeue ( ) {

     if ( front ) {
     int value = front -> info;

     Node *temp = front;
     
	 front = front -> prev;
     if ( front == NULL )
       rear = NULL;
       delete temp;
       return value;
      } 
	  else { cout << "Queue is full "<<endl;;
     return -1; }
}
     
     
     int peek ( ) {

     int value = -1;
      if ( front ) {

      value = front->info;
   } 
     return value;
    }
	
	
	int isEmpty ( )
{
return front == NULL;
}
	

		
};

int main(){
	
	
	Queue list;
	
	list.enqueue(13);
	list.enqueue(12);
	list.enqueue(11);
	
	cout<<list.dequeue()<<endl;
	cout<<list.dequeue()<<endl;
	cout<<list.dequeue()<<endl;
   }
   
