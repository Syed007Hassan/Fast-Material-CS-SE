#include<iostream>
#include<stdexcept>

using namespace std;

class dynamicFlat
{
	int *p;
	int n_rows;
	int n_column;
	int size;
	
	public:
		dynamicFlat(int n_rows,int n_column)
		{
			try
			{
				p = new(nothrow) int[n_rows*n_column];
				
				if(p==NULL || n_column <0)
				{
					throw out_of_range("Failed in allocating memory");
				}
				this->n_rows=n_rows;
				this->n_column=n_column;
				size=n_rows*n_column;
					
			}
			catch(out_of_range &e)
			{
				cout << e.what()<<endl;
			}
		}
		void set()
		{
			int num=1;
			for(int i=0; i<n_rows;i++)
			{
				for(int j=0;j<n_column;j++)
				{
					p[i*n_column+j]=num;
					num++;			
				}
			}
		}
		void display()
		{
			for(int i=0; i<n_rows;i++)
			{
				for(int j=0;j<n_column;j++)
				{
					cout << p[i*n_column+j] << " ";
				}
				cout <<endl;
			}
			cout <<"\n";
		}
		int& operator () (int row_num, int col_num) 
		{
			try 
			{
				if ( row_num < 0 || row_num > n_rows || col_num < 0 || col_num > n_column )
				{
					throw 1;
					//out_of_range ("Index Out Of Bounds Exception");
				}
				return p[row_num*n_column+col_num];
			} 
			catch (int a) 
			{
				cout << "hehe";	
			}
		}
		void display(int row_i,int column_i)
		{
			cout << p[row_i*n_column+column_i];
			cout <<"\n";
		}
		void pushback_row(int *array,int size1)
		{
			try
			{
				if(size1!=n_column)
				{
					throw out_of_range("Invalid size of row\n");
				}
				int *newp = new int[size+size1];
				for(int i=0;i<size;i++)
				{
					newp[i]=p[i];
				}
				for(int j=size,i=0;j<size+n_column;j++,i++)
				{
					newp[j]=array[i];
				}
					
				delete[]p;
				p = newp;
				n_rows++;
				size=n_rows*n_column;
			}
			catch (out_of_range &ex) 
			{
				cout<<ex.what()<<endl;
				
			}	
		}
};
int main()
{
	dynamicFlat ob(2,2);
	ob.set();
	ob.display();
	int array[2]={5,6};
	ob.pushback_row(array,2);
	ob.display();
	cout << ob(3,3);
	
	
	
}
