/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Rule of Three (Examples)                                        *
* Dated: September 12, 2007                                                *
* Version: 1.2   Update on Copy Constructor and assignment operator        *                                                 
* Last modified: September 20, 2007                                        *
****************************************************************************/
#include <iostream>

using namespace std;

/* A point class of interger co-ordinates as point in 2D     */
/* it has got two data members abscissa (x) and ordinate (y) */
/* this example class use dynamic memory for objects         */ 
 
class Point2D{
private :
	int * itsX;
	int * itsY;
public:
	
	/* default constructor -------------------       */
	/* grab memory using new operator and initialize */ 
	Point2D(){ 
	
	  itsX = new int;
	  itsY = new int;
	  *itsX=*itsY=0;
	  cout<< "Default Constructor" << endl;
	}

    /* parametric constructor -------------------       */
	/* grab memory using new operator and initialize    */ 
   Point2D(int a, int b){ 
	
	  itsX = new int;
	  itsY = new int;
	  *itsX=a;
	  *itsY=b;
	  cout<< "Parametric Constructor" << endl;
	}
	
	    /* User define destructor -------------------              */
    	/* lease memory using delete operator and set it to null    */ 
	~Point2D()
	{
		if (itsX != 0) delete itsX; itsX=0;
		if (itsY != 0) delete itsY; itsY=0;
		cout<< "User-define destructor" << endl;
	}

    Point2D(const Point2D & rhs){
    	
      itsX = new int;
	  itsY = new int;
	  *itsX=rhs.getX();
	  *itsY=rhs.getY();
      cout<< "Copy Constructor" << endl;
    	
    }
    
    int getX() const { return *itsX;}
    int getY() const { return *itsY;}
    
    void setX(int a) 
	{  itsX = new int;
	   *itsX=a;
    }
	
	void setY(int b) 
	{  itsY = new int;
	   *itsY=b;
    }
	
	Point2D   operator=( const Point2D& rhs){
		
	cout<< "Assignment Operator" << endl;
	if (this != &rhs)
	   {
	   delete itsX;
	   delete itsY;
		itsX= new int;
		*itsX = rhs.getX();
		itsY= new int;
		*itsY = rhs.getY();
     	}
	return(*this);
		
	}
	   
    double distance(const Point2D & rhs){
    	
     return((this->getX()-rhs.getX())*(this->getX()-rhs.getX()));
    }
	
};


// Driver Program 

int main(){
	
	Point2D P1, P2(2,3);
	
	cout << P1.getX() <<  P1.getY()  << endl;
	cout << P2.getX() <<  P2.getY()  << endl;
	
	P1=P2;
	
	cout << P1.getX() <<  P1.getY()  << endl;
	
	return 0;
}

