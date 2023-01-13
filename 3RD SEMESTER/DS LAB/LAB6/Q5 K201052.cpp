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
		
	     void AddToHead(int value){
	     	
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
	
	
	//deleting the head
		
		void delete_head(){
				Node*temp = head;
			if(head!=0){
			
				head = head->next;
				head->prev = 0;
				delete temp;
			}
			else if(head == tail){
				
				head = tail = 0;
			}
		}
	
	
	//deleting the tail
		
		void delete_tail(){
			Node*temp = tail;
			
			if(tail!=0){
				tail = tail->prev;
				tail->next = 0;
				delete temp;
			}
			else if(head == tail){
				
				head = tail = 0;
			}
		}
	

    //reversing the list using recursion
   	
		void reverseLL()
    {
        reverse(head);
    }

    void reverse(Node *node)
    {
        if (node == NULL)
        {
            head = 0;
            tail = 0;
        }

        else
        {
            reverse(node->next);
          insert_tail(node->data);
        }
    }
    
    
    //for finding the duplicate elements and removing it.
    
 void checkDuplicate() {
			Node *temp, *temp1;
			temp1=head;
			
			while(temp1->next!=0) {
				temp=temp1->next;
			
				while(temp!=0) {
			
					if(temp1->data==temp->data && temp->next !=0) {
						temp->prev->next=temp->next;
						temp->next->prev=temp->prev;
					}
					else if(temp1->data==temp->data && temp->next ==0) {
						temp->prev->next=0;
					}
					temp=temp->next;
				}
				
				temp1=temp1->next; 
			}
			
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
	
	Double_List dl;
	
	dl.AddToHead(12);
	dl.insert_tail(12);
	dl.insert_tail(11);
	dl.insert_tail(21);
	dl.insert_tail(41);
	dl.insert_tail(43);
	dl.insert_tail(21);



    dl.traverse();

	
    dl.checkDuplicate();
    
    dl.traverse();
	
	
}
