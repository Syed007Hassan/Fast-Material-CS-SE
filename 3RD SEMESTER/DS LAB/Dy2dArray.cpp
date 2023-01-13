#include<iostream>
#include<stdexcept>

using namespace std;

class Dynamic2D
{
	int **p;
	int n_rows;
	int n_column;
	int size;
	
	public:
		// default constructor
		Dynamic2D()
		{
			p = new(nothrow) int*[1];
			n_rows=1;
			for(int i=0; i<n_rows; i++)
			{
				p[i]=new int[1];
			}
			n_column=1;
			size=n_rows*n_column;
		}
		// parameterized
		Dynamic2D(int n_rows,int n_column)
		{
			try
			{
				p = new(nothrow) int*[n_rows];
				
				if(p==NULL || n_column <0)
				{
					throw out_of_range("Failed in allocating memory");
				}
				this->n_rows=n_rows;
				for(int i=0; i<n_rows; i++)
				{
					p[i]=new int[n_column];
				}
				this->n_column=n_column;
				size=n_rows*n_column;
					
			}
			catch(out_of_range &e)
			{
				cout << e.what()<<endl;
			}
		}
		// function that will initialize the newly created array 
		void set()
		{
			int num=1;
			for(int i=0; i<n_rows;i++)
			{
				for(int j=0;j<n_column;j++)
				{
					p[i][j]=num;
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
					cout << p[i][j] << " ";
				}
				cout <<endl;
			}
			cout <<"\n";
		}
		// copy constructor for newly created object
		Dynamic2D (const Dynamic2D &ob)
		{
			cout<<"COPY CONSTRUCTOR HAS BEEN CALLED "<<endl;
			size=ob.size;
			n_rows=ob.n_rows;
			n_column=ob.n_column;
			
			p = new int*[n_rows];
			for(int i=0;i<n_rows;i++)
			{
				p[i]=new int[n_column];
				memcpy(p[i],ob.p[i],sizeof(int)*n_column);
			}
		}
		// assignment operator for initializing an old created object with another object 
		Dynamic2D& operator = (const Dynamic2D &ob )
		{
			
			for(int i=0;i<n_rows;i++)
			{
				delete[]p[i];
			}
			delete[]p;
			p=NULL;
			
			size=ob.size;
			n_rows=ob.n_rows;
			n_column=ob.n_column;
			
			p = new int*[n_rows];
			for(int i=0;i<n_rows;i++)
			{
				p[i]=new int[n_column];
				memcpy(p[i],ob.p[i],sizeof(int)*n_column);
			}
		}
		// funtion/operator that will return the value of desired index
		int& operator ( ) (int row_num, int col_num) 
		{
			try 
			{
				if ( row_num < 0 || row_num >= n_rows || col_num < 0 || col_num >= n_column )
				{
					throw out_of_range ("Index Out Of Bounds Exception");
				}
				return p [row_num] [col_num];
			} 
			catch (out_of_range &ex) 
			{
				cout<<ex.what()<<endl;
				
			}
		}
		// channing function to set value of more than one index in one line;
		Dynamic2D& set(int row_i,int column_i,int val)
		{
			try 
			{
				if ( row_i < 0 || row_i >= n_rows || column_i < 0 || column_i >= n_column )
				{
					throw out_of_range ("Index Out Of Bounds Exception");
				}
				p[row_i][column_i]=val;
				return (*this);
				
			} 
			catch (out_of_range &ex) 
			{
				cout<<ex.what()<<endl;
				
			}	
		}
		// push desired row that you want to pushback
		void pushback_row(int *array,int size)
		{
			try
			{
				if(size!=n_column)
				{
					throw out_of_range("Invalid size of row\n");
				}
				int **newp = new int* [n_rows+1];
				for(int i=0;i<n_rows+1;i++)
				{
					newp[i]=new int[n_column];
				}
				for(int i=0;i<n_rows;i++)
				{
					memcpy(newp[i],p[i],sizeof(int)*n_column);
				}
				
				memcpy(newp[n_rows],array,sizeof(int)*n_column);
				for(int i=0;i<n_rows;i++)
				{
					delete []p[i];
				}	
				delete[]p;
				p = newp;
				n_rows++;
			}
			catch (out_of_range &ex) 
			{
				cout<<ex.what()<<endl;
				
			}	
		}
		// overloaded push back that will attach a row of size of column with all Zeros
		void pushback_row()
		{
			int **newp = new int* [n_rows+1];
			for(int i=0;i<n_rows+1;i++)
			{
				newp[i]=new int[n_column];
			}
			for(int i=0;i<n_rows;i++)
			{
				memcpy(newp[i],p[i],sizeof(int)*n_column);
			}
			int *array=new int[n_column];
			for(int i=0;i<n_column;i++)
			{
				array[i]=0;
			}
			memcpy(newp[n_rows],array,sizeof(int)*n_column);
			for(int i=0;i<n_rows;i++)
			{
				delete []p[i];
			}	
			delete[]p;
			delete[]array;
			p = newp;
			n_rows++;	
		}
		// for desired values of pushing back a column
		void pushback_col(int *array,int size)
		{
			try
			{
				if(size!=n_rows)
				{
					throw out_of_range("Invalid size of row\n");
				}
				int **newp = new int* [n_rows];
				for(int i=0;i<n_rows;i++)
				{
					newp[i]=new int[n_column+1];
				}
				for(int i=0;i<n_rows;i++)
				{
					for(int j=0;j<=n_column;j++)
					{
						if(j<n_column)
						{
							newp[i][j]=p[i][j];
						}
						else
						{
							newp[i][j]=array[i];
						}
					}
				}
				for(int i=0;i<n_rows;i++)
				{
					delete []p[i];
				}	
				delete[]p;
				p = newp;
				n_column++;;
			}
			catch (out_of_range &ex) 
			{
				cout<<ex.what()<<endl;
				
			}	
		}
		// pushback only zeros
		void pushback_col()
		{
			int **newp = new int* [n_rows+1];
			for(int i=0;i<n_rows;i++)
			{
				newp[i]=new int[n_column+1];
			}
			for(int i=0;i<n_rows;i++)
				{
					for(int j=0;j<=n_column;j++)
					{
						if(j<n_column)
						{
							newp[i][j]=p[i][j];
						}
						else
						{
							newp[i][j]=0;
						}
					}
				}
	
			for(int i=0;i<n_rows;i++)
			{
				delete []p[i];
			}	
			delete[]p;
			
			p = newp;
			n_column++;	
		}
		~Dynamic2D()
		{
			for(int i=0;i<n_rows;i++)
			{
				delete []p[i];
			}
			delete[]p;
		}
		
		
				
};
int main()
{
	Dynamic2D ob(2,2);
	ob.set();
	ob.display();
	
	Dynamic2D ob1;
	ob1.set();
	ob1.display();
	ob1=ob;
	ob1.display();
	
	ob1.set(1,1,0);
	ob1.display();
	
//	int arr[2]={5,6};
//	ob1.pushback_row(arr,2);
//	
//	ob1.display();
//	ob1.pushback_row();
//	ob1.display();
//	ob1.set(3,0,7).set(3,1,8);
//	ob1.display();
//	int array[4]={10,20,30,40};
//	ob1.pushback_col(array,4);
//	ob1.display();
//	ob1.pushback_col();
//	ob1.display();

  Dynamic2D ob3(ob);
  
  ob3(4,4);

	
	
}
