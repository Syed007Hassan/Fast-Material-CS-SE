#include<iostream>
using namespace std;

class MinHeap {
	int *harr; 
	int capacity; 
	int heap_size; 
	public:
		
		MinHeap(int cap)
		{
			heap_size = 0;
			capacity = cap;
			harr = new int[cap];
		}
		
		//Converting Binary tree into min heap
		
		void heapify(int i) {
			int size=heap_size;
			int smallest =i;
	
			int l=2*i+1;
			int r=2*i+2;
	
			if(l<size && harr[l]<harr[smallest]) {
				smallest =l;
			}
			if(r<size && harr[r]<harr[smallest]) {
				smallest =r;
			}
	
			if(smallest !=i) {
				swap(harr[i],harr[smallest]);
				heapify(smallest);
			}
		}
		
		//Inserting elements in heap
		
		void insert(int val) {
			if(heap_size==capacity) {
				cout << "Heap is full.";
				return;
			}
			
			harr[heap_size++]=val;   //inserting value in heap and then heapify           
			
			for(int i=heap_size/2-1; i>=0;i--)
			{
				heapify(i);
			}
		}
		
		//Deleting elements in heap
		
		void dequeue(int val) {
			int i;
			for(i=0;i<heap_size;i++) {
				if(val == harr[i]) {
					break;
				}
			}
			
			swap(harr[i],harr[heap_size-1]);
			heap_size--;
			
			for(int i=heap_size/2-1; i>=0;i--)
			{
				heapify(i);
			}
			
		}
	
	//GET max or min element if it's a max or min heap respectively 
		
		void peek() {
			cout << harr[0];
		}
		
		void print() {
			for(int i=0;i<heap_size;i++) {
				cout << harr[i] << " ";
			}
			cout<<endl<<endl;
		}
		
		void print(int x){
			cout<<"All the elements lesser than "<<x<<" in heap are: "<<endl;
			for(int i=0;i<heap_size;i++){
				if(harr[i] < x){
					cout<<harr[i]<<" ";
				}
			}
				cout<<endl;
		}
		
		void parent(int i){
			cout<<"Parent of index "<<i<<" would be: "<<(i-1)/2<<endl;
		}
		
		void left_child(int i) {
			cout << "Left child of index "<<i<<" would be: "<<2*i+1<<endl;
		}
		
		void right_child(int i) {
			cout <<"Right child of index "<<i<<" would be: "<< 2*i+2<<endl<<endl;
		}
};

int main() {
	MinHeap h(10);
	
	h.insert(5);
	h.insert(2);
	h.insert(7);
	h.insert(6);
	h.insert(3);
	h.insert(8);
	h.print();
	h.dequeue(6);
	h.dequeue(3);
	cout << endl;
	h.print();
	
	h.parent(1);
	h.left_child(0);
	h.right_child(0);
	
	
	MinHeap h1(15);
	h1.insert(2);
	h1.insert(120);
	h1.insert(77);
	h1.insert(150);
	h1.insert(6);
	h1.insert(80);
	h1.insert(5);
	h1.insert(4);
	h1.insert(15);
	h1.insert(45);
	h1.insert(3);

    h1.print();
	
//	h1.print(15);
//	
//	h1.print(80);
//	
}
