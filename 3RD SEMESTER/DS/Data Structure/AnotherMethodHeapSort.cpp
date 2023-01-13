#include<iostream>

using namespace std;

class MinHeap
{
	int size;
	int current;
	int *a;
	
	public:
		MinHeap()
		{
			a= new int[1];
			size=0;
			current=-1;
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
				size++;
				current++;
				a[current]=value;
				return true;
			}
			else
			{
				size++;
				current++;
				a[current]=value;
				for(int i=current;i>0;i=((i-1)/2))
				{
				
					if(a[i]<a[(i-1)/2])
					{
						swap(a[i],a[(i-1)/2]);
					}
				}
				return true;
			}
		}
		int del()
		{
			int num;
			if(current==-1)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				swap(a[0],a[current]);
				num=a[current];
				current--;
				size--;
				
				for(int i=0;i<size; )
				{
					if(((2*i)+1)>current)
					{
						break;
					}
					else if(a[(2*i)+1]<a[(2*i)+2]&&(2*i)+1<=current&&(2*i)+2<=current)
					{
						if(a[i]>a[(2*i)+1])
						{
							swap(a[i],a[(2*i)+1]);
							i=(2*i)+1;
						}
						else break;
					}
					else if(a[(2*i)+1]>a[(2*i)+2]&&(2*i)+1<=current&&(2*i)+2<=current)
					{
						if(a[i]>a[(2*i)+2])
						{
							swap(a[i],a[(2*i)+2]);
							i=(2*i)+2;		
						}
						else break;
					}
					else if(((2*i)+1)<=current&&((2*i)+2)>current)
					{
						
						if(a[i]>a[(2*i)+1])
						{
							swap(a[i],a[(2*i)+1]);
							i=(2*i)+1;
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
			return num;
		}
		~MinHeap()
		{
			if(a!=NULL)
			{
				delete []a;
			}
		}
		
};

int main()
{ 
	MinHeap ob;
	int num;
	 
	while(1)
	{
		cout << "Enter number of elements : ";
		cin >>num;
		{
			if(num==-1)
			{
				break;
			}
		}
		
		int a[num];
		cout << "Enter elements : ";
		for(int i=0;i<num;i++)
		{
			cin >> a[i];
			ob.insert(a[i]);
		}
		for(int i=0;i<num;i++)
		{
			a[i]=ob.del();
		}
		for(int i=0;i<num;i++)
		{
			cout << a[i]<<"  ";
		}
		cout << endl;
	}
	
}
