#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<math.h>
//Chaining 
using namespace std;
const int T_S = 200;


class Node{
	
	public:
		int k,v;
		Node *next;
		
		
		Node(int x,int y){
			k = x;
			v = y;
			next = 0;   }
			
			
};


class HashMap{
	
	Node **arr;
	
	public:
		
		HashMaP(){
			for(int i = 0 ;i < T_S; i++){
				arr[i] = 0;
			}
		}
		
		HashFunc(int k){
			return k % T_S;
		}
		
		//Insert using chaining 
		
		void insert(int key , int value){
		int h = HashFunc(key);
		
		Node *prev = 0;
		Node *entry = arr[h];
		
		while(entry != 0){    // if entry already existed
			
			prev = entry;
			entry = entry->next;
		}
		
		if(entry == 0){       //if entry was null
			
			entry = new Node(key,value);
			
			if(prev == 0){      //if prev was also null make entry 
				arr[h] = entry; 
			}
			
			else{
				prev->next = entry;    //connect entry to next of previos
			}
		}
		else{
			entry->v = value;      //if entry not null assign value to entry;
			
		}
			
		}
		
 
		
		//Removing in the Hash map
		
		int remove(int key){
			
			int h = HashFunc(key);
			
			Node *prev = 0;
			Node *entry = arr[h];
			
			if(entry  == 0 || entry->k != key ){
				cout<<"No KEY EXISTED "<<endl;
				return -1;
			}
			
			while(entry->next != 0){
				prev = entry;
				entry = entry->next;
			}
			
			if(prev != 0){
				
				prev->next = entry->next;
			}
			
			delete entry;
			
			cout<<"Element has been deleted "<<endl;
			
		}
		
		
		//Search for an element in the Hashh map
		
		int search(int key){
			cout<<"ds";
			bool flag = 0;
			int h = HashFunc(key);
			Node *entry = arr[h];
			
			while(entry != 0){
				if(entry->k == key){
					cout<<"value found "<<entry->v<<endl;
					flag  = 1;
				}
				entry  = entry->next;
				
			}
			
				if(!flag){
					return -1;
				}
		}
		
	
	
};

int main(){
	
	HashMap h1;
	
	h1.insert(5,4);
	
	//h1.remove(4);
	
	h1.search(4);

	
	
}
