#include <bits/stdc++.h>
using namespace std;


//BINARY SEARCH

int binarySearch(int arr[],int s,int e,int x){
	
//	int s =0, e = n;
	
	while(s <=e ){
		
		int mid = (s+e)/2;
		
		if(arr[mid] == x){
			cout<<"in the range of "<<s<<"  "<<e<<endl;
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

// Exponential search using binary Searching 

int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at first location itself
//    if (arr[0] == x)
//        return 1;
// 
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x){
	
        i = i*2;
 
    //  Call binary search for the found range.
    return binarySearch(arr, i/2,
                            min(i, n-1), x);
j
   }
}

//INTERPOLATION SEARCH

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
 
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
 
        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
 
        // Condition of target found
        
        if (arr[pos] == x){
		
         // cout<<"now "<<endl;
            return pos;
        } 
        // If x is larger, x is in right sub array
        if (arr[pos] < x){
		
            return interpolationSearch(arr, pos + 1, hi, x);
			}
        // If x is smaller, x is in left sub array
        if (arr[pos] > x){
		
            return interpolationSearch(arr, lo, pos - 1, x);
			
		   }
    }
    return -1;
}


//JUMP SEARCH

int jumpSearch(int arr[], int x, int n)
{
    // Finding block size to be jumped
    int step = sqrt(n);
 
    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
 
    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x)
    {
        prev++;
 
        // If we reached next block or end of
        // array, element is not present.
        if (prev == min(step, n))
            return -1;
    }
    // If element is found
    if (arr[prev] == x)
        return prev;
 
    return -1;
}


int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l) {
 
        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
 
        // Check if key is present at any mid
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }
 
        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region
        if (key < ar[mid1]) {
 
            // The key lies in between l and mid1
            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {
 
            // The key lies in between mid2 and r
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else {
 
            // The key lies in between mid1 and mid2
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }
 
    // Key not found
    return -1;
}
 
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(int);
    int result;
    
	// result = binarySearch(arr,0,n,x);
    
    //  result = exponentialSearch(arr,n,x);
    
   // result = jumpSearch(arr,x,n);
    
    result = interpolationSearch(arr,0,n-1,x);
    
    
	cout<<result<<endl; 
    return 0;
}
