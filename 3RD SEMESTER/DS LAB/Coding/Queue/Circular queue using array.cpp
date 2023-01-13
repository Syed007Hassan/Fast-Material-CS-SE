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
		front = rear= 0;
		size = s;
		Q= new int[size];
	}
	
	void Enqueue(T x){
		if(isFull()){
			cout << "\nOverflow at : " << rear << " " << front << endl;
		}
		else{
			rear= (rear+1)%size;
			Q[rear]= x;
		}
	}
	
	T Dequeue(){
		T x=-1;
		if(isEmpty()){
			cout << "Underflow.\n";
		}
		else{
			front= (front+1)%size;
			x= Q[front];
		}
		return x;
	}
	
	void Display(){
		int i= front+1;
		do{
			cout << Q[i] << " ";
			i= (i+1)%size;
		}while(i!=(rear+1)%size);
		cout << endl;
	}
	bool isEmpty(){
		if(front==rear)
			return true;
		return false;
	}
	bool isFull(){
		if((rear+1)%size==front)
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
	q.Display();
	q.Enqueue(40);
//	q.Display();
//	q.Dequeue();
//	q.Enqueue(40);
//	q.Display();
	return 0;
}
