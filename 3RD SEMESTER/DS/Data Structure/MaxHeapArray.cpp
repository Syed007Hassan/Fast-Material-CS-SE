#include<iostream>

using namespace std;

class MaxHeap
{
	int size;
	int current;
	int *a;
	
	public:
		MaxHeap()
		{
			a= new int[1];
			current=-1;
			size=0;
		}
		void swap(int &a,int &b)
		{
			int temp;
			temp=a;
			a=b;
			b=temp;
		}
		bool insert(int value)
		{
			if(current==-1)
			{
				current++;
				size++;
				a[current]=value;
				return true;
			}
			else
			{
				size++;
				current++;
				a[current]=value;
				
				for(int i=current;i>0;i=(i-1)/2)
				{
					if(a[i]>a[(i-1)/2])
					{
						swap(a[i],a[(i-1)/2]);
					}
				}
				return true;
			}
		}
		bool del()
		{
			if(current==-1)
			{
				cout << "Empty Heap\n";
				return true;
			}
			else
			{
				swap(a[0],a[current]);
				a[current]=INT_MIN;
				current--;
				size--;
				
				for(int i=0;i<size;)
				{
					if(((2*i)+1)>current)
					{
						break;
					}
					else if(a[((2*i)+1)]>a[((2*i)+2)]&&((2*i)+1)<=current&&((2*i)+2)<=current)
					{
						if(a[i]<a[((2*i)+1)])
						{
							swap(a[i],a[((2*i)+1)]);
							i=((2*i)+1);
						}
						else
						{
							break;
						}
					}
					else if(a[((2*i)+1)]<a[((2*i)+2)]&&((2*i)+1)<=current&&((2*i)+2)<=current)
					{
						if(a[i]<a[((2*i)+2)])
						{
							swap(a[i],a[((2*i)+2)]);
							i=((2*i)+2);
						}
						else
						{
							break;
						}
					}
					else if(((2*i)+1)<=current&&((2*i)+2)>current)
					{
						if(a[i]<a[((2*i)+1)])
						{
							swap(a[i],a[((2*i)+1)]);
							i=((2*i)+1);
						}
						else
						{
							break;
						}
					}
					else
					{
						break;
					}
				}	
			}
		}
		void print()
		{
			int i;
			
			for(i=0;i<size;i++)
			{
				cout <<a[i]<<"  ";
				
			}
			cout <<endl<<"Size : "<<size<<endl<<"Current : "<<current<<endl;
		}
};
int main()
{
	MaxHeap ob;
	ob.insert(5);
	ob.insert(10);
	ob.insert(8);
	ob.insert(12);
	ob.insert(11);
	ob.insert(14);
	ob.insert(13);
	ob.insert(22);
	ob.insert(43);
	ob.insert(9);
	
	ob.print();
	
	ob.del();
	ob.print();
	ob.del();
	ob.print();
	ob.del();
	ob.print();
	ob.del();
	ob.print();
	ob.del();
	ob.print();
	ob.del();
	ob.print();
	ob.del();
	ob.print();
	ob.del();
	ob.print();
	ob.del();
	ob.print();
	ob.del();
	ob.print();
	ob.del();
}
