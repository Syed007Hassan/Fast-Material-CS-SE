#include<iostream>
#include<math.h>
using namespace std;

class Point{
	
    int x1, y1,x2,y2;
    public:
        Point(int a, int b,int c, int d){
            x1 = a;
            y1 = b;
            x2 = c;
            y2 = d;
            
            
			
			void displayPoint();
			void distance();
            
            
        }

        void displayPoint(){
            cout<<"The point (x1,y1) is ("<<x1<<", "<<y1<<")"<<endl;
            cout<<"The point (x2,y2) is ("<<x2<<", "<<y2<<")"<<endl;
        }
        
        
        void distance(){
        	
        		float dist;
	
	dist=sqrt((pow(x2-x1,2)+pow(y2-y1,2)));
	
	cout<<"The distance btw the points is "<<dist<<endl;
        	
		}
        
        

};


int main(){
    Point p(2,2,5,8);
    p.displayPoint();
    
    p.distance();


    return 0;
}
