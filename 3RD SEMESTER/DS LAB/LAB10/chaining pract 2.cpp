#include<iostream>
#include<math.h>
using namespace std;

const int TS = 200;

class Node{
	
	public:
		
		int k , v;
		Node *next;
		
		Node(int x , int y){
			k = x;
			v = y;
			next  = 0;
		}
};


class HashMap{
	
	Node **arr;
	
	public:
		
		HashMAp(){
			
			arr = new Node *[TS];
			
			for(int i = 0;i<TS;i++){
				arr[i] = 0;
			}
		}
		
		int HashFunc(int k){
			return k % TS;
		}
		
		int insert(int key, int val){
			
			int h = HashFunc(key);
		
			Node *entry = arr[h];		
			Node *prev = NULL;
					
			while(entry != 0 ){
				prev = entry;
				entry = entry->next;
			}
			
			if(entry == 0){
	
				entry = new Node(key,val);
				
				if(prev == 0){
					arr[h] = entry;
				}
				else{
					prev->next = entry;
				}	
			}
			
			else{
				entry->v = val;
			}
		}
		
		
		int search(int key){
			int h = HashFunc(key);
			
			Node *entry = arr[h];
	
		    while(entry !=0 ){
		    	
		    	if(entry->k == key){
		    		cout<<entry->v;
		    		break;
				}
				else{
					entry = entry->next;
				}
		    	
			}
		
		    return -1;	
		}
		
		
		int remove(int key){
			
			int h = HashFunc(key);
			
			Node *entry = arr[h];
			Node *prev =0;
			
			if(entry == 0 || entry->k != key){
				cout<<"No element found at that key "<<endl;
			}
			
			while(entry != 0){
				prev = entry;
				entry = entry->next;
			}
			
			if(prev != 0){
				
				prev->next = entry->next;
			}
			
			delete entry;
			
			cout<<"Element has been deletd "<<endl;
			
		
		}
		
	
	
};

int main(){
	
	
	
	HashMap h;
	
	h.insert(1,3);
	//h.insert(2,4);
	
	cout<<h.search(1)<<endl;
	
	
}

