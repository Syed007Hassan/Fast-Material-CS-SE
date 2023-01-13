#include <iostream>
#include <cstring>
using namespace std;

// dsa along with rule of 3

template <class T>
class A{
	T *data;
	int size;
public:
	A(){
		data = NULL;
		size = 0;
	}
	A(int size){
		this->size = size;
		data = new int[size];
		memset(this->data, 0, sizeof(int)*this->size);
	}
	A(const A &rhs){
		this->size = rhs.size;
		this->data = new int[this->size];
		memcpy(this->data, rhs.data, sizeof(int)*size);
	}
	A& operator=(const A &rhs){
		if(this != rhs){
			delete[] data;
			this->size = rhs.size;
			this->data = new int[this->size];
			memcpy(this->data, rhs.data, sizeof(int)*size);
		}
		return *this;
	}
	~A(){
		if(data)
			delete[] data;
			data = 0;
	}
};

int main(){
	A<int> ob(5);
	return 0;
}
