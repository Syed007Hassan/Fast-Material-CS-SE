#include<iostream>
#include<cmath>

using namespace std;
float distance(float x1,float y1,float x2,float y2);
float radius(float x1,float y1,float x2,float y2);
float circumference(double u1);
float area(double u1);

int main(){
	
	float x1,y1,x2,y2,u;
	cout<<"This program will give the\n1-Distance btw the points of circle\n2-The cicle's radius\n3-The cicle's circumference\n4-The cicle's area\n\n";

    cout<<"Enter the centre of circle\n";
    cout<<"Enter the x1 and y1 respectively: ";
    cin>>x1>>y1;
    
     cout<<"Enter the x2 and y2 respectively: ";
     cin>>x2>>y2;
     
     cout<<endl;
     
     cout<<"The distance btw the points are: "<<distance(x1,y1,x2,y2)<<endl<<endl;
     
     cout<<"The radius is equal to distance which is: "<<radius(x1,y1,x2,y2)<<" since a point is centre"<<endl<<endl;
     
     cout<<"The circumference of the circle is: "<<circumference(u)<<endl<<endl;
     
     cout<<"The area of the circle is: "<<area(u)<<endl<<endl;
}

float distance(float x1,float y1,float x2,float y2){
	
	float u1;
	
	u1=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
		
	return u1;
}

float radius(float x1,float y1,float x2,float y2){
	
	
	float u1;
	
	u1=distance(x1,y1,x2,y2);

	return u1;
	
}

float circumference(double u1){
	
	float u3;
	
	
	u3=2*3.142*u1;
	
	return u3;
	
	
}

float area(double u1){
	
	float u3;

	u3=3.142*pow(u1,2);
	
	return u3;
	
}
