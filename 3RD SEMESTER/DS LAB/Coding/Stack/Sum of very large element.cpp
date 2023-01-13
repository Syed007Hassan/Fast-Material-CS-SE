#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Stack{
	int top;
	int size;
	T* array;
public:
	Stack(int size=0){
		this->size = size;
		array = new T[size];
		memset(array,0,sizeof(array));
		top = -1;
	}
	void Push(T el){
		if(isFull()){
			cout << "Stack is full\n";
		}
		else{
			array[++top] = el;
		}
	}
	T pop(){
		if(isEmpty()){
			cout << "Stack is empty.";
			return -1;
		}
		else{
			return array[top--];
		}
	}
	bool isFull(){
		if(top==size-1)
			return true;
		return false;
	}
	bool isEmpty(){
		if(top<0)
			return true;
		return false;
	}
	void Display(){
		for(int i=top; i>-1; i--){
			cout << array[i];
		}
		cout << endl;
	}
	
	Stack<int> AddTwoStacks(Stack<T> s2){
		int carry=0;
		int s;
		if(this->size > s2.size)
			s= size;
		else
			s= s2.size;
		
		Stack<int> s3(s);
		
		while(!this->isEmpty() && !s2.isEmpty()){
			int t= (int)pop()-48;
			t += (int)s2.pop()-48;
			t += carry;
			if(t/10>0){
				s3.Push(t%10);
				carry = t/10;
			}
			else{
				s3.Push(t);
				carry=0;
			}
		}
		while(!this->isEmpty()){
			int  t= (int)pop()-48;
			t+= carry;
			if(t/10>0){
				s3.Push(t%10);
				carry = t/10;
			}
			else{
				s3.Push(t);
				carry=0;
			}
		}
		while(!s2.isEmpty()){
			int  t= (int)s2.pop()-48;
			t+= carry;
			if(t/10>0){
				s3.Push(t%10);
				carry = t/10;
			}
			else{
				s3.Push(t);
				carry=0;
			}
		}
		return s3;
	}
};


int main(){
	string s1,s2;
//	cin >> s1;
//	cin >> s2;
	s1= "18274364583929273748459595684373";
	s2= "8129498165026350236";
	
	Stack<char> ss(s1.length());
	Stack<char> ss2(s2.length());
	
	for(int i=0; i<s1.length(); i++)
		ss.Push(s1[i]);
	
	for(int i=0; i<s2.length(); i++)
		ss2.Push(s2[i]);
	
	
	Stack<int> ss3;
	ss3 = ss.AddTwoStacks(ss2);
	ss3.Display();
	
	return 0;
}

// 18274364583929273748459595684373
// 8129498165026350236
