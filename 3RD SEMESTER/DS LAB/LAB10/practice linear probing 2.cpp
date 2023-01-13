#include<iostream>
#include<math.h>
using namespace std;

const int TS = 200;
float A = 0.618033;

class HTE{
	
	public:
		
		int k , v;
		
		HTE(int x , int y){
			k = x;
			v = y;
		}
};


class HTM{
	
	HTE **arr;
	
	public:
		
		HTM(){
			
			arr = new HTE *[TS];
			
			for(int i = 0; i< TS;i++){
				arr[i] = 0;
			}
			
		}
		
		int HashFunc(int k){
			return k % TS;
		}
		
//		int HashFunc(int v){
//			
//			return floor(1000 * fmod((A*v),1));
//		}
		
		
		void insert(int key,int val){
			
			int h = HashFunc(key);
			
			while(arr[h]  != 0 && arr[h]->k != key){
				h = HashFunc(h + 1);
			}
			
			if(arr[h] != 0){
				delete arr[h];
			}
			
			arr[h] = new HTE(key , val);
		
		}
		
		int search(int key){
			
			int h = HashFunc(key);
			
			while(arr[h]  != 0 && arr[h]->k != key){
				h = HashFunc(h + 1);
			}
			
			if(arr[h] == 0){
				return -1;
			}
			else{
				return arr[h]->v;
			}
		}
		
	  int remove(int key){
	  	
	  	int h = HashFunc(key);
	  	
	  	while(arr[h] != 0){
	  		
	  		if(arr[h]->k == key){
	  			break;
			  }
			  else{
			  	h = HashFunc(h+1);
		   }
		  }
		  
		  if(arr[h] == 0){
		  	cout<<"no key found "<<endl;
		  }
		  else{
		  	delete arr[h];
		  }
	  	
	  }	

};

int main(){
	
	
	HTM h;
	h.insert(1,4);
	h.insert(1,6);
	h.insert(3,5);
	
	cout<<h.search(1)<<endl;
	h.remove(1);
	cout<<h.search(1)<<endl;
	
	
	
	
	
}
