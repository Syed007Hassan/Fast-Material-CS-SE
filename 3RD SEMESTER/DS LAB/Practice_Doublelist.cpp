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
		
		
	 void AddToHead(int value)
    {
        head = new Node(value, head);
        if (tail == 0)
        {
            tail = head;
        }
    }
		
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
		
		void add_after(int val,int value){
			
			if(isEmpty()){
				 AddToHead(value);
			}
			
			else if(val == head->data){
				
				Node *temp = new Node(value);
				head->next = temp;
				temp->prev = head;
				temp->next = 0;
				
			}
			
			else{
				
				Node* temp;
				for(temp = head; temp != 0, !(temp->data == val),temp = temp->next;);
			
			if(temp!= 0){
				
				Node *n = new Node(value);
				
				n->next = temp->next;
				n->next->prev=n;
				temp->next = n;
				n->prev = temp;
				
				
			}
			else{
				
				insert_tail(value);
			}
		}
			
		}
		
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
		
		void delete_node(int val){
			
			if(head!=0){
				
				if(val == head->data){
					
					delete_head();
				}
				
				else if(val == tail->data){
					
					delete_tail();
				}
				
				else{
					
					Node *temp;
					
					for(temp=head; temp!=0 && !(temp->data == val); temp = temp->next);
					
					if(temp != 0){
					
					 temp->prev->next = temp->next; 
                    temp->next->prev = temp->prev;
                   
				    if (temp == tail){
					}
                       
                    delete temp;
				}
					
				}	
				
			}
			
			
			
		}
	
	
	
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
	
	dl.AddToHead(5);
	dl.insert_tail(10);
		dl.insert_tail(12);
//	dl.add_after(5,10);
//	dl.add_after(10,12);
//		dl.add_after(11,16);
		
	//	dl.delete_head();
		
	//	dl.delete_tail();
	dl.traverse();
   dl.delete_node(10);
 
 	dl.traverse();
 
//    
//    dl.insert_tail(4);
   

	

	
	
}
