#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;
const int T_S = 200;

class hashTableEntry{
	
	public:
		int k,v;
		
		hashTableEntry(int x,int y){
			
			k = x;
			v = y;
				}
};


class HashTable{
	
	hashTableEntry **arr;
	
	public:
		
		HashTable(){
			
			arr = new hashTableEntry *[T_S];
			
			for(int i = 0; i<T_S;i++){
				arr[i] = NULL;
 			}
 		
		}
		
		
		int HashFunc(int k){
			return k % T_S;
				
		}
	
	   void Insert(int k, int v){
	   	
	   	int h = HashFunc(k);
	   	while(arr[h] != NULL && arr[h]->k != k){
	   		h = HashFunc(h + 1);
		   }
	   	
	   	if(arr[h] != NULL)
	   		delete arr[h];
		   
		   arr[h] = new hashTableEntry(k,v);
	   	
	   }
	 
	   
	   int search(int k){
	   	
	   	int h = HashFunc(k);
	   	
//	   	while(arr[h] != 0 && arr[h]->k != k){
//	   		h = HashFunc(h+1);
//		   }
		   
		   if(arr[h] == 0){
		   	return -1;
		   }
		   else{
		   	return arr[h]->v;
		   }
	   	
	   }
	   
	   
	  int remove(int k){
	   	
	   	int h = HashFunc(k);
	   	
//	   	while(arr[h] != 0){
//	   		
//	   		if(arr[h]->k == k){
//	   			break;
//			   }
//			   else{
//			   	h = HashFunc(h+1);
//			   }
//	   		
//		   }
		   
		   if(arr[h] == 0){
		   	cout<<" No element at key "<<k<<endl;
		   }
		   else{
		   	
		   	delete arr[h];
		   } 	
	   }
	   
	    
};

int main(){
	
	HashTable h;
	
	h.Insert(2,4);
	h.Insert(1,3);

//	cout<<h.search(1)<<endl;
	cout<<h.search(2)<<endl;
	
	
   h.remove(2);
   
   	cout<<h.search(1)<<endl;
	
	
}
