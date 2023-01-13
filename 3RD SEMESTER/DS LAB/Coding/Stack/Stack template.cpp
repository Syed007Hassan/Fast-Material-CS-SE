#include <iostream>
using namespace std;

template <class T>
class Stack{
	private:
		int top;
		int size;
		T* ptr;
	public:
		Stack(int n){
			top=-1;
			size = n;
			ptr = new T(n);
		}
		~Stack(){
			delete[] ptr;
			ptr= NULL;
		}
		
		bool isEmpty(){
			if(top==-1)
				return true;
			return false;
		}
		
		bool isFull(){
			if(top==size-1)
				return true;
			return false;
		}
		
		void push(T a){
			if(!isFull()){
				ptr[++top]= a;
			}
			else{
				cout << "Stack Overflow";
				exit(0);
			}
		}
		
		T& pop(){
			if(!isEmpty()){
				return ptr[top--];
			}
			else{
				cout << "Stack underflow";
				exit(0);
			}
		}
		
		T& peek(){
			if(!isEmpty()){
				return ptr[top];
			}
			else{
				cout << "Stack is empty.\n";
			}
		}
		
		void Display(){
			for(int i= top; i>-1; i--){
//				cout << pop() << endl;
				cout << ptr[i] << " ";
			}
		}
		
};

int main(){
	Stack<int> S1(5);
	S1.push(1);
	S1.push(2);
	S1.push(3);
	S1.push(4);
	S1.push(5);
	S1.Display();
	return 0;
}
