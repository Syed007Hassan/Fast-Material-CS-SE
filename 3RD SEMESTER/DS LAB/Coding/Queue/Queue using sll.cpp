#include <iostream>
using namespace std;

template <class T>
class Node{
public:
	T data;
	Node* next;
};

template<class T>
class Queue{
	Node<T> *front, *rear;
public:
	Queue(){
		front = rear = NULL;
	}
	void Enqueue(T el){
		Node<T> *temp = new Node<T>;
		if(!temp){
			cout << "Queue is full";
			exit(0);
		}
		else{
			temp->data = el;
			temp->next = NULL;
			if(!front)
				front = rear = temp;
			else{
				rear->next = temp;
				rear = temp;	
			}
		}
	}
	T Dequeue(){
		Node<T> *temp;
		if(front == NULL){
			cout << "Queue is empty";
			return -1;
		}
		else{
			temp= front;
			front = front->next;
			int x= temp->data;
			delete temp;
			return x;
		}
	}
	
	void Display(){
		Node<T> *p= front;
		while(p){
			cout << p->data << " ";
			p=p->next;
		}
		cout << endl;
	}
};


int main(){
	Queue<int> q1;
	q1.Enqueue(1);
	q1.Enqueue(2);
	q1.Enqueue(3);
	q1.Enqueue(4);
	q1.Enqueue(5);
	q1.Display();
	cout << q1.Dequeue() << "\n";
	q1.Display();
}
