#include <iostream>

using namespace std;

class Node
{
public:
  int info;
  Node *prev;

  Node()
  {
    prev = 0;
  }

  Node(int value, Node *ptr = 0)
  {
    info = value;
    prev = ptr;
  }
};

class Stack
{
private:
  Node *top, *temp;

public:
  Stack()
  {
    top = temp = NULL;
  }

  void push(int el)
  {
    top = new Node(el, top);
  }

  int pop()
  {
    int value;
    if (!isEmpty())
    {
      value = top->info;
      temp = top;
      top = top->prev;
      delete temp;
      temp = NULL;
      return value;
    }
    else
    {
      cout << "Stack is empty..!";
      return -1;
    }
  }

  int peek()
  {
    if (isEmpty())
    {
      cout << "Stack is empty..!";
      return -1;
    }
    else
    {
      return top->info;
    }
  }
  
  
  int peek_at_position(int pos){
  	
       temp = top;
       int i;
       
       if( isEmpty()){
       	cout<<"Stack is empty "<<endl;
	   }
	   else{
	   	
	   	for(i;i<pos-1 && temp!=0;i++){
	   		temp = temp->prev;
		   }
		   
		   if(temp!=0){
		   	return temp->info;
		   }
	   		   	
	   }
  	
  }

  void clear()
  {
    if (!isEmpty())
    {
      while (top != NULL)
      {
        temp = top;
        top = top->prev;
        delete temp;
        temp = NULL;
      }
    }
    else
    {
      cout << "Stack is already Empty..!";
    }
  }

  ~Stack()
  {
    clear();
  }

  int isEmpty()
  {
    return top == NULL;
  }

  void printStack()
  {
    if (!isEmpty())
    {
      temp = top;
      while (temp != NULL)
      {
        cout << "\n\t" << temp->info;
        temp = temp->prev;
      }
    }
    else
    {
      cout << "\n\n\tStack is Empty..!";
    }
  }
};

int main()
{
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  stack.printStack();

  cout<<endl;
//  cout << "\n\t"
//       << stack.pop();
//  cout << "\n\t"
//       << stack.pop();
//  cout << "\n\t"
//       << stack.pop();
//  cout << "\n\n\n***********";
//
//  stack.printStack(); 
  
  
  cout<<stack.peek_at_position(5);
//  stack.clear();
 // stack.printStack();

  return 0;
}
