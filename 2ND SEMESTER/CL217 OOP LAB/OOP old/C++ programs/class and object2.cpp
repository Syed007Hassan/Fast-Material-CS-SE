#include<iostream>
using namespace std;

class Robot {
  
  private:
    float locX;
    float locY;
    float facing;
    
    public:
    void setLocation(float x, float y){
  
     if ((x < 0.0) || (y < 0.0)){
	 
     cout << "Illegal location!!" << endl;
 }
    else {
      locX = x;
      locY = y;
      
      cout<<locX<<" value of x\n"<<locY<<" value of y";
  }
}

};

int main(){
	
	Robot r1;
	
	r1.setLocation(2,2);
	
	
	return 0;
	
}



