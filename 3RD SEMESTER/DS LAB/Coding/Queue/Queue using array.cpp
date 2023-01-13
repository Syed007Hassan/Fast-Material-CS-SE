#include <iostream>
using namespace std;

template <class T>
class Queue{
private:
	int front;
	int rear;
	int size;
	T *Q;
public:
	Queue(int s){
		front = rear= -1;
		size = s;
		Q= new int[size];
	}
	
	void Enqueue(T x){
		if(isFull()){
			cout << "Overflow.\n";
		}
		else{
			Q[++rear]= x;
		}
	}
	
	T Dequeue(){
		T x=-1;
		if(isEmpty()){
			cout << "Underflow.\n";
		}
		else{
			x= Q[++front];
		}
		return x;
	}
	
	void Display(){
		for(int i=front+1; i<=rear; i++){
			cout << Q[i] << " ";
		}
		cout << endl;
	}
	bool isEmpty(){
		if(front==rear)
			return true;
		return false;
	}
	bool isFull(){
		if(rear==size-1)
			return true;
		return false;
	}
};

int main(){
	
	Queue<int> q(5);
	q.Enqueue(5);
	q.Enqueue(15);
	q.Enqueue(25);
	q.Enqueue(30);
	q.Enqueue(35);
	q.Display();
	q.Dequeue();
	
	q.Enqueue(40);
	q.Display();
	q.Enqueue(40);
	q.Display();
	return 0;
}
