#include<cstring>
#include<iostream>
using namespace std;

class Node {
	public:
		char info[25]; Node *next, *prev;
		
		Node(){ next=0;prev=0;}
		
		Node(char a[25], Node *ptr=0){
			
			strcpy(info,a); next=ptr; prev = 0;
		}
};

class DoubleList {
	private:
		Node *head, *tail;
	public:
		DoubleList() { head=0; tail=0; }
	
     void AddToHead(char value[25]){
      
	    head = new Node(value, head);
        if (tail == 0){ tail = head; }
    }
	
	void UniqueWordsSorting() {
		
		Node *n1=head->next, *n2=head; char x[25],y[25],z[25];
		
		while(n1!=0) { strcpy(x,n1->info);
		while(n2!=0) { strcpy(y,n2->info);
					
		if(strcmp(n1->info,"How")==0) {	strcpy(n1->info,"how"); }
		
		if(strcmp(n1->info,"If")==0) { strcpy(n1->info,"if"); }
		
		else if(strcmp(n2->info,n1->info) > 0)
        {  
		 strcpy(z,n2->info); strcpy(n2->info, n1->info); strcpy(n1->info, z);
   		}   
		n2=n2->next;
		}
		n1=n1->next;
		n2=head;
		}
		}
		
		
    	int FindUniqueWords(){
			Node *n; n=head; string a,b;
			if(isEmpty()) {
				cout << "List is empty.";
				return 0; }
			
			while(n->next!=0){
				
			a=n->info,b=n->next->info;
			if(a.compare(b)==0){}
			
			else{
			if(strcmp(n->info,"how")==0) { strcpy(n->info,"How"); }
			
			if(strcmp(n->info,"if")==0) {  strcpy(n->info,"If");  }
			  cout << n->info << endl;
			  }	n=n->next;
			} cout << n->info;
		}
		
		int isEmpty(){
		return head==0;	}
};

int main(){
	DoubleList list; char ch[25]; int c = 0; int words_given = 13;
	
	for(int i=0;i<words_given;i++)
	{
	    
		cin >>ch; list.AddToHead(ch);
		
		if(strcmp(ch,"AAP")==0) { ++c; }
		
		if(c==2) { break;}
	}
	
	list.UniqueWordsSorting(); list.FindUniqueWords();
}
