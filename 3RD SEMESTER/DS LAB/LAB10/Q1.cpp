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
 

};


int main(){

  HashMT a;

 
   a.insert(1,20);
   a.insert(1,22);
  cout<<a.search(1);
  a.Remove(1);
  cout<<a.search(1);
 
 
}
