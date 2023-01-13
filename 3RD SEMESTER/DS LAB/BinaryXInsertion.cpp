 #include<iostream>
using namespace std;


int binarySearch(int arr[],int s,int e,int x){
	
//	int s =0, e = n;
	
	while(s <=e ){
		
		int mid = (s+e)/2;
		
		if(arr[mid] == x){
		//	cout<<"in the range of "<<s<<"  "<<e<<endl;
			return  mid;
		}
		
		else if(arr[mid] > x){
			e = mid - 1;
		}
		else{
		//	cout<<"here";
			s = mid + 1;
		}
		
	} 
	
	return -1;
	
}
	
	
	
void InsertionSort(int arr[],int n){
 	
 	for(int i=1; i<n; i++){
 		int x = binarySearch(arr,0,i,arr[i]);
 		int current = arr[i];
 		int j = i-1;
 		
 		while(arr[j] > current && j>=x){  //checking previous with the next and moving it to the forward end
 			
 			arr[j+1] = arr[j];
 			j--;  
			 arr[x] = current;               //will become negative 
		 }
		 
		   //the previous location saving current 
 		
	 }
	 
	 for(int i=0;i<n;i++){
	 	cout<<arr[i] <<" ";
	 }
 	
 	
 }
 
 int main(){
	
	int arr[] = {1,2,5,3,7,4,8,10,6,9};
	int n = sizeof(arr)/ sizeof(int);
	
//	cout<<n<<endl;
	InsertionSort(arr,n);


	
}	
