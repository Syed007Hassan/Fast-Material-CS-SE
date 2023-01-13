#include <iostream>
using namespace std;

template <class T>
class Node{
public:
	T data;
	Node* next;
};

template <class T>
class linkedlist{
	Node<T> *top;
public:
	linkedlist(){
		top = NULL;
	}
	void AddNewNodeAtHead(T el){
		Node<T>* temp = new Node<T>;
		if(!temp){
			cout << "Memory is full.\n";
			exit(0);
		}
		temp->data = el;
		temp->next = NULL;
		
		if(!top){
			top = temp;
		}
		else{
			temp->next = top;
			top = temp;
		}
	}
	
	void Display(){
		Node<T> *temp = top;
		while(temp){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	T pop(){
		if(isEmpty()){
			cout << "Stack is empty.";
			return -1;
		}
		else{
			Node<T> *temp = top;
			top = top->next;
			T x = temp->data;
			delete temp;
			return x;		
		}
	}
	bool isEmpty(){
		if(top==NULL)
			return true;
		return false;
	}
};

int main(){
	linkedlist<int> l1;
	l1.AddNewNodeAtHead(1);
	l1.AddNewNodeAtHead(2);
	l1.AddNewNodeAtHead(3);
	l1.AddNewNodeAtHead(4);
	l1.AddNewNodeAtHead(5);
	l1.AddNewNodeAtHead(6);
	l1.Display();
	
	cout << l1.pop() << endl;
	l1.Display();
	return 0;
}
