#include<iostream>
using namespace std;

class MaxHeap {
	int *harr; 
	int capacity; 
	int heap_size; 
	public:
		
		MaxHeap(int cap)
		{
			heap_size = 0;
			capacity = cap;
			harr = new int[cap];
		}
		
		//Converting Binary tree into min heap
		
		void heapify(int i) {
			int size=heap_size;
			int largest =i;
	
			int l=2*i+1;
			int r=2*i+2;
	
			if(l<size && harr[l]>harr[largest]) {
				largest =l;
			}
			if(r<size && harr[r]>harr[largest]) {
				largest =r;
			}
	
			if(largest !=i) {
				swap(harr[i],harr[largest]);
				heapify(largest);
			}
		}
		
		//Inserting elements in heap
		
		void insert(int val) {
			if(heap_size==capacity) {
				cout << "Heap is full.";
				return;
			}
			
			harr[heap_size++]=val;
			
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
		
		
		void parent(int i){
			cout<<"Parent of index "<<i<<" would be: "<<(i-1)/2<<endl;
		}
		
		void left_child(int i) {
			cout << "Left child of index "<<i<<" would be: "<<2*i+1<<endl;
		}
		
		void right_child(int i) {
			cout <<"Right child of index "<<i<<" would be: "<< 2*i+2<<endl<<endl;
		}
		
		// MERGING HEAPS
		
		void Merge_Heaps(MaxHeap &h, MaxHeap &h1){
	
			for(int i=0;i<h.heap_size;i++){
				insert(h.harr[i]);
			}
			
			for(int i=0; i< h1.heap_size ;i++){
			    insert(h1.harr[i]);
			}
			
			print();
		}
		
		
		
};

int main() {
    
	MaxHeap h(5);
	h.insert(10);
	h.insert(5);
    h.insert(6);
    h.insert(2);
    cout<<"HEAP 1: "<<endl;
    h.print();
	
	MaxHeap h1(5);
	h1.insert(12);
	h1.insert(7);
	h1.insert(9);
	cout<<"HEAP 2: "<<endl;
	h1.print();
	
	MaxHeap h2(10);
	
	cout<<"HEAP 1 and 2 combined: "<<endl;
	h2.Merge_Heaps(h,h1);
	
	
		MaxHeap h3(15);
	h3.insert(2);
	h3.insert(120);
	h3.insert(77);
	h3.insert(150);
	h3.insert(6);
	h3.insert(80);
	h3.insert(5);
	h3.insert(4);
	h3.insert(15);
	h3.insert(45);
	h3.insert(3);
	
	h3.print();
}
