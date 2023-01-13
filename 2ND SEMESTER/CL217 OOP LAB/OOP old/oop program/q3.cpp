#include <iostream>
using namespace std;
class shape
{
	protected:
		float area;
	public:
		virtual float RectangleArea(int l, int w)=0;
		virtual float SquareArea(int s)=0;
		virtual float CircleArea(int r)=0;
		float getarea()
		{
			return area;
		}
};

class Area: public shape
{
	public:
		float SquareArea(int s)
		{
			area=s*s;
			return getarea();
		}
			float RectangleArea(int l, int w)
		{
			area=l*w;
			return getarea();
		}
			float CircleArea(int r)
		{
			area=3.142*r*r;
			return getarea();
		}
};

int main()
{
	int l,w,r,side;
	cout<<"Enter the length and width of rectangle:  "<<endl;
	cin>>l>>w;
	Area r1;
	cout<<"Area of rectangle is "<<r1.RectangleArea(l,w)<<endl<<endl;
	cout<<"Enter the side of square: "<<endl;
	cin>>side;
	Area s1;
	cout<<"The area of square is: "<<s1.SquareArea(side)<<endl<<endl;
	cout<<"enter the radius of the circle: "<<endl;
	cin>>r;
	Area c;
	cout<<"The area of circle is: "<<c.CircleArea(r);
}
