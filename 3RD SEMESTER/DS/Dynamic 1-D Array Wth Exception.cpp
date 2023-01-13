#include<iostream>
#include<cstring>
#include<stdexcept>
#include <stdlib.h> 
using namespace std;

class DynamicArray {
	private:
		int *ptrarr;
		int length;
		int nextindex;
	public:
		DynamicArray(int size) {
			ptrarr = new int[size];
			length = size;
			nextindex = 1;
		}

		DynamicArray(const DynamicArray &darr) {
			length = darr.length;
			nextindex = darr.nextindex;
			ptrarr = new int[length];

			memcpy(ptrarr,darr.ptrarr,sizeof(int)*length);
		}

		int& operator [] (int index) {
			try{
				if(index<0||index>=nextindex)
					throw out_of_range("Index Invalid");
				if(index>nextindex)
				nextindex = index+1;

			return *(ptrarr+index);
			}
			catch(out_of_range &ex)
			{
				cout<<ex.what()<<endl;
				exit(EXIT_FAILURE);
			}
		}

		DynamicArray& operator = (const DynamicArray &darr) {
			length = darr.length;

			int*ptrn;
			ptrn= new int[length];

			memcpy(ptrarr,darr.ptrarr,sizeof(int)*length);

			delete []ptrarr;
			ptrarr = ptrn;

			return *this;
		}

		int size() {
			return length;
		}

		void add(int index,int val) {
			try{
				if(index<0||index>=nextindex){
					throw out_of_range("Index Invalid");
				}	
				ptrarr[nextindex++] = val;
				
			}
			catch(out_of_range &ex)
			{
				cout<<ex.what()<<endl;
				exit(EXIT_FAILURE);
			}
		}
		
		~DynamicArray() {
			delete []ptrarr;
		}
};

int main()
{
	DynamicArray arr(5);

	arr[0]=3;
	//arr[6]=5;
	
	DynamicArray arr2 = arr;
	
	cout<<arr[0];
	
}
