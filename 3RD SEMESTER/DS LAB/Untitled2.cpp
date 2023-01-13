#include<iostream>
using namespace std;

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

class BT{
	
	Node *root;
	int arrr[3],m=0;
	int x = 1;
	
	public:
		
   BT(){
   	root = 0;
   }
   
   //Inserting in BST
   
    void insert(int x) {
        root = insert(x, root);
    }

   Node *insert(int val,Node *r){
   	
   	if( r == 0){
   		r = new Node(val);
   		r->left = r->right = 0;
	   }
	   
	else if(val < r->data){
		r->left = insert(val,r->left);
	}
	
	else if(val > r->data){
		r->right = insert(val,r->right);
	}
	
	return r;      
   	
   }
   
   
   void lorder(){
   	
   	LevelOrder(root);
   	
   }
   
   
  void LevelOrder(Node *r){
 	
 	Node *n = r;
 	Node *q;
 	Node *p;
 	Node *x,*y;
 	
 	if(r!= 0){
 		cout<<r->data<<" "<<r->data<<endl;
 		
 		while(r->left || r->right || n->right || n->left ){
 			
 			if(r->left){	
 			cout<<r->left->data<<" ";
 			
 			x = r->left;
 			
 			if(x->left){
 				
 				if(x->left->right == 0 && x->left->left == 0 ){
 					if(x->right->left){
 						y = x->right->left;
					 }
					 else{
					 	y = x->right->right;
					 }
				 }
			 }
 			
 			r = r->left;
 			
 		   }
 		   else if(r->left == 0 && r->right != 0){
 	
 				cout<<r->right->data<<" ";
 				r = r->right;
			 }
			 
			else if(r->right == 0 && r->left == 0 ){
 		 
 			  cout<<y->data<<" ";
 			  r = y;
			 } 
  
  			 
   
 		   if(n->right){
 			cout<<n->right->data<<" ";
 			q = n->right;
 			
 			if(q->right){
 				
 				if(q->right->right == 0 && q->right->left == 0 ){
 					if(q->left->right){
 						p = q->left->right;
					 }
					 else{
					 	p = q->left->left;
					 }
				 }
			 }
 			
 			n = n->right;
 			
 		   }
 		   
 		   else if(n->right == 0 && n->left !=0){
 		 
 			  cout<<n->left->data<<" ";
 			  n = n->left;
			 }
			 
		   else if(n->right == 0 && n->left == 0 ){
 		 
 			  cout<<p->data<<" ";
 			  n = p;
			 }
			 	 
 		   
 		   cout<<endl;
 		   
		 }	 
	 }
 }
 
 void printLevelOrder()
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++){
		m=0;
		printCurrentLevel(root, i);
		find();
	}
}

void printCurrentLevel(Node* r, int level)
{
	if (r == NULL){
	    return ;
	//	printfun(a);
	}
	if (level == 1)
	{
		arrr[m++]=r->data;
		
		//cout << root->data << " ";
	}
	else if (level > 1) {
		printCurrentLevel(r->left, level - 1);
		printCurrentLevel(r->right, level - 1);
	}
}



int height(Node* n)
{
	if (n == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		int lheight = height(n->left);
		int rheight = height(n->right);

		/* use the larger one */
		if (lheight > rheight) {
			return (lheight + 1);
		}
		else {
			return (rheight + 1);
		}
	}
}



void find(){
	int size=sizeof(arrr)/sizeof(arrr[0]);
	int min,max;
	
	 min=arrr[0];
	 max=arrr[0];

	for(int i=0 ; i < size ; i++){
		if(min>arrr[i] && arrr[i]!=0)	{
			min=arrr[i];
		//	cout << "min: " <<min <<endl;
		}
	    if(max<arrr[i]){
			max=arrr[i];
		//	cout << "max: " <<max <<endl;
		}
	}
	
	
	  if(x < 2){
	  	cout<< min <<" "<< min<<endl;
	  	++x;
	  }
	  else{
	  	cout<<min<<" "<<max<<endl;
	
	  }

	
	for(int i =0 ; i <size ; i++){
		arrr[i]=0;
	}
}


   
   
 
   
   
};


int main(){
	
	

 int n;
 cin>>n;
 int arr[n];
 
 BT bb;

for(int i=0;i<n;i++){
	cin>>arr[i];
}

for(int i=0;i<n;i++){
	bb.insert(arr[i]);
}

   // bb.lorder();
    
    bb.printLevelOrder();
    
  
    
}
