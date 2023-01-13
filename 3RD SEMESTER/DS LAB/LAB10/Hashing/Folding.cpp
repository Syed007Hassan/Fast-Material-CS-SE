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
      double v;
      HashTableEntry(int k, double v) {
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
      int HashFunc(int k) {
      		cout <<"Key against the value is " <<k % 150<<endl;
         return k % 150;
      }
      void Insert(int k, double v) {
     
         int h = HashFunc(k);
      	    if (t[h] != NULL)
            delete t[h];
        
         t[h] = new HashTableEntry(h, v);
         
      }
      double SearchKey(int k) {
     
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
   double value;
   int c;
   int y,z,y1,z1;
   while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter 12 digit element to be inserted: e.g 123456789012";
            cin>>value;
				y = value/100000000;
			    z = fmod(value,100000000);   
			    y1 = z/10000;
			    z1 = fmod(value,10000);
			  // cout<<y<<endl<<y1<<endl<<z1<<endl;   dividing in to 4 digit chunks
			    k=y+y1+z1;            
            hash.Insert(k, value);
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
