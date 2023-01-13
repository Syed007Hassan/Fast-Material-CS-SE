#include <iostream>
using namespace std;


class Shape {
  
   public:
    int l,b,h;

    virtual float getArea() = 0;
};


class Rectangle : public Shape {
   public:
    float getArea(){
        return l*b;
    }
};


class Triangle : public Shape {
   public:
    float getArea() {
        return (0.5*b*h);
    }
};

int main() {
   
    Rectangle rec;
     Triangle tri;

    cout << "Enter the length of the Rectangle: ";
    cin>>rec.l;
    cout << "Enter the breath of the Rectangle: ";
    cin>>rec.b;
    cout << "Area of Rectangle: " << rec.getArea()<< endl;

    cout << "\nEnter the breath of the triangle: ";
    cin>>tri.h;
    cout << "Enter the height of the triangle: ";
    cin>>tri.b;
    cout << "Area of Triangle: " << tri.getArea()<< endl;
    return 0;
}


