#include<iostream>
#include<cstring>
#include<stdexcept>
#include <stdlib.h> 
using namespace std;

class DynArray {
	private:
		int *ptr2d;
		int n_row,n_col,row_index,col_index,size;

	public:
		DynArray(int r,int c) {
			n_row = r;
			n_col = c;
			row_index = 0;
			col_index = 0;
			size = n_row*n_col;
			
			ptr2d = new(nothrow) int[size];
			if(!ptr2d)
				exit(EXIT_FAILURE);
		}

		DynArray(const DynArray& da) {
			size = da.size;
			n_col = da.n_col;
			n_row = da.n_row;
			row_index = da.row_index;
			col_index = da.col_index ;

			ptr2d = new(nothrow) int[n_row*n_col]; 
			if(!ptr2d)
				exit(EXIT_FAILURE);
			memcpy(ptr2d,da.ptr2d,sizeof(int)*n_col);
			}

		int length(){
			return n_row*n_col;
		}
		
		int& operator () (int r,int c){
			try{
				if(r<0||r>=n_row||c<0||c>=n_col)
					throw out_of_range("Invalid Index");
				
				return ptr2d[r*n_col+c];
			}
			catch(out_of_range& ex)
			{
				cout<<ex.what()<<endl;
				exit(EXIT_FAILURE);
			}
		}
		
		int get(int r,int c){
			try{
				if(r<0||r>=n_row||c<0||c>=n_col)
					throw out_of_range("Invalid Index");
				
				return ptr2d[r*n_col+c];
			}
			catch(out_of_range ex)
			{
				cout<<ex.what()<<endl;
				exit(EXIT_FAILURE);
			}
		}
		
		void set(int r,int c,int val){
			try{
				if(r<0||r>=n_row||c<0||c>=n_col)
					throw out_of_range("Invalid Index");
					
				ptr2d[r*n_col+c] = val;
			}
			catch(out_of_range& ex)
			{
				cout<<ex.what()<<endl;
				exit(EXIT_FAILURE);
			}
		}

		~DynArray() {
			delete[] ptr2d;
		}
};

int main()
{
	DynArray da(2,3);
	
	da.set(0,2,9);
	
	cout<<da(0,2);
}
