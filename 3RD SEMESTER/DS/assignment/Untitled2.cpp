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
		
		void insertAtFront(int p,int c,char x) {
			head= new Node(p,c,x,head);
			if(tail == 0) {
				tail=head;
			}
		}
		
		void insertAtEnd(int p,int c,char x) {
			if(tail!=0) {
				tail->next=new Node(p,c,x);
				tail=tail->next;
			}
			else {
				head=tail=new Node(p,c,x);
			}
		}
		
		
		void addpoly(Singlelist sl1,Singlelist sl2){
			
			Node *n1, *n2;
			
			n1=sl1.head;
			
			int num=0,count=0;
			
			while(n1!=NULL) {
				
				n2=sl2.head;
				num=n1->coeff;
				
				while(n2!=NULL) {
					
					if(n1->power == n2->power && n1->var == 'X' && n2->var == 'X') {
						num=num+n2->coeff; 
					}
					n2=n2->next;
				}
				insertAtEnd(n1->power,num,n1->var);
				num=0;
				n1=n1->next;
			}
			
			n2=sl2.head;
			while(n2!=NULL) {
				if(n2->var == 'Y') {
					insertAtEnd(n2->power,n2->coeff,n2->var);
				}
				n2= n2->next;
			}
		
		}
		
//		void swap() {
//			Node *temp=head, *temp2;
//			int num1;
//			int num2;
//			char ch;
//			
//			while(temp!=NULL) {
//				temp2=temp->next;
//				while(temp2!=NULL) {
//					if(temp->pow>temp2->pow) {
//						num1=temp->data;
//						num2=temp->pow;
//						ch=temp->variable;
//						
//						temp->data=temp2->data;
//						temp->pow=temp2->pow;
//						temp->variable=temp2->variable;
//						
//						temp2->data=num1;
//						temp2->pow=num2;
//						temp2->variable=ch;
//					}
//					temp2=temp2->next;
//				}
//				temp=temp->next;
//			}
//			
//			temp=head;
//			for(temp=head;temp!=NULL;temp=temp->next) {
//				cout << temp->data << " " << temp->variable << " " << temp->pow << endl;
//			}
//			
//		}



void doswap(Node *node_1, Node *node_2){
			
	    int temp1 = node_1->power;
	    int temp2 = node_1->coeff;
	    int temp3 = node_1->var;
	    
	    node_1->power = node_2->power;
	    node_1->coeff = node_2->coeff;
	    node_1->coeff = node_2->coeff;
	    
		node_2->power = temp1;
		node_2->coeff = temp2;
		node_2->var = temp3;
		
		}
		
		void sort(){
			
			Node *temp = head;
			Node *temp1 = 0;
			int swapped;
			
			do{
				int swapped = 0;
				
				while(temp->next != temp1){
					
					if(temp->power > temp->next->power){
						
						doswap(temp,temp->next);
						swapped =1;
					}
					
					temp = temp->next;
				}
				
				temp1 = temp;
				
			} while(swapped);
			
			
		}


		void traverse(){
//			cout<<endl;
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
	
		sl1.insertAtEnd(p,c,x);
	}
	
//	cout<<"Enter the terms of eq 2: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		
//	  cout<<"coeff variable power "<<i<<endl;
		cin>>c;
		cin>>x;
		cin>>p;
		
		sl2.insertAtEnd(p,c,x);
	}
		
	sl1.sort();

	
	r.addpoly(sl1,sl2);
	
	r.sort();
    
	
	r.traverse();
	
}
