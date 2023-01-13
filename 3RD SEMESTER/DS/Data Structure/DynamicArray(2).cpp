#include<iostream>
#include<stdexcept>
using namespace std;

class Darray
{
	int *p;
	int length;
	int lastindex;
	
	public:
		Darray(int length)
		{	
			try
			{
				p = new (nothrow) int [length];
				
				if(p==NULL)
				{
				
					throw out_of_range ("Failed in allocating memory");
				}
				this->length= length;
				lastindex=length-1;
				
			}
			catch(out_of_range e)
			{
				cout << e.what();
			}
		}
		void display()
		{
			for(int i=0; i<length; i++)
			{
				cout << p[i]<< " ";
			}
			cout << "\nSize : "<<length<<"\nLast Index : "<< lastindex<<endl<<endl;
		}
		void set()
		{
			for(int i=0;i<length;i++)
			{
				p[i]=i+1;
			}
		}
		void operator[] (int newLength)
		{
			int *newp = new int[newLength];
			int max;
			
			if(newLength>length)
			{
				max=p[0];
				for(int i=1;i<length;i++)
				{
					if(max<p[i])
					{
						max=p[i];
					}
				}
				for(int i=0;i<length;i++)
				{
					newp[i]=p[i];
				}
				for(int i=length;i<newLength;i++)
				{
					newp[i]=max+1;
					max++;
				}
				length=newLength;
				lastindex=newLength-1;
				delete[] p;
				p=newp;
			}
			else
			{
				int *newp = new int[newLength];
				
				for(int i=0 ;i<newLength;i++)
				{
					newp[i]=p[i];
				}
				delete[]p;
				p=newp;
				length=newLength;
				lastindex=length-1;
			}
		}
		void pushback(int val)
		{
			p[lastindex+1]=val;
			length++;
			lastindex++;	
		}
		void insert(int index,int val)
		{
			int i;
			length++;
			int *newp = new int[length];
			
			if (index==0)
			{
				newp[index]=val;
				
				for(i=1;i<length;i++)
				{
					newp[i]=p[i-1];
				}
				delete[]p;
				p=newp;
				lastindex=length-1;
					
			}
			else
			{
				for(i=0;i<index;i++)
				{
					newp[i]=p[i];
				}
				newp[index]=val;
				for(int j=i+1;j<length;j++)
				{
					newp[j]=p[j-1];
				}
				delete[]p;
				p=newp;
				lastindex=length-1;
			}
		}
		void Delete(int index)
		{
			int i;
			length--;
			int *newp = new int[length];
			
			for(i=0;i<index;i++)
			{
				newp[i]=p[i];
			}
			for(int j=i;j<length;j++)
			{
				newp[j]=p[j+1];
			}
			delete[]p;
			p=newp;
			lastindex=length-1;
		}
	
		
};
int main()
{
	Darray ob(8);
	ob.set();
	ob.display();
	ob.insert(0,0);
	ob.display();
	ob.pushback(0);
	ob.display();
	
	

}
