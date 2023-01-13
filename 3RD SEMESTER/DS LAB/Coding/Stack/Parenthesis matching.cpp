#include <iostream>
#include <cstring>
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
			ptr = new T[n];
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
				cout << ptr[i] << " ";
			}
		}
		
		void ParenthesisMatching(T* exp){
			for(int i=0; i<size; i++){
				if(exp[i]=='('){
					push(ptr[i]);
				}
				if(exp[i]==')'){
					if(isEmpty()){
						cout << "Stack is empty. failed\n";
					}
					else{
//						cout << pop() << " ";
						pop();
					}
				}
			}
			if(top==-1){
				cout << "Brackets matched.\n";
			}
			else{
				cout << "Brackets not matched.\n";
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
//	S1.Display();
	
	char* exp= "(a+b)*(a-b)()";
	int l = strlen(exp);
	Stack<char> s2(l);
	
	s2.ParenthesisMatching(exp);
	return 0;
}
