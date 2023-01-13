#include <iostream>
using namespace std;

class Count{
	private:
		static int obj_num;
	public:
		Count() {
	
		//	obj_num=1;
		}
		
		obj_count() {
			cout << "Object Created: " << obj_num++<< endl;
		}
		
		~Count(){
			static int i=3;
			cout<<"\nDistroying Object "<<i--<<endl;
		}
};

int Count::obj_num=1;


main()
{
	Count c1,c2,c3;
	c1.obj_count();
	c2.obj_count();
	c3.obj_count();
}


