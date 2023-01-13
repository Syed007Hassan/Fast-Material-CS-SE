#include <iostream>
using namespace std;

int CountPaths(int n){
	static int totalPaths=0;
	
	if(n==0 || n==1)
		return totalPaths+1;
	else if(n==2)
		return totalPaths+2;
	else if(n==3)
		return CountPaths(n-2) + CountPaths(n-1);
	else{
		return CountPaths(n-4) + CountPaths(n-2) + CountPaths(n-1);
	}
}

int main(){
	int n = CountPaths(6);
	cout << n;
	
	return 0;
}
