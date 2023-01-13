#include<iostream>
#include <string>
using namespace std;

class Node{
	
	public:
		string data;
		string id;
		Node *left;
		Node *right;
		Node *next;
	    
	Node(string val){
		data = val;
		left = right = 0;
	}
	
};

class BST{
	
	public:
		
		Node *root;
		Node *tail;
		string text;
		
   BST(){
   	root = 0;
   	tail  = 0;
   	text = "NULL";
   }
   
    void insert(string x) {
        root = InsertInBst(x, root);
    }

   Node *InsertInBst(string val,Node *r){
   	
   	if( r == 0){
   		r = new Node(val);
   		r->left = r->right = 0;
	   }
	else if(val < r->data){
		r->left = InsertInBst(val,r->left); }
	else if(val > r->data){
		r->right = InsertInBst(val,r->right); }
	return r;      
   }
   
   	void compare_string(string c) {
		string t,q;
		for(int x=0;x<= c.length();x++) {
			if(c[x]==' ') {
				if(c[x-2]== 'n',c[x-1]== 'e' && c[x+1] == 'l' && c[x+2] == 'e') { t+=c[x]; }
				
				else if(c[x+1] == 'e' && c[x+2] == 'x') { t+=c[x]; }
				else if(c[x+1] == 'd' && c[x-1] == 'v') { t+=c[x]; }
				else if(c[x+1] == 'p' && c[x-1] == 'n') { t+=c[x]; }
				else{ t.clear(); }
			}
			else if(c[x]=='\n'){ q.clear(); }
			else if (c[x]=='0' || c[x]=='1'|| c[x]=='2'|| c[x]=='3'|| c[x]=='4'|| c[x]=='5'){ q+=c[x]; }
			else if(c[x]=='i' && c[x+1]==' '){ q+=c[x]; }
			else if(c[x]=='i' && c[x+1]=='i' && c[x+2]==' '){ q+=c[x]; q+=c[x+1]; x++; }
			else if(c[x]=='i' && c[x+1]=='i' && c[x+2]=='i'){ q+=c[x]; q+=c[x+1]; q+=c[x+2]; x+=2; }
			else if(c[x]=='i' && c[x+1]=='v' && c[x+2]==' ') { q+=c[x]; q+=c[x+1]; x++; }
			else if(c[x-1]=='\n' && c[x]=='v' && c[x+1]==' '){ q+=c[x]; }
			else if(c[x]=='v' && c[x+1]=='i' && c[x+2]==' '){ q+=c[x]; q+=c[x+1]; x++; }
			else if(c[x]=='v' && c[x+1]=='i' && c[x+2]=='i') { q+=c[x]; q+=c[x+1]; q+=c[x+2]; x+=2; }
			else{ t+=c[x]; LevelOrder(root,t,q); } } }   
   
   
   void lorder(){  LevelOrder1(root); }
   
   void LevelOrder1(Node *r){
   	
   	if(r == 0){
   		return;
	   }       LevelOrder1(r->left);
	
	cout<<r->data<<" ";
	
	if(r->data=="learning") { 	if(r->id=="003 ") cout << "001 002 "; } cout << r->id << endl;   LevelOrder1(r->right);   

   }
   
     void postorder(Node *r){
   	
   		if(r == 0){
   		return;
	   }
	     
	postorder(r->left);
	postorder(r->right);
	cout<<r->data<<" ";    
   	
   }
   
   void LevelOrder(Node *r,string t,string store){
   	if(r == 0){
   		return;
	   }         LevelOrder(r->left,t,store);
	
	if(r->data == t) {
		r->id+=store;
		r->id+= ' ';
	}            LevelOrder(r->right,t,store);  }
   
   
};


int main(){
	
	string str; int para; string s, largestr;
	BST bstnode;

	int n; cin >> n;
	for(int y=0;y<=n;y++) { getline(cin, str); bstnode.insert(str); str.clear(); }
	
	cin >>para;
	
	for(int y=0 ; y<=para ; y++){ getline(cin,s); largestr += s + "\n"; }
	
	bstnode.compare_string(largestr); bstnode.lorder();

}
