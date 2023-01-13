#include<iostream>
using namespace std;

class Node{
	
	public:
		int data;
		Node *next,*prev;
		
		Node(){
			data = 0;
			next = 0;
			prev = 0;
		}
		
		Node(int val,Node *ptr = 0){
			
			data = val;
			next = ptr;
			prev = 0;
		}
		
};


class Double_List{
	
	private:
		
		Node *head, *tail;

    public:
    	
    	Double_List(){
    		head = 0;
    		tail = 0;
		}
		
	//adding to the head
		
	     void AddToHead(int value)
    {
        head = new Node(value, head);
        if (tail == 0)
        {
            tail = head;
        }
    }
	
	//adding to the tail
		
	    void insert_tail(int val){
			
			if(tail!=0){
				
				Node* temp = new Node(val);
				tail->next = temp;
				temp->prev = tail;
				tail = tail->next;
			}
			
			else{
			
			head = tail = new Node(val);		
		   }
		}
	
    //finding the middle node
    
    void middlenode(){
    	
    	Node* temp = head;
    	int y,x;
    	
    	while(temp!=0){
    	   y++;
		   temp = temp->next;	
		   
	//	   cout<<"Total no of nodes are "<<y<<endl;
		}
		
		y = y/2;
		
		Node* n = head;
		
		while(x!=y){
			x++;
			n=n->next;
		}
		
		cout<<"The middle node is "<<n->data<<endl;
    	
    	
    	
	}
	
	//traversing the list to the end
	
		int traverse() {
			Node *temp;
			if(isEmpty()) {
				cout << "List is empty.";
				return 0;
			}
			for(temp=head;temp!=NULL;temp=temp->next) {
				cout << temp->data << " ";
			}
			cout << endl;
			
		}
		
		int isEmpty(){
			
			return head == 0;
		}
	
};

int main(){
	
	Double_List dl,dl2;
	
	dl.AddToHead(1);
	dl.insert_tail(2);
	dl.insert_tail(3);
	dl.insert_tail(4);
	dl.insert_tail(5);

    dl.traverse();
    dl.middlenode();
 
  	dl2.AddToHead(1);
	dl2.insert_tail(2);
	dl2.insert_tail(3);
	dl2.insert_tail(4);
	dl2.insert_tail(5);
	dl2.insert_tail(6);

    dl2.traverse();
    dl2.middlenode();
 
 

	

	
	
}
