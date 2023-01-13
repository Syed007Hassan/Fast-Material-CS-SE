#include <iostream>
using namespace std;

bool isSafe(int sp1, int sp2, int ep1, int ep2);

int tpaths=0;
void paths(int sp1, int sp2, int ep1, int ep2){
	if(sp1==ep1 && sp2== ep2){
		tpaths++;
		return;
	}
	if(isSafe(sp1,sp2,ep1,ep2)){
		paths(sp1, sp2+1, ep1, ep2);
		paths(sp1+1, sp2, ep1, ep2);
	}
}

bool isSafe(int sp1, int sp2, int ep1, int ep2){
	if(sp1 < 0 || sp2 < 0 || sp1 > ep1 || sp2 > ep2)
		return false;
	return true;
}

int main(){
	
	int n,m;
	cin >> n >> m;
//	int tpaths=0;
	paths(0,0,n-1,m-1);
	cout << tpaths << endl;
	
	return 0;
}

//	if(sp2<ep2){
//		paths(sp1, sp2+1, ep1, ep2);
//	}
//	if(sp1<ep1){
//		paths(sp1+1, sp2, ep1, ep2);
//	}
