// C++ program to calculate the area of a wall

#include <iostream>
using namespace std;

// declare a class
class Wall {
   private:
    double length;
    double height;
    double width;

   public:
    // create parameterized constructor
    Wall(double len, double hgt,double wid) {
        // initialize private variables
        length = len;
        height = hgt;
        width=wid;
    }

    double calculateArea() {
        return length * height;
    }
    
    double calculateVolume(){
    	
    	return length*height*width;
	}
};

int main() {
    // create object and initialize data members
    Wall wall1(10.54, 8.65,9.87);
  

    cout << "Area of Wall: " << wall1.calculateArea() << endl;
    cout << "Volume of Wall: " << wall1.calculateVolume() << endl;

    return 0;
}
