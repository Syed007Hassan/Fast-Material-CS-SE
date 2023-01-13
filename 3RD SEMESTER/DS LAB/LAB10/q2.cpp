#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
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

  // Hash Functions
 
  int Div(int k){
  return k % Size;
  }
 
 
  int Multi(int k){
	
	double x;
	return floor (Size*modf(k*0.6, &x));
	
	}


/*
	
	int mid_square_hash(int key)
{
int value = key*key;
int middle_value= middle_value(value);
Return middle_value;
}
int Folding_hash(int value1, int value2, int value3)
{
return value1 + value2 + value3;
}
int radix_hash(int value)
{
Int result= base _number(value)
return result;
return last4 digit of result;
}

 */
 
   
 
 // Insertion in Hash table
 
  void insert(int key,int value){
 
  int h = Div(key);
 // int h = Multi(key);
 
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
 
  int h = Div(k);
 
  while(arr[h] != 0 && arr[h]->key != k){
  h = Div(h+1);
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
         int h = Div(k);
         while (arr[h] != NULL) {
            if (arr[h]->key == k)
               break;
            h = Div(h + 1);
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
  cout<<a.search(1)<<endl;
  a.Remove(1);
  cout<<a.search(1);
 
 
}
