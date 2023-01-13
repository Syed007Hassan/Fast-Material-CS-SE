#include<iostream>
using namespace std;
 
class Queue{
	
    int front, rear, len;
    int data[];
    
    public:
    Queue(int c)
    {
        front = rear = 0;
        len = c;
        data[len];
    }
 
   // ADD MEMBER IN A QUEUE 
   
    void enqueue(int val)
    {
        if (isFull()) {
            cout<<"QUEUE IS FULL "<<endl;
        }
        else{
            
			data[rear] = val;
            rear++;
        }
    }
 
    //DELETE MEMBER IN A QUEUE 
    
    int dequeue()
    {
        if(isEmpty()){
        	cout<<"QUEUE IS EMPTY "<<endl;
        }
 
        else{
        	
        	int value = data[front++];
            for (int i = 0; i < rear - 1; i++) {
                data[i] = data[i+1];
            }
            rear--;
            return value;
        }
    }
 
    //QUEUE EMPTY CHECK
    
    int isEmpty(){
    	
    	return front = 0;
	}
	
	//QUEUE FULL CHECK
	
	int isFull(){
		
		if(len == rear){
		
			return true;
		}
		else{
			return false;
		}
	}
 
};

int main(void)
{
    
    Queue q(3);
    
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(8);
    
//    cout<<q.dequeue()<<endl;
//    cout<<q.dequeue()<<endl;
//    cout<<q.dequeue()<<endl;
  
//    cout<<q.isFull()<<endl;
  
}
