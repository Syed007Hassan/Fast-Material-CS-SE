#include<iostream>
using namespace std;
#define n 3
bool d=false; bool x =false; bool y=false;  

class Node{
	
	public:
		int data;
		Node *left;
		Node *right;
	    
	Node(int val){
		data = val;
		left = right = 0;
	
	}
	
};

class GameTrees{

     public: 
    
     int c1, c2,k;
      int bd[n][n];
    
   GameTrees(){
   	c1 = c2 = k = 0;
   	
   	for(int i=0;i<n;i++)
	{ for(int j=0;j<n;j++){ cin>>bd[i][j]; }
	}
	
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(bd[i][j]==1)
			  c1++;
			if(bd[i][j]==2)
			  c2++;
		}
	}
		
   }
    
    bool second_p(int bd[n][n]) {
		if(bd[0][0]==2 && bd[0][1]==1 && bd[0][2]==1 && 
		bd[1][0]==0 && bd[1][1]==2 && bd[1][2]==1 && 
		bd[2][0]==0 && bd[2][1]==0 && bd[2][2]==0) { return true; }
		return false;
    }

    bool diagonal_c(int bd[n][n]) {
		if(bd[0][0]==2 && bd[0][1]==0 && bd[0][2]==0 && 
		bd[1][0]==0 && bd[1][1]==1 && bd[1][2]==0 && 
		bd[2][0]==0 && bd[2][1]==0 && bd[2][2]==1) { return true;}
		return false;
    }

    bool Check(int t1, int t2){
	if(t1>t2||t2>t1){ cout<<"-1\n"; return 0;}
    }

    bool GT_BT(int bd[n][n]){
	if(bd[1][1]==1)
	{
		if(bd[0][1]==2 || bd[1][0]==2||bd[2][1]==2||bd[1][2]==2){	x=true; return true; } else if(bd[0][0]==2 || bd[0][2]==2||bd[2][0]==2||bd[2][2]==2) { d=true; }
		else{ 	d=false; }
	}
	else if(bd[2][1]==1){
		if(bd[0][0]==2 || bd[1][0]==2||bd[0][2]==2||bd[1][2]==2){	x=true; return true; } 	else if(bd[0][1]==2 || bd[1][1]==2||bd[2][2]==2||bd[2][2]==2) { d=true; }
		else{ d=false; } 
		}
	else if(bd[1][2]==1)
	{
		if(bd[0][0]==2 || bd[2][0]==2||bd[0][1]==2||bd[2][1]==2){ 	x=true; return true; } 	else if(bd[0][2]==2 || bd[2][2]==2||bd[1][1]==2||bd[1][0]==2){	d=true; }
		else{ d=false; } }
	else if(bd[0][1]==1)
	{
		if(bd[1][0]==2 || bd[2][0]==2||bd[1][2]==2||bd[2][2]==2) { 	x=true; return true;} else if(bd[0][0]==2 || bd[0][2]==2||bd[1][1]==2||bd[2][1]==2) { d=true; }
		else{ d=false; 	}
	}
	else if(bd[1][0]==1)
	{
		if(bd[0][1]==2 || bd[0][2]==2||bd[2][1]==2||bd[2][2]==2){ x=true; return true; } else if(bd[0][0]==2 || bd[2][0]==2||bd[1][1]==2||bd[1][2]==2) { d=true; }
		else{ d=false; 	}
	}
	else if(bd[2][0]==1||bd[0][0]==1||bd[0][2]==1||bd[2][2]==1)
	{
		if(bd[1][1]==0 ||bd[1][1]==1){ 	x=true; return true; } else{ d=true; }
	}
	else{ return false; }
    }

    bool endd(int bd[n][n]){
	for(int q=0;q<3;q++)
	{
		if(bd[0][q]==bd[1][q]&& bd[1][q] ==bd[2][q] && bd[0][q]!= 0){
			if(bd[0][q]==1){	x=true; }
			else{ y=true; }
			return true; }
	}
	for(int q=0;q<3;q++)
	{
		if(bd[q][0]==bd[q][1]&& bd[q][1] ==bd[q][2] && bd[q][0]!= 0){
			if(bd[q][0]==1){ x=true; }
			else{ y=true; }
			return true; }
	}
	if(bd[0][0]==bd[1][1]&& bd[1][1] ==bd[2][2] && bd[0][0]!= 0)
	{
		if(bd[0][0]==1) { x=true; }
			else{ y=true; }
		return true;
	}
	if(bd[0][2]==bd[1][1]&& bd[1][1] ==bd[2][2] && bd[0][2]!= 0)
	{ if(bd[2][2]==1){ x=true; }
			else{ y=true; } return true;
	}
	else{   x=false; y=false; d=true;
		return false; }
	}


};
int main()
{
    GameTrees gt;
	
	if(gt.second_p(gt.bd)) { cout << "2"; return 0; }
	
	if(gt.diagonal_c(gt.bd)) { cout << "0"; return 0; }                                                         
	
	if(gt.Check(gt.c1,gt.c2))
	{
		if(gt.endd(gt.bd))
		{
			if(x){ cout<<"1"<<endl; }
			else if(d){ cout << "0" << endl; }
			else if(y){ cout<<"2"<<endl; }
			else{ cout<<"-1\n"; }
		}
	    else
		{
	    	if(gt.GT_BT(gt.bd)==true){ cout<<"1";}
			else{ cout<<"2"; }
		}
	}
}
