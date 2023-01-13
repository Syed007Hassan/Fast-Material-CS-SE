#include<iostream>

using namespace std;

class DynamicArray
{
	int *p;
	int length;
	int next;
	
	public:
		DynamicArray()
		{
			p= new int[10];
			
			for(int i=0; i<10;i++)
			{
				p[i]=i+1;
			}
			length=10;
			next=0;
		}
		void display()
		{
			for(int i=0; i<length;i++)
			{
				cout << p[i] << "  ";
			}
			cout << endl;
		}
		int& operator[](int newSize)
		{
			int *pnew;
			if(newSize>=length)
			{
				pnew = new int[newSize];
				
				for(int i=0;i<length;i++)
				{
					pnew[i]=p[i];
				}
				for(int j=length;j<newSize;j++)
				{
					pnew[j]=j+1;
				}
				length = newSize;
				delete[]p;
				p=pnew;
			}
			if(newSize<length)
			{
				pnew = new int[newSize];
				
				for(int i=0;i<newSize;i++)
				{
					pnew[i]=p[i];
				}
				length=newSize;
				delete []p;
				p=pnew;
			}
			
		}
		void add(int val)
		{
			int *pnew;
			
			pnew = new int [length+1];
			
			for(int i=0;i<length;i++)
			{
				pnew[i]=p[i];
			}
			pnew[length]=val;
			
			length++;
			delete[]p;
			p=pnew;
		}
		DynamicArray (const DynamicArray &dynamicArray) 
		{
			
			length = dynamicArray.length;
			p = new int [length];
			memcpy(p, dynamicArray.p, sizeof(int) * length);
		}

		int size( ) 
		{
			return length;
		}
};
int main()
{
	DynamicArray ob;
	ob.display();
	ob[12];
	ob.display();
	ob[6];
	ob.display();
	ob[8];
	ob.display();
	DynamicArray obb = ob;
	obb.display();
	obb.add(12);
	obb.display();
	
}
