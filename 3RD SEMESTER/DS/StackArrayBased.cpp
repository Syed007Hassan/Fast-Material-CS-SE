#include <iostream>

using namespace std;

class Stack
{
private:
  int *pa, top, length;

public:
  Stack() : pa(NULL), top(-1), length(10)
  {
    // Default Constructor
  }
  Stack(int len) : pa(NULL), top(-1), length(len)
  {
    // Parameterized Constructor
    pa = new (nothrow) int[length];
    if (!pa)
      for (int i = 0; i < length; i++)
        pa[i] = -1;
  }

  void clear()
  {
    delete pa;
    pa = NULL;
    top = -1;
  }

  void push(int el)
  {
    if (top < length && pa)
    {
      pa[++top] = el;
    }
    else if (!pa)
    {
      pa = new (nothrow) int[length];
      pa[++top] = el;
    }
    else
      cout << "\nStack is full";
  }

  int pop()
  {
    int value = -1;
    if (!isEmpty())
    {
      value = pa[top];
      pa[top--] = -1;
    }
    else
    {
      cout << "\n Stack is Empty...!";
    }
    return value;
  }

  int peek()
  {
    if (!isEmpty())
    {
      return pa[top];
    }
    return -1;
  }

  int isEmpty()
  {
    return !pa;
  }

  void printStack()
  {
    if (!isEmpty())
      for (int i = top; i >= 0; i--)
      {
        cout << "\n"
             << pa[i];
      }
    else
      cout << "\nStack is Empty...!";
  }

  ~Stack()
  {
    // Destructor
    if (pa != NULL)
    {
      delete[] pa;
    }
  }
};

int main()
{
  Stack stack(5);
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  stack.printStack();
  cout << "\n\nPOP";
  cout << "\n"
       << stack.pop();
  cout << "\n"
       << stack.pop();
  cout << "\n"
       << stack.pop();
  stack.push(6);
  stack.clear();
  stack.printStack();
  return 0;
}