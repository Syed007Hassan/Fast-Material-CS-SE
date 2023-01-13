#include<iostream>
using namespace std;

class Animal{
	
	public:
		animalSound(){
			cout<<"The animal makes a sound"<<endl;
		}
};

class Cat: public Animal{
		
		public:
		animalSound(){
			cout<<"The cat says meow"<<endl;
		}
};

class Dog: public Animal{
		
		public:
		animalSound(){
			cout<<"The cat says bow wow"<<endl;
		}
};

class Duck: public Animal{
		
		public:
		animalSound(){
			cout<<"The duck says quack quack"<<endl;
		}
};


int main(){
	
	Animal a1;
	a1.animalSound();
	Cat c1;
	c1.animalSound();
	Dog d1;
	d1.animalSound();
	Duck d2;
	d2.animalSound();

}

