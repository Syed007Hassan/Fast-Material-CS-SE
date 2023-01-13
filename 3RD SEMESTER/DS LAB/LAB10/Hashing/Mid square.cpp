#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<math.h>
using namespace std;
const int T_S = 1000;
class HashTableEntry {
   public:
      int k;
      int v;
      HashTableEntry(int k, int v) {
         this->k= k;
         this->v = v;
      }
};
class HashMapTable {
   private:
      HashTableEntry **t;
   public:
      HashMapTable() {
         t = new HashTableEntry * [T_S];
         for (int i = 0; i< T_S; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(int a) {
      	
   		long int x=a*a;
	
		   		cout <<x;
				if(x>99 && x <1000){
				cout <<"Key against the value is "<<(x / 10) % 10<<endl;
				return (x / 10) % 10 ;
			
				}
				
			else 	if(x>999 && x <100000){
					cout <<"Key against the value is "<<(x / 10) % 100 <<endl;
				return  (x / 10) % 100 ;
				
				}
				
			else	if(x>9999 && x <100000){
				cout <<"Key against the value is "<<(x / 10) % 100<<endl;
				return (x / 10) % 1000 ;
		
				}
      
      }
      void Insert(int k, int v) {
         int h = HashFunc(v);
   
      	    if (t[h] != NULL)
            delete t[h];
          
         t[h] = new HashTableEntry(h, v);
      }
      int SearchKey(int k) {
     
         if (t[k] == NULL)
            return -1;
         else
            return t[k]->v;
      }
      void Remove(int k) {
        
         if (t[k] == NULL) {
            cout<<"No Element found at key "<<k<<endl;
            return;
         } else {
            delete t[k];
         }
         cout<<"Element Deleted"<<endl;
      }
      ~HashMapTable() {
         for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
               delete t[i];
               delete[] t;
         }
      }
};
int main() {
   HashMapTable hash;
   int k, v;
   int c;
   while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter element to be inserted: Range 10 - 316  to work properly (due to index issue  )";
            cin>>v;
            hash.Insert(k, v);
         break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            if (hash.SearchKey(k) == -1) {
               cout<<"No element found at key "<<k<<endl;
               continue;
            } else {
               cout<<"Element at key "<<k<<" : ";
               cout<<hash.SearchKey(k)<<endl;
            }
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>k;
            hash.Remove(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
   }
   return 0;
}
