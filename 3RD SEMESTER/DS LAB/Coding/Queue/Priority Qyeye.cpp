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
	
	Node<T>* getHighest(){
		Node<T> *h= front;
		Node<T> *p= front->next;
		while(p){
			if(p->data < h->data)
				h=p;
			p=p->next;
		}
		return h;
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
			Node<T> *h = getHighest();
			if(h==front){
				temp= front;
				front = front->next;
				int x= temp->data;
				delete temp;
				return x;
			}
			else if(h==rear){
				temp = front;
				while(temp->next!=h){
					temp= temp->next;
				}
				Node<T> *p = rear;
				int x= rear->data;
				rear = temp;
				rear->next= NULL;
				delete p;
				return x;
			}
			else{
				while(temp->next!=h){
					temp= temp->next;
				}
				Node<T> *p = h;
				int x= p->data;
				temp->next = p->next;
				delete h;
				return x;
			}
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
	q1.Enqueue(5);
	q1.Enqueue(4);
	q1.Enqueue(3);
	q1.Enqueue(2);
	q1.Enqueue(1);
	q1.Display();
	cout << q1.Dequeue() << "\n";
	q1.Display();
	cout << q1.Dequeue() << "\n";
	q1.Display();
}
