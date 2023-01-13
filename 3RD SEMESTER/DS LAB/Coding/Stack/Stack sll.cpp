#include <iostream>

class Node{
	public:
		int data;
		Node* next;
};

class stack{
	private:
		Node* top;
	public:
		Stack(){
			top= NULL;
		}
		void push(int x);
		int pop();
		void Display();
		bool isEmpty();
};

void stack:: push(int x){
	Node* temp = new Node;
	if(!temp){
		std:: cout << "StackOverflow";
	}
	else{
		temp->data= x;
		temp->next= top;
		top= temp;
	}
}

int stack:: pop(){
	if(isEmpty()){
		std:: cout << "\n Can't pop.\n";
		return -1;
	}
	else{
		Node* temp= top;
		top= top->next;
		int x= temp->data;
		delete temp;
		return x;
	}
}

bool stack:: isEmpty(){
	if(top==NULL){
		std:: cout << "Stack is empty.";
		return true;
	}
	return false;
	
}

void stack:: Display(){
	Node* p= top;
	while(p!= NULL){
		std:: cout << p->data << " " << std::endl;
		p= p->next;
	}
}
int main(){
	stack s1;
	s1.push(5);
	s1.push(10);
	s1.push(15);
	s1.push(20);
	s1.push(25);
	s1.Display();
	s1.pop();
	s1.Display();
	
	return 0;
}
