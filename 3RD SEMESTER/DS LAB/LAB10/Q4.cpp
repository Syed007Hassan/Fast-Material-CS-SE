#include<iostream>
using namespace std;

const int Size = 200;

class HashTE{

  public:
  int key;
  int value;
  HashTE *next;

   HashTE(int k,int v){
   key = k;
   value = v;
   next = 0;
   
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
 
              HashTE *prev = 0;
              HashTE *current = arr[h];
  
            while (current != 0)
            {
                prev = current;
                current = current->next;
            }
            if (current == 0)
            {
                current = new HashTE(key, value);
                if (prev == NULL){
                    arr[h] = current;
					}
	        else
	        {
                    prev->next = current;
                }
            }
            else
            {
                current->value = value;
            }

 }
 
  // Searching data in Hash Table
 
  int search(int key)
        {
            bool flag = false;
            int h = HashF(key);
            HashTE* current = arr[h];
            while (current != NULL)
	    {
                if (current->key == key)
	        {
                    cout<<current->value<<" ";
                    flag = true;
                }
                current = current->next;
            }
            if (!flag)
                return -1;
        }
 
  //Removing the Value with key
 
     void remove(int key)
        {
            int h = HashF(key);
            HashTE* current = arr[h];
            HashTE* prev = NULL;
            if (current == NULL || current->key != key)
            {
            	cout<<"No Element found at key "<<key<<endl;
                return;
            }
            while (current->next != NULL)
	    {
                prev = current;
                current = current->next;
            }
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            delete current;
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
