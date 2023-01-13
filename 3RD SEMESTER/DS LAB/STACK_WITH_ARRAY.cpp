#include<iostream>
using namespace std;

class Stack{
	

	int top;
	
	public: 
	
    int len;  
	int data[];
	
	Stack(int l):len(l){
		
		data[len];
		top = -1;
	}
	
	
	void push(int c){
		
		if(!(isFull())){
			
			data[++top] = c;
		}
		else{
			
			cout<<"Stack over flow "<<endl; 
		}		
	}
	
	int pop(){
	
	   int val = -1;	
		
		if(!isEmpty()){
			
			val = data[top];
			data[top--] = -1;
			
			return val;
		}
		
		else{
			
			cout<<"Stack under flow "<<endl;
			exit(0);
			
			
		}				
	}
	
	int isEmpty(){
		
       return top == -1;
	}
	
	int isFull(){
		return top == len -1;
	}
	
	
		
		
};


int main(){
	
   	Stack stk(10);
   	
    stk.push(1);  
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);
    stk.push(10);
    stk.push(11);
		
		
		

	
		
	for(int i=0;i>=0;i++){

    	cout<<stk.pop()<<endl;  
		
		}	
   
}
