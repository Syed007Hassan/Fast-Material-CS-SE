#include<iostream>
using namespace std;

class Node{
	
	public:
		int data;
		Node* next;
	
	Node(){
		
		
	}
	
	Node(int value, Node* ptr = 0){
		data = value;
		next = ptr;
	}
	
};


class SinglyList{

 private:
 	
 	Node *head,*tail;

     public:
     	
     	SinglyList(){
     		
     		head = 0;
     		tail = 0;
		 }
        
       void addtohead(int value){
        	
        	head = new Node(value,head);
        	
        	if(tail == 0){
        		tail = head;
				
		      }
	}
		
		
		int search(int value){
			
			int static x=0;
			Node *temp;
			
			for(temp = head; temp!= NULL; temp = temp->next){
				
				if(temp->data == value){
						x = x+1;
				}
			}
			
		cout<<value<<" is "<<x<<" times in the list"<<endl; 
			
		}
};

int main(){
	
SinglyList list;

list.addtohead(1);  //just adding to head inorder to check only the list
list.addtohead(2);
list.addtohead(1);
list.addtohead(2);
list.addtohead(1);
list.addtohead(5);
list.addtohead(7);


 list.search(1);
}
