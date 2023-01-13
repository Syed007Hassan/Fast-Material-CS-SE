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
			size=0;
			current=-1;
			a=new int [1];
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
				current++;
				size++;
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
		bool dele()
		{
			if(current==-1)
			{
				return false;
			}
			else
			{
				swap(a[0],a[current]);
				current--;
				
				for(int i=0;i<=current;i++)
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
							i=(2*i)+1;
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
		}
};
int main()
{
	int num;
	cout << "Enter number of elements : ";
	cin >> num;
	cout << "Enter Elements : ";
	int number;
	MaxHeap ob;
	for(int i=0;i<num;i++)
	{
		cin >> number;
		ob.insert(number);
	}
	for(int i=0;i<num;i++)
	{
		ob.dele();
	}
	
	ob.print();
}
