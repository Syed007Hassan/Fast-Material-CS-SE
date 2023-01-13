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
	     	
        Node* newNode = new Node(value);
      
	  if (head == NULL)
        {
            head = tail =  newNode;
            head->next = head;
            head->prev = head; 
        }
        else
        {
            
           tail->next = newNode;
           newNode->prev = tail;
           newNode->next = head;
           head->prev = newNode;
            
           
        }
    }


	//traversing the list to the end
	
		int traverse() {
			if (isEmpty())
        {
            cout << "List is Empty..." << endl;
        }
        else
        {
            Node *temp = head;
            cout << endl;

            do
            {
                cout << temp->data << "\t";
                temp = temp->next;

            } while (temp != head);
        }
			
		}
		
		int isEmpty(){
			
			return head == 0;
		}
	
};

int main(){
	
	Double_List dl;
	
	dl.AddToHead(1);
	dl.AddToHead(2);
	dl.AddToHead(2);



   dl.traverse();  


}
