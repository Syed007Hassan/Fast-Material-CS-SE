#include<iostream>

#define MAX 5
using namespace std;

class CircularQueue
{
	int front;
	int rear;
	int size;
	int a[5];
	
	public:
		CircularQueue()
		{
			front=-1;
			rear=-1;
			size=0;
		}
		
		bool enqueue(int value)
		{
			if(size==MAX)
			{
				cout << "Queue is full\n";
				return false;
			}
			else if(front==-1&&rear==-1)
			{
				front++;
				rear++;
				a[front]=value;
//				cout <<a[front]<<" Enqueued\n";
				size++;
				return true;
			}
			else if(rear==MAX-1&&front!=-1)
			{
				int i=0;
				while(a[i]!=-9999)
				{
					i++;
				}
				rear=i;
				size++;
				a[rear]=value;
//				cout<<a[rear]<<" Enqueued\n";
				return true;
			}
			else
			{
				rear++;
				a[rear]=value;
//				cout<<a[rear]<<" Enqueued\n";
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
			else if(front==rear&&front!=-1&&rear!=-1)
			{
				size--;
//				cout<<a[rear]<<" Dequeued\n";
				a[front]=-9999;
				front=-1;
				rear=-1;
				return true;
			}
			else if(front==MAX-1)
			{
				size--;
//				cout<<a[front]<<" Dequeued\n";
				a[front]=-9999;
				front=0;
				return true;
			}
			else
			{
				size--;
//				cout <<a[front]<<" Dequeued\n";
				a[front]=-9999;
				front++;
				return true;
			}
		}
		int peek()
		{
			return a[rear];
		}
		int getsize()
		{
			return size;
		}
		void print()
		{
			int i;
			
			for(i=0;i<5;i++)
			{
				if(a[i]==-9999)
				{
					cout << "*  ";
				}
				else
				{
					cout << a[i]<<"  ";
				}

				
			}
			cout << endl;
			cout << "Peek : "<<a[rear]<<endl;
			cout << "Size : "<<size<<endl;
		}
		
};
int main()
{
	CircularQueue ob;
	ob.enqueue(1);
	ob.enqueue(2);
	ob.enqueue(3);
	ob.enqueue(4);
	ob.enqueue(5);
	ob.dequeue();
	ob.print();
	ob.dequeue();
	ob.print();
	ob.enqueue(6);
	ob.print();
	ob.enqueue(7);
	ob.print();
	ob.dequeue();
	ob.print();
	ob.dequeue();
	ob.print();
	ob.dequeue();
	ob.print();
	ob.dequeue();
	ob.print();
	ob.dequeue();
	ob.print();
	ob.enqueue(1);
	ob.print();
}
