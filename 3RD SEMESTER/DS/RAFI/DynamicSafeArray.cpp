/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: DynamicSafeArray (Examples)                                     *
* Dated: September 18, 2007                                                *
* Version: 1.0                                                             *                                                 
* Last modified: September 27, 2007                                        *
****************************************************************************/

#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;



//----------------------------------------------------------
//Exceptions class
// Very generic just to handle a single Index out of bound exception
// you can inherent it from std::exception class
class IndexOutOfBoundException
{
private:
	string message;
public:
	IndexOutOfBoundException():message("Array Index is out of Bound."){}

	string what() {return message;}
};


//----------------------------------------------------------
//Template based DynamisSafeArray class
// A linear memory model is used with pointer of specific type
// Size represent the dynamic size of the array 
// Safe access with exception 

template<class T>
class DynamicSafeArray
{
private:
	T *array;
	int size;

public:
	DynamicSafeArray();
	DynamicSafeArray(int size);
	~DynamicSafeArray();
	DynamicSafeArray(const DynamicSafeArray &rhs);

	DynamicSafeArray& operator= (const DynamicSafeArray &rhs);
	T& operator[](unsigned int i);
	const T& operator[](unsigned int i) const;

	template<class U>	//not T because it shadows previous T.
	friend ostream& operator<< (ostream &output, const DynamicSafeArray<U> &rhs);
	template<class U>
	friend istream& operator>> (istream &input, const DynamicSafeArray<U> &rhs);

	int getSize() const;
	void setSize(int pSize);

	void resize(unsigned int pSize);
	void print();
	void getInput();


	
};  // class header file

//Default constructor.
template<class T>
DynamicSafeArray<T>::DynamicSafeArray()
{
	setSize(0);
	array = NULL;		
}

//Parameterized constructor. Parameters: size of an array.
template<class T>
DynamicSafeArray<T>::DynamicSafeArray(int size)
{
	setSize(size);
	array = new T[size];
	memset(array, 0, size*sizeof(T));		//Initializes the array with zeros.
}

//Destructor.
template<class T>
DynamicSafeArray<T>::~DynamicSafeArray()
{
	//---Debug---
	// cout << "Deleted.\n";
	//------
	if (array != NULL)
	{
		delete[] array;
		array = NULL;
	}

	//Note: to check if the memory has really been deleted call print().
}

//Returns the size of the array.
template<class T>
int DynamicSafeArray<T>::getSize() const
{
	return this->size;
}

//Sets the size of an array. Checks if the size is less than 0 before setting.
template<class T>
void DynamicSafeArray<T>::setSize(int pSize)
{
	if (pSize >= 0)
	{
		this->size = pSize;
	}
	else
	{
		cout << "Invalid size. Setting size to default 0.\n";
		this->size = 0;
	}
}

//Copy constructor. Deep copy.
template<class T>
DynamicSafeArray<T>::DynamicSafeArray(const DynamicSafeArray &rhs)
{
	setSize(rhs.size);
	array = new T[size];
	memcpy(this->array, rhs.array, size*sizeof(T));
}

//Assignment operator overload
template<class T>
DynamicSafeArray<T>& DynamicSafeArray<T>::operator= (const DynamicSafeArray &rhs)
{
	if (this != &rhs) //to check the reassignment with itself.
	{
		int lSize = rhs.getSize();
		setSize(lSize);
		this->array = new T[size];
		memcpy(this->array, rhs.array, sizeof(T)*size);

	}
	return *this;
}

//for left hand side value. E.g DSA[i] = something.
template<class T>
T& DynamicSafeArray<T>::operator[] (unsigned int i)
{
	try // this function through exception sepecific to this class
	{
		if (i < 0 || i >= getSize()) throw i;
		else
		{
			return array[i];
		}
	}
	catch(unsigned int i)
	{
		IndexOutOfBoundException exceptionObj;
		cout << exceptionObj.what() << endl;
	}
}

//for right hand side value. E.g var = DSA[i]
template<class T>
const T& DynamicSafeArray<T>::operator[] (unsigned int i) const
{
	try
	{
		if (i < 0 || i >= getSize()) throw i;
		else
		{
			return array[i];
		}
	}
	catch(unsigned int i)
	{
		IndexOutOfBoundException exceptionObj;
		cout << exceptionObj.what() << endl;
	}
}

//Extraction operator overload.
template<class U>
ostream& operator<< (ostream &output, const DynamicSafeArray<U> &rhs)
{
	for (int i = 0; i < rhs.getSize(); ++i)
	{
		output << rhs.array[i] << " ";
	}
	return output;
}

//Insertion operator overload. Input complete array from input medium.
template<class U>
istream& operator>> (istream &input, const DynamicSafeArray<U> &rhs)
{
	for (int i = 0; i < rhs.getSize(); ++i)
	{
		input >> rhs.array[i];
	}
	return input;
}

//Resizes the array to desired parameter size.
//If the pSize is greater than extra elements are initialized with 0.
//If it is less then original array is copied till pSize and then chopped.
template<class T> 
void DynamicSafeArray<T>::resize(unsigned int pSize)
{
	if (size != pSize)
	{
		T *tempArray = new T[size];
		memcpy(tempArray, array, sizeof(T)*size);

		delete[] array;
		array = NULL;

		array = new T[pSize];
		memset(array, 0, sizeof(T)*pSize);

		if (pSize > size)
		{
			memcpy(array, tempArray, sizeof(T)*size);
		}
		else
		{
			memcpy(array, tempArray, sizeof(T)*pSize);
		}

		size = pSize;
		delete[] tempArray;
		tempArray = NULL;

	}
}

//Prints the entire array with endline.
template<class T>
void DynamicSafeArray<T>::print()
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

//Takes input for whole array.
template<class T>
void DynamicSafeArray<T>::getInput()
{
	for (int i = 0; i < size; ++i)
	{
		cin >> array[i];
	}
}


int main()
{
  
  int n;
  cout<< "Enter the size of the DynamicSafeArray:" <<endl;
  cin>>n;
  DynamicSafeArray<int> DSA1(n); 
  
  
  cout << " Input from insertion Operator:";
  cout << "Enter an Array DSA1: ";
  cin >> DSA1;
  
  
   cout << " Output from Extraction Operator:";
   cout << DSA1;
  
   std::ofstream out_file;
    cout << " Output from Extraction Operator to a file: ";
   out_file.open("output.txt");
   out_file << DSA1<< endl;
   out_file.close();
  

return 0;


}

