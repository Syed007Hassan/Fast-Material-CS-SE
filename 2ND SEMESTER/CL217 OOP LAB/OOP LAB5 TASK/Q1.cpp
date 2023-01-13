#include <iostream>

using namespace std;

class Pair{
	public:
		int a=10;
		int b= 5;
		
		void sum()
		{
			cout << "Sum = " << a+b;
		}
};

int main()
{
	Pair p;
	p.sum();
}

