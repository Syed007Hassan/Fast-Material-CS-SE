    #include <cmath>               // To get std::sin() and std::cos()
    class Point {
    public:
      static Point rectangular(float x, float y);      // Rectangular coord's
      static Point polar(float radius, float angle);   // Polar coordinates
      // These static methods are the so-called "named constructors"
      // ...
    private:
      Point(float x, float y);     // Rectangular coordinates
      float x_, y_;
    };
    inline Point::Point(float x, float y)
      : x_(x), y_(y) { }
    inline Point Point::rectangular(float x, float y)
    { return Point(x, y); }
    inline Point Point::polar(float radius, float angle)
    { return Point(radius*std::cos(angle), radius*std::sin(angle));}
    
    int getX() {
	
	 return x_;
	}
	
	 int getY() const {
	
	 return y_;
	}
	
	void setX(int x){
	 x_ = x;
	
	}    
    
    void setY(int y){
	 y_ = y;
	
	}   
};
    
    
    int main(){
    	
    	Point p1=Point::rectangular(2,3);
    	Point p2=Point::polar(2,3);
    	
    	
    	
    	
    	return 0;
    	
    	
    }
