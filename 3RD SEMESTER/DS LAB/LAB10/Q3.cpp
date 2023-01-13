#include<iostream>
using namespace std;

const int Size = 200;

class HashTE{

  public:
  int key;
  int value;

   HashTE(int k,int v){
   key = k;
   value = v;
   
   }

};


class HashMT{

  private:
  HashTE **arr;

  public:

  HashMT(){
  arr = new HashTE *[Size];
  for(int i = 0; i<Size; i++){
  arr[i] = 0;
  }
  }

  // Hash Function
 
  int HashF(int k){
  return k % Size;
  }
 

 // Insertion in Hash table
 
  void insert(int key,int value){
 
  int h = HashF(key);
 
  while(arr[h] != NULL && arr[h]->key != key){
  h = HashF(h+1);
 }
 
  if (arr[h] != NULL){
 
      delete arr[h];
  }
      arr[h] = new HashTE(key, value);
     

 }
 
  // Searching data in Hash Table
 
  int search(int k){
 
  int h = HashF(k);
 
  while(arr[h] != 0 && arr[h]->key != k){
  h = HashF(h+1);
  }
 
 
  if(arr[h] == 0){
 
  return -1;
  }
  else{
  return arr[h]->value;
  }
 
  }
 
  //Removing the Value with key
 
     void Remove(int k) {
         int h = HashF(k);
         while (arr[h] != NULL) {
            if (arr[h]->key == k)
               break;
            h = HashF(h + 1);
         }
         if (arr[h] == NULL) {
            cout<<"No Element found at key "<<k<<endl;
            return;
         } else {
            delete arr[h];
         }
         cout<<"Element Deleted"<<endl;
      }
      
      
      
    //Checking if Hash table is empty
    
	bool isEmpty(){
		
		for(int i=0;i<Size;i++){
			if(arr[i] != NULL)
				return false;
		
		}
			
			return true;

	}
	
		
		int book_SIZE(){
			return Size;
		}
		
 

};


int main(){

  HashMT CN;
  
   if(CN.isEmpty()){
   	cout<<"Contact book is empty "<<endl;
   }
   else{
   	cout<<"Contact book is not empty "<<endl;
   }
   
   cout<<"SIZE OF CONTACT BOOK IS: "<<CN.book_SIZE()<<endl;
   
   CN.insert(1052,23353);
   CN.insert(1044,32423);
   
   cout<<CN.search(1044)<<endl; 
    cout<<CN.search(1052)<<endl; 
    
  //  CN.Remove(1052);
      
   
    if(CN.isEmpty()){
   	cout<<"Contact book is empty "<<endl;
   }
   else{
   	cout<<"Contact book is not empty "<<endl;
   }
   
    
    
    

 
 
 
}
