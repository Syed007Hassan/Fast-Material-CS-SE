#include <iostream>
using namespace std;

class Queue {
	private:
		int front,rear,capacity;
		int *arr;
	public:
		Queue(int c) {
			front=0;
			rear=-1;
			capacity=c;
			arr = new int[capacity];			
		}
		
		void ADDMember(int num) {
			if(rear==capacity) {
				cout << "\nQueue is Full!";
				return;
			}
			arr[++rear]=num;
			return;
		}
		
		void RemoveMember() {
			if(rear==-1) {
				cout << "\nQueue is Empty!";
				return;
			}
			
			for(int i=0;i<=rear-1;i++) {
				arr[i]=arr[i+1];	// 6 5 3 2 1 8
			}
			
			rear--;
			return;
		}
		
		void QueueCapacity() {
			if(rear==capacity) {
				cout << "\nCapacity is Full.";
			}
			else {
				cout << "\nCapaity is not Full.";
			}
		}
		
		void display() {
        	if (rear==-1) {
            	cout << "\nQueue is Empty.";
            	return;
        	}
 
        	for (int i = front; i <= rear; i++) {
            	cout << arr[i] << " ";
        	}
        	return;
		}
		
		void peek() {
			cout << arr[front];
			return;
		}
};

int main() {
	Queue q1(10);
	
	q1.ADDMember(6);
	q1.ADDMember(8);
	q1.ADDMember(3);
	
	q1.display();
	
	q1.RemoveMember();
	
	cout << endl;
	q1.display();
	
	q1.QueueCapacity();
	
	cout << endl;
	q1.peek();
}
