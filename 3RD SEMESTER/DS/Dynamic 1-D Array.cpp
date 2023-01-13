#include<iostream>
#include<cstring>
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
			nextindex = 0;
		}

		DynamicArray(const DynamicArray &darr) {
			length = darr.length;
			nextindex = darr.nextindex;
			ptrarr = new int[length];

			memcpy(ptrarr,darr.ptrarr,sizeof(int)*length);
		}

		int& operator [] (int index) {
			int *ptrnew;

			if (index >= length) {
				ptrnew = new int [index+length];

				for(int i=0; i<nextindex; i++)
					ptrnew[i] = ptrarr[i];
				for(int j=nextindex; j<index+length; j++)
					ptrnew[j] = 0;

				length += index;

				delete []ptrarr;
				ptrarr=ptrnew;
			}

			if(index>nextindex)
				nextindex = index+1;

			return *(ptrarr+index);
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

		void set(int val) {
			int *ptrnew;

			if(nextindex == length) {
				length += length;
				ptrnew = new int[length];

				for(int i=0; i<nextindex; i++)
					ptrnew[i] = ptrarr[i];
				for(int j=nextindex; j<length; j++)
					ptrnew[j]=0;

				delete ptrarr;
				ptrarr = ptrnew;
			}

			ptrarr[nextindex++] = val;
		}

		~DynamicArray() {
			delete []ptrarr;
		}
};

int main() {
	DynamicArray arr(3);

	arr.set(1);
	arr.set(2);
	arr.set(5);
	
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<endl;
	
	arr[10]=10;
	
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<endl;
		
}
