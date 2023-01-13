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
   Queue(int len) : queue(NULL), rear(0),front(-1), length(len)
  {
    // Parameterized Constructor
    queue = new (nothrow) int[length];
    if (!queue)
      for (int i = 0; i < length; i++)
        queue[i] = -1;
  }

//
//void enqueue ( int element ) {
//	
//     if ( queue ) {
//     	
//     if ( rear < length) {
//     //	cout<<rear<<" rear "<<endl;
//     queue [++rear] = element;
//    
//    //	cout<<front<<" front "<<endl;
//	 if ( front == -1)
//     front = rear;
//      return ;
//  }
//
// } 
// else{
//cout <<"Queue is full "<<endl;
//  }
//}

//circular queue

void enqueue ( int el ) {
if ( ( front == 0 && rear == length - 1) || ( rear == front - 1) )
cout << "Queue is Full..."<<endl;
else if ( front == -1 ) {
front = rear = 0;
queue [ front ] = el;
} else {
queue [++rear ] = el;
}

}


int dequeue () {
int value = -1;
if ( front == -1 ) {
cout<< " Queue is Empty...!”"<<endl;
return value;
}
value = queue [ front ]; 
queue [front ] = -1;
if (front == rear ){
front = rear = -1;
} else if ( front == length -1 ){ front = 0; }
else front++;
return value;
}

//int dequeue ( ) {
//int value = -1;
//   
//     if ( queue ) {
//     if (front != -1) {
//     value = queue [ front ];
//     for (int i = 0; i <= rear; i++)
//      queue [ i ] = queue [ i + 1];
//      rear--;
//
//   }
//}  
//  else { cout <<"Queue is full "<<endl; }
//  return value;
//}



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
       ql.enqueue(1);
    
   
   cout<<ql.dequeue()<<endl;
   cout<<ql.dequeue()<<endl;
   cout<<ql.dequeue()<<endl;
   cout<<ql.dequeue()<<endl;
  
   
  return 0;
}
