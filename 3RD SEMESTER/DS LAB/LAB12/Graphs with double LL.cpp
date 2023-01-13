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
	    		
	    		Node *temp = new Node(val);
	    		
	    		tail->next = temp;
	    		temp->prev = tail;
	    		tail = tail->next;
			}
			else{
				head = tail = new Node(val);
		}
		}
		
		//traversing the list to the end
	
		int traverse() {
			Node *temp;
			if(isEmpty()) {
				cout << "List is empty.";
				return 0;
			}
			
			temp = head;
			cout<<temp->data<<"->";
			temp = temp->next;
			
			for(temp;temp!=NULL;temp=temp->next) {
				cout << temp->data << " ";
			}
			cout << endl;
			
		}
		
		int isEmpty(){
			
			return head == 0;
		}
	
		
};

int main(){
	
	Double_List d[5];
	
	d[0].AddToHead(0);
	d[0].insert_tail(4);
	d[0].insert_tail(3);
	d[0].insert_tail(2);
	d[0].traverse();
	
	d[1].AddToHead(1);
	d[1].insert_tail(3);
	d[1].insert_tail(2);
	d[1].insert_tail(4);
	d[1].traverse();
	
	d[2].AddToHead(2);
	d[2].insert_tail(3);
	d[2].insert_tail(1);
	d[2].insert_tail(4);
	d[2].traverse();
	

}
