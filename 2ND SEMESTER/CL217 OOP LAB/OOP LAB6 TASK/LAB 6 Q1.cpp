#include<iostream>
using namespace std;

class Circle{
	
	private:
		
		int radius;
		
	public:
	
	   static int count;
	   
	   Circle(int r){
	   	
	   	  radius=r;
	   	  
	          cout<<"The object no that is created: "<<++count<<endl;  	  
	 		 cout<<"The area is: "<<getarea()<<endl<<endl;
			
			 			 
	   }
	   
	   getarea(){
	   	  	
	   	  	float arr;
	   	  	
	   	  	arr=3.142*radius*radius;
	   	  	
	   	  	return arr;
			 }		 
};

int Circle::count=0;


int main(){
	
	int r[3];

for(int i=1;i<=3;i++){
	cout<<"Enter the radius: "<<i<<" ";
	cin>>r[i];
	
	cout<<endl;
}
	
		Circle c1[3]={Circle(r[1]),Circle(r[2]),Circle(r[3])};
		
}
