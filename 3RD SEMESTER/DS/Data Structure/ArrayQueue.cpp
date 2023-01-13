#include<iostream>
#define MAX 5
using namespace std;
class Queue
{
	int front;
	int rear;
	int size;
	int a[MAX];
	
	public:
		Queue()
		{
			front=-1;
			rear=-1;
			size=0;
		}
		bool enqueue(int value)
		{
			if(rear==MAX-1)
			{
				cout << "Full Queue\n";
				return false;
			}
			if(front==-1&&rear==-1)
			{
				front++;
				rear++;
				a[front]=value;
				cout << a[front]<<" Enqueued\n";
				size++;
				return true;
			}
			else
			{
				rear++;
				a[rear]=value;
				cout << a[rear]<<" Enqueued\n";
				size++;
				return true;
			}
		}
		bool dequeue()
		{
			if(front==-1&&rear==-1)
			{
				cout << "Empty Queue\n";
				return false;
			}
			if(front==rear&&front!=-1&&rear!=-1)
			{
				cout << a[front]<<" dequeued\n";
				a[front]=INT_MIN;
				front=-1;
				rear=-1;
				size--;
				return true;
			}
			else
			{
				cout << a[front]<<" dequeued\n";
				a[front]=INT_MIN;
				front++;
				size--;
				return true;
			}	
		}
		int num()
		{
			return size;
		}
		int peek()
		{
			return a[rear];
		}
		
};
int main()
{
	Queue ob;
	ob.enqueue(1);
	ob.enqueue(2);
	ob.enqueue(3);
	ob.enqueue(4);
	ob.enqueue(5);
	ob.enqueue(6);
	ob.dequeue();
	ob.enqueue(1);
	cout << ob.num()<<endl;
	cout << ob.peek();
}
