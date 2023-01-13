#include <iostream>
using namespace std;

   class Product {
    public:

    calc(int i,int j) {
    cout << "\nThe product of two integers is: " << i*j;
}

    calc(int i,int j, int k) {
    cout << "\nThe product of three integers is: " << i*j*k;
}

    calc(double i, double j) {
    cout << "\nThe product of two decimal digits is: " << i*j;
}

    calc(double i, double j, double k) {
    cout << "\nThe product of three decimal digits is: " << i*j*k;
}
};

    main() {
    Product p;
    p.calc(3,5);
   p.calc(4,8,6);
   p.calc(3.3,5.5);
   p.calc(2.8,6.4,9.7);
}

