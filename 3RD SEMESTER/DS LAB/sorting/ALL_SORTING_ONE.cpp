 #include<iostream>
using namespace std;

void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}


// INSERTION SORT
 void InsertionSort(int arr[],int n){
 	
 	for(int i=1; i<n; i++){
 		
 		int current = arr[i];
 		int j = i-1;
 		
 		while(arr[j] > current && j>=0){  //checking previous with the next and moving it to the forward end
 			
 			arr[j+1] = arr[j];
 			j--;                 //will become negative 
		 }
		 
		 arr[j+1] = current;  //the previous location saving current 
 		
	 }
	 
	 for(int i=0;i<n;i++){
	 	cout<<arr[i] <<" ";
	 }
 	
 	
 }
 
 
 
  // SELECTION SORT
  
  void Selection_Sort(int A[],int n){
  	
	  int i,j,k;

     for(i=0;i<n-1;i++){      //In each pass we get the smallest element at the top of the list 
     	for(j=k=i;j<n;j++){   //i,j,k points to the same location at the beginning 
     		                  //i stays there then j moves further and k legs behind 
			 if(A[j]<A[k])    
			 k=j;
			 
			 }
			 swap(&A[i],&A[k]);
			 }
			 
}
  

//  BUBBLE SORT
 
void Bubble_Sort(int data[],int n){
	
	bool again = true;

     for(int i = 0; i < n ; i++) {
     	int flag =0;
     
	  for(int j=0 ;j < n-1-i; j++){
	      
	   if ( data [ j ] > data [ j+1]) {

       swap ( data[ j ], data [ j+1 ] );
                   flag = 1;
         }
 
      }

       if(flag == 0){
      	break;
         
	 }
 
 } 
 
   for(int x = 0;x<n;x++){
		
		cout<<data[x]<<" ";
	}

}

void print(int arr[],int n){
		 
	 for(int i=0;i<n;i++){
	 	cout<<arr[i] <<" ";
	 }
 	
	
}



// QUICK SORT

int partition(int A[],int l,int h){
	
   int pivot=A[l];
   int i=l,j=h;

   do{
   	
   do{i++;}while(A[i]<=pivot);  //moving the pivot to almost centre by incrementing i
                                //and decrementing j
   do{j--;}while(A[j]>pivot);

   if(i<j){
    swap(&A[i],&A[j]);
 }
   } 
     while(i<j);
  
    swap(&A[l],&A[j]);

    return j;
}


void Quick_Sort(int arr[],int l,int h){
	
	int j;
	if(l < h){
		
	
	j = partition(arr,l,h);
	
	Quick_Sort(arr,l,j);
	Quick_Sort(arr,j+1,h);
		
		
	}
			
}

// SHELL SORT

void Shell_Sort(int arr[],int n){
	
	int gap,temp,i,j;
	
	for(gap=n/2;gap>=1;gap=gap/2){
		
		for(i = gap; i<n ;i++){
		
			
			temp = arr[i];
			j = i-gap;
		
		
		while(j >=0 && arr[j] > temp){
			
			arr[j+gap] = arr[j];
			j = j-gap;
		}
		
		arr[j+gap] = temp;
		
		
     }
     
     for(int i=0;i<n;i++){
	 	cout<<arr[i] <<" ";
	 }
     cout<<endl<<endl;
	}

	
 		
}

// MERGE SORT 

void Merge(int arr[],int l,int mid,int h){
	
	int i = l, j = mid+1, k = l;
	int B[100];
	
	while(i<=mid && j<=h){
		
		if(arr[i]<arr[j]){
			B[k++] = arr[i++];
		}
		else{
			B[k++] = arr[j++];
		}
	}
	
	
	for(;i<=mid;i++){
		B[k++] = arr[i];
	}
	
	for(;j<=h;j++){
		B[k++] = arr[j];
	}
	
	
	for(i=l;i<=h;i++){
		arr[i] = B[i];
	}
	
	
	
	
}


void Merge_Sort(int arr[],int n){
	
	int p,l,h,mid;
	
	for(p=2;p<=n;p=p*2){     //taking the pair of two elements and once and merging them into a list
	                         //2 becomes 4 and then so on
		for(int i=0; i+p-1<=n; i=i+p){
			
			l = i;             
			h = i+p-1;
			mid = (l+h)/2;
			Merge(arr,l,mid,h);     //merging those list of elements
		}
		
			
	}
	
	if(p/2 < n){     //for odd elements
		Merge(arr,0,p/2,n);
	}
	
	for(int i=0;i<n;i++){
	 	cout<<arr[i] <<" ";
	 }
	 
	 cout<<endl<<endl;	 
	
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] < arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] < arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}



int main(){
	
	int arr[] = {1,2,5,3,7,4,8,10,6,9};
	int n = sizeof(arr)/ sizeof(int);
	
//	cout<<n<<endl;
//	InsertionSort(arr,n);

//  Selection_Sort(arr,n);
//  print(arr,n);

//    Bubble_Sort(arr,n);

//   Quick_Sort(arr,0,n);
//	print(arr,n); 

 //   Shell_Sort(arr,n);
    
    
 //   Merge_Sort(arr,n);

 heapSort(arr,n);	
}
