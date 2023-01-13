#include <iostream>
using namespace std;

class Node {
	public:
	int power;
		int coeff;
		char var;
		Node *next;
	
		Node() {
			next=0;
			coeff=0;
			var=0;
			power=0;
		}
		Node(int p,int c,char x,Node *ptr=0) {
			power = p;
			coeff = c;
			var = x;
			next=ptr;
		}
};

class Singlelist {
	private:
		Node *head, *tail;
	public:
		Singlelist() {
			head= 0;
			tail = 0;
		}
		
	// Inserting Node at head	
		void insertAtFront(int p,int c,char x) {
			head= new Node(p,c,x,head);
			if(tail == 0) {
				tail=head;
			}
		}
	
	// Inserting Node at tail	
		void insertAtTail(int p,int c,char x) {
			if(tail!=0) {
				tail->next=new Node(p,c,x);
				tail=tail->next;
			}
			else {
				head=tail=new Node(p,c,x);
			}
		}
		
	// Swapping wrp to power, coeff, var 		
		void doswap(Node *node_1, Node *node_2){
			
	    int temp1 = node_1->power;
	    int temp2 = node_1->coeff;
	    char temp3 = node_1->var;
	    
	    node_1->power = node_2->power;
	    node_1->coeff = node_2->coeff;
	    node_1->var = node_2->var;
	    
		node_2->power = temp1;
		node_2->coeff = temp2;
		node_2->var = temp3;
		
		}
	
	//Bubble Sorting based on power swapping 		
	void sort(){

	Node *temp; Node *temp1 = NULL; int flag;
	do
	{   flag = 0;
	    temp = head;
		while(temp->next != temp1)
		{
		
		if (temp->power > temp->next->power){ doswap(temp, temp->next); flag=1; }
			temp = temp->next;
		
		} temp1 = temp;
	
	} while(flag);
}

//new sort

	void sortt(){

	Node *temp; Node *temp1 = NULL; int flag;
	do
	{   flag = 0;
	    temp = head;
		while(temp->next != temp1)
		{
		
		if (temp->var > temp->next->var){ doswap(temp, temp->next); flag=1; }
			temp = temp->next;
		
		} temp1 = temp;
	
	} while(flag);
}

	//Adding the two polynomials together 		
		void addpoly(Singlelist sl1,Singlelist sl2){
			
		Node *n1 = sl1.head; Node *n2; int coEFF=0;
			
		while(n1!=NULL) {
		n2=sl2.head; coEFF=n1->coeff;
				
		while(n2!=NULL) {
		if(n1->var == 'X' && n2->var == 'X' && n1->power == n2->power) {coEFF=coEFF+n2->coeff; }
		n2=n2->next;
		}				
		 insertAtTail(n1->power,coEFF,n1->var); coEFF=0; n1=n1->next;
	    }
		
		n2=sl2.head;
		while(n2!=NULL) {
			
		if(n2->var == 'Y') {insertAtTail(n2->power,n2->coeff,n2->var); }
		n2= n2->next;
		}}
		
    //Traversing the list and printing it
		void traverse(){
			Node *n = head;
			int c;
			
			while(n!=0){
				c++;
				n = n->next;
			}
			
			Node *temp =head;
			
			if(!isEmpty()){
				cout<<c<<endl;
				while(temp!=0){
					
					cout<<temp->coeff<<" "<<temp->var<<" "<<temp->power<<endl;
					
					temp = temp->next;
				}
				cout<<endl;
			}
			
	//checking the List empty		
		}
		
		int isEmpty() {
			return head == 0;
		}
		
	
};

int main() {
	Singlelist sl1,sl2,r;
	int n,p,c;
	char x = '\0';
	
//	cout<<"Enter the terms of eq 1: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		
//		cout<<"coeff variable power "<<i<<endl;
		cin>>c;
		cin>>x;
		cin>>p;
	
		sl1.insertAtTail(p,c,x);
	}
	
//	cout<<"Enter the terms of eq 2: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		
//	  cout<<"coeff variable power "<<i<<endl;
		cin>>c;
		cin>>x;
		cin>>p;
		
		sl2.insertAtTail(p,c,x);
	}
		
	r.addpoly(sl1,sl2);
	
//	r.sort();
	r.sortt();
	
	r.traverse();
	
}
