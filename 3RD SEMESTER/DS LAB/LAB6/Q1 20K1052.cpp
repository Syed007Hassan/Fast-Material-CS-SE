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
	
	//deleting with respect to value
		
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
		
	//inserting at any given position
		
	    void insertatposition(int c,int val){   //perfectly working now
	     	
	     	Node *temp;
	     	Node *n = head;
	     	int x,y;
	     	
	     	while(n!=0){
	     		y++;          //total no of list counter
	     		n = n->next;
			 }
			 
	     	
	     	for(temp = head; temp!=0 && !(x == c);temp = temp->next,x++);
	     	
	        if(tail!= 0){
	        	
	        	if(c == 0){       //if c==0 add to head
	        		
	        		AddToHead(val);
				}
				
				else if( y == (c+1)){   //if c is at last add to tail
					
					insert_tail(val);
					
				}
				
			else if( (c+1) > y){   //if c is greater than nodes position also add at last
				
				insert_tail(val);
			}
				
				
				else{           //if c is between the range add respectively
					
					Node *n = new Node(val);
					
					temp->prev->next = n;
					temp->prev = n;
					n->prev = temp->prev;
					n->next = temp;
				}
				
			}
				
	     }
	     
	//deleting at any given position
	
	     
	    void deletePosition(int c){   //working based on inserting node
	     	
	     	Node *temp;
	     	Node *n = head;
	     	int x,y;
	     	
	     	while(n!=0){
	     		y++;          //total no of list counter
	     		n = n->next;
			 }
			 
	     	
	     	for(temp = head; temp!=0 && !(x == c);temp = temp->next,x++);
	     	
	        if(tail!= 0){
	        	
	        	if(c == 0){       //if c==0 delete from head
	        		
	        		delete_head();
				}
				
				else if( y == (c+1)){   //if c is at delete from tail
					
					delete_tail();
					
				}
				
			else if( (c+1) > y){   //if c is greater than nodes position also delete from last
				
				delete_tail();
			}
				
				
				else{           //if c is between the range add respectively
					
				  
				    temp->prev->next = temp->next;
				    temp->next->prev = temp->prev;
				    
				    delete temp;
				   
				}
				
			}
				
	     }
	     	
	//finding the maximum in the list 
		 	
		void maximum(){
		Node* temp = head;
		int max = temp->data;

		
		while(temp!= 0 ){
			if(max < temp->data){
				max = temp->data;
			}
			temp = temp->next;
		}
		cout<<"The maximum value in list is: "<<max<<endl;
	}
	
	//finding then mean of the list 
	
	    void mean(){
		Node *temp = head;
		
		int c=0;
		float x,sum;
		
		
		while(temp!= 0){
			sum = sum + temp->data;
			++c;
			temp = temp->next;	
		}
		
		x = sum/c;
		
		cout<<"The mean(avg) value of the list is: "<<x<<endl;
		
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
    
    //sorting the list 
    
	
	  	void sort(){
		
		Node *temp=head->next; 
		Node *temp1 = head->next->next;
		int swap;
	
		if(head->data < temp->data){
			
			swap = head->data;
			head->data = temp->data;
			temp->data = swap;
		}
		
		while(temp1->next != 0){
			
			if(temp1->data > temp->data){
				swap = temp1->data;
				temp1->data = temp->data;
				temp->data = swap;
			}
			
			else if(temp1->data < temp1->next->data){
				
				swap = temp1->data;
				temp1->data = temp1->next->data;
				temp1->next->data = swap;
			}
			
			temp = temp1;
			temp1 = temp1->next;			
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
	
	dl.AddToHead(6);
	dl.insert_tail(4);
	dl.insert_tail(5);
	dl.insert_tail(3);
	dl.insert_tail(1);


//    dl.insertatposition(5,6);
//    dl.deletePosition(5);
// 
//	dl.traverse();
// 	
// 	dl.maximum();
// 	
// 	dl.mean();
// 	
// 	dl.reverseLL();
 	
 	dl.traverse();
 
 dl.sort();
 
   dl.traverse();
 

	

	
	
}
