#include<iostream>
#include<string>
using namespace std;

class haha{
	
	private:
		int a;
		string b;
		double c;
		
	public:
	
	haha(){       //user defined default constructor
		
		cout<<"Enter the name: ";
		getline(cin,b);
		
		cout<<"Enter the age: ";
		cin>>a;
		
		cout<<"Enter the salary: ";
		cin>>c;
		
		print();
	}
	
	
	print(){
		
	cout<<endl;
	cout<<"Name: "<<b<<endl;
	cout<<"Age: "<<a<<endl;
	cout<<"Salary: "<<c<<endl<<endl;
	
   }
   
   
   
   haha(int p,int q,int r){    //parameterized constructor  
   	
   double x;
   	
		x=(p+q)*r;
		cout<<"The value of x is: "<<x<<endl<<endl;
   	
   	   hehe(x);
   	
   }
   
   int hehe(double x){
   	cout<<"The iterations are as follows: \n";
   	   
   	  for(int i=0;i<5;i++){
   	  	
   	  	   x=x+1;
   	  	   cout<<x<<endl;
		 }
		 cout<<endl;
   }
   
   haha(haha &h1){  //default copy constructor 
   	
   	
   }
   
   haha(const haha &h2){      //parameterized copy constructor
   	
   	
   	
   	
   }
   

   
  ~haha(){   //destructor 
   	
 }
	
	
};

int main(){
	
	haha h1;   //calling of user defined constructor
	 
	
	haha h2(2,5,8);  //calling of paramterized constructor
	
	getchar();
	
	haha h3;  //calling of default copy constructor
	
	haha h4(2,5,8); //calling of parameterized copy constructor
	
//	delete &h1,&h2,h3;   //can also use destructor this way to delete an object
	
	
	
	

}
