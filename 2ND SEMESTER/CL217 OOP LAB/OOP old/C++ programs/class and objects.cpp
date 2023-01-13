#include<iostream>
using namespace std;

class room{
	private:
		
		double length;
		double width;
		double height;
	
	public:
	
		void getDATA(int l,int w, int h){
			length=l;
			width=w;
			height=h;
		}
		
		double area(){
			
			return(length * width);
		}
		
		double volume(){
			
			return(length*width*height);
		}
		
		
};

int main(){
	
	room r1;
	
    r1.getDATA(33.5,55.67,77.8);
	
	cout<<"The area of room r1 is "<<r1.area()<<endl;
	cout<<"the volume of room r1 is "<<r1.volume()<<endl;
	
	return 0;
	
}
