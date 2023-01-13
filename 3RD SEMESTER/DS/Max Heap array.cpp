#include<iostream>
#include<climits>
using namespace std;

class MinHeap {
	int *harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
	public:
		MinHeap(int cap)
		{
			heap_size = 0;
			capacity = cap;
			harr = new int[cap];
		}
		
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
		
		void merge(MinHeap &h, MinHeap &h1){
			
			int n = h1.heap_size + h.heap_size;
			
		//	int arr[n];
			
			for(int i=0;i<h.heap_size;i++){
				harr[i] = h.harr[i];
				
			//	cout<<harr[i]<<" ";
			} 
			
			for(int i=h.heap_size;i<heap_size;i++){
				harr[i] = h.harr[i];
				
				cout<<harr[i]<<" ";
			} 
			
//			   for(int j = 0, i=h.heap_size; j < h1.heap_size && i< heap_size ; i++, j++){
//			   	cout<<i<<" ";
//			   	harr[i] = h1.harr[j];
//			  // 	 cout<<harr[j]<<" ";
//			   }
			   
//			   	for(int i=0;i<heap_size;i++) {
//				cout << harr[i] << " ";
//			}
			   
//		for(int i=n/2-1; i>=0;i--)
//			{
//				heapify(i);
//			}	   
//			 
			
		}		
		
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
		
		void peek() {
			cout << harr[0];
		}
		
		void print() {
			for(int i=0;i<heap_size;i++) {
				cout << harr[i] << " ";
			}
		}
		
		void left_child(int i) {
			cout << 2*i+1;
		}
		
		void right_child(int i) {
			cout << 2*i+2;
		}
};

int main() {
	MinHeap h(5);
	
	h.insert(5);
	h.insert(2);
	h.insert(7);
	h.insert(6);
	h.insert(3);
	
//	h.print();

//	h.print();
	
	
	MinHeap h1(5),h2(11);
	h1.insert(8);
	h1.insert(9);
	h1.insert(11);
	h1.insert(1);
	h1.insert(4);
	
//	h1.print();
	
	h2.merge(h,h1);
	
	h2.print();
}
