#include<iostream>

using namespace std;


class DynamicSafeArray{
	
	  private:
	  	int *Data;
	  	unsigned int size;
	  	
	  	
	 public:
	 	DynamicSafeArray():Data(0),size(0){}
		 	 	
	 	DynamicSafeArray(int n){
	 		this->size=n;
	 		this->Data= new int[size];
	 	}
	   ~DynamicSafeArray(){
	   	
	   	 if (Data != 0)
	   	 {
	   	 	delete [] Data;
	   	 }
	   	 Data=0;
	      	
	   }
	   
	   unsigned int getSize(){ 
	   return size;
	   }
	   
	 int& Operator[](int i){
	 	
	 	return (Data[i]);
	 	
	 }
	
	
	
};

int main()
{
  DynamicSafeArray   DSA= new DynamicSafeArray(10);
  
  for(int i=0; i< 10; i++)
  {
  
    cout << DSA[i] << endl;  }
  
  
  
  


return 0;
}
