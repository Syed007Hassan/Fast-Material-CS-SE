#include <iostream>

using namespace std;

class Queue
{
private:
  int *queue, rear,front, length;

public:
  Queue() : queue(NULL),rear(0),front(0), length(10)
  {
    // Default Constructor
  }
   Queue(int len) : queue(NULL), rear(-1),front(-1), length(len)
  {
    // Parameterized Constructor
    queue = new (nothrow) int[length];
    if (!queue)
      for (int i = 0; i < length; i++)
        queue[i] = -1;
  }


void enqueue ( int element ) {
	
     if ( queue ) {
     	
     if ( rear < length) {
     //	cout<<rear<<" rear "<<endl;
     queue [++rear] = element;
    
    //	cout<<front<<" front "<<endl;
	 if ( front == -1)
     front = rear = 0;
     
      return ;
  }

 } 
 else{
cout <<"Queue is full "<<endl;
  }
}


int dequeue ( ) {
int value = -1;
   
     if ( queue ) {
     if (front != -1) {
     value = queue [ front ];
     for (int i = 0; i <= rear; i++)
      queue [ i ] = queue [ i + 1];
      rear--;

   }
}  
  else { cout <<"Queue is full "<<endl; }
  return value;
}



  int isEmpty()
  {
    return !queue;
  }

 

  void clear ( )
{
if ( !isEmpty ( ) )
{
delete [ ] queue;
front = rear = -1;
}
}


};

int main()
{

   Queue ql(3);
   
   ql.enqueue(5);
     ql.enqueue(3);
       ql.enqueue(2);
       
    
   
   cout<<ql.dequeue()<<endl;
   cout<<ql.dequeue()<<endl;
   cout<<ql.dequeue()<<endl;
  
   
  return 0;
}
