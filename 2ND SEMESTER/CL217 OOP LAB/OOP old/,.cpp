#include <iostream>
#include <new>
#include <algorithm>
using namespace std;

//Template Class T
template <class T>
class DynArray {
protected:
    int size;
    T * DynamicArray;
public:
    DynArray(){};
    DynArray(size_t s): size(s) {
        DynamicArray = new T[size];
        for (int i = 0; i<size; i++) {
            cout << "Element " << i << ": ";
            cin >> DynamicArray[i];

        }
    }
    //Sort Array
    void Sort(){
        sort(DynamicArray, DynamicArray+size);
        for (int i=0; i<size; i++) {
            cout << DynamicArray[i] << endl;
        }
    }

    //Clear Heap
    ~DynArray() {
        delete []DynamicArray;
    }
};

int main() {
    int sizeOfArry;
    cout << "Enter size of Array: ";
    cin >> sizeOfArry;

    //Use as an int Array;
    DynArray<int> intArray = DynArray<int>(sizeOfArry);
    intArray.Sort();
}
