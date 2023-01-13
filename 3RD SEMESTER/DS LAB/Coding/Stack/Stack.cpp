#include <iostream>
using namespace std;

class stack{
	private:
		int size;
		int top;
		int *ptr;
	public:
		stack(int size){
			this->size= size;
			top = -1;
			ptr= new int[this->size];
		}
		
		void Display(){
			for(int i= top; i>=0; i--)
				cout << ptr[i] << " ";
		}
		bool isFull(){
			if(top== size-1)
				return true;
			return false;		
		}
		void push(int content){
			if(isFull())
				cout << "stack overflow.";			
			else
				ptr[++top]= content;
		}
		bool isEmpty(){
			if(top==-1)
				return true;
			return false;
		}
		int pop (){
			if(isEmpty()){
				cout << "Underflow";
			}
			else{
				int n= -1;
				n= ptr[top--];
				return n;
			}
		}
};

int main(){
	class stack s(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.Display();
	cout << endl << s.pop() << endl;
	s.Display();
	return 0;
}

