#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node() {
			next=NULL;
		}
		Node(int val, Node *ptr=0) {
			data=val;
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
		
		void insertAtFront(int val) {
			head= new Node(val,head);
			if(tail == 0) {
				tail=head;
			}
		}
		
		void insertAtEnd(int val) {
			if(tail!=0) {
				tail->next=new Node(val);
				tail=tail->next;
			}
			else {
				head=tail=new Node(val);
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
		
		 void insertatposition(int c,int val){   //perfectly working now
	     	
	     	Node *temp;
	     	Node *n = head;
	     	Node *q = head;
	     	int x,y,z;
	     	
	     	while(n!=0){
	     		y++;          //total no of list counter
	     		n = n->next;
			 }
			 
			 z = y;
			 
			 while(z > c ){
			 	z--;
			 	 q = q->next;
			 }
			 
	     	
	     	for(temp = head; temp!=0 && !(x == c-1);temp = temp->next,x++);
	     	
	        if(tail!= 0){
	        	
	        	if(c == 0){       //if c==0 add to head
	        		
	        		insertAtFront(val);
				}
				
				else if( y == (c+1)){   //if c is at last add to tail
					
					insertAtEnd(val);
					
				}
				
			else if( (c+1) > y){   //if c is greater than nodes position also add at last
				
				insertAtEnd(val);
			}
				
				
				else{           //if c is between the range add respectively
					
					Node *n = new Node(val);
					q ->next = n;
					temp->next = q;
					q->next = temp->next;
				}
				
			}
				
	     }
		

		void insertAtPosition(int val) {
			int pos;
			cout << "Enter position:";
			cin >> pos;
			pos=pos-1;
			Node *add= new Node(val);
			Node *temp=head;
			int c=0;
			while(temp!=0) {
				c+=1;
				if(c==pos) {
					add->next=temp->next;
					temp->next=add;
				}
				temp=temp->next;
			}
		}
		
		void deleteFirst() {

        	Node *temp = head;

        	if (head == tail)
        	{
           		head = tail = 0;
        	}
        	else
        	{
            	head = head->next;
        	}
        	delete temp;
		}
		
		void deteleEnd() {
        	if (head == tail)
        	{
            	delete head;
            	head = tail = 0;
        	}
        	else
        	{
            	Node *temp;
            	for (temp = head; temp->next != tail; temp = temp->next);
            	delete tail;
            	tail = temp;
            	tail->next = 0;
        	}
		}
		
		void deletePosition(int pos) {
			Node *temp=head;
			
			int x=0;
			if(pos==1) {    //if deleting head
				head=head->next;
				delete temp;
			}
			else {
				while(temp!=0) {
					x = x + 1;
				if(x == pos-1) {
					
				temp->next=temp->next->next;   //moving the pointer a node forward hence disconnecting with
				}                                  //previous one
				temp=temp->next;
			}
			}
		}
		
		
	void maximum(){
		Node* temp = head;
		int max = temp->data;
	//	temp = temp->next;
		
		while(temp!= 0 ){
			if(max < temp->data){
				max = temp->data;
			}
			temp = temp->next;
		}
		cout<<"The maximum value in list is: "<<max<<endl;
	}
	
	
	void mean(){
		Node *temp = head;
		
		int c,sum=0,x=0;
		
		
		while(temp!= 0){
			sum = sum + temp->data;
			c++;
			temp = temp->next;	
		}
		
		x = sum/c;
		
		cout<<"The mean(avg) value of the list is: "<<x<<endl;
		
	}
	
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
          insertAtEnd(node->data);
        }
    }
    
    
   //palindrome check using revcursion 
    
    bool palindromecheck(Singlelist &A , Singlelist &B){
    	
      Node *n = A.head;
      Node *q = B.head;
      
      
      while(n!=0){
      	
      	if(n->data == q->data){
      
      		n = n->next;
      		q = q->next;
		  }
		  else{
		  	
		  	return false;
		  }
      	
      
	  }	
	  
	  	return true;
    	
	}
	
	
	void hello(){
	
	   Node *temp = head;
	   
	   
	   while(temp != 0){
	   	
	   	   cout<<temp->data<<" ";
	   	   temp = temp->next;
	   	
	   }	
	}
		
    	
		
		int isEmpty()
    	{
        	return head == 0;
    	}
		
};

int main() {
	Singlelist list,list1,list3;
	int opt=1,num,pos;
//	
//	while(opt!=12) {
//		cout <<endl<<"1-Insert At Front \n2-Insert At End \n3-Insert At Position \n4-Detete First \n5-Traverse \n6-Delete End \n7-Delete Position \n8-Maximum of List \n9-Mean of the List \n10-Sort in Ascending order \n11-Reversing the list \n12-Exit program" << endl<<endl;
//		
//		cout<<"Enter option: ";
//		cin >>opt;
//		cout << endl<<endl;
//
//		switch(opt) {
//			case 1:
//				cout << "\nEnter Element: ";
//				cin >> num;
//				list.insertAtFront(num);
//				list.traverse();
//				cout << endl;
//				break;
//			case 2:
//				cout << "\nEnter Element: ";
//				cin >> num;
//				list.insertAtEnd(num);
//				list.traverse();
//				cout << endl;
//				break;
//			case 3:
//				cout << "\nEnter the new data for the current position: ";
//				cin >> num;
//				list.insertAtPosition(num);
//				list.traverse();
//				cout << endl;
//				break;
//			case 4:
//				list.deleteFirst();
//				list.traverse();
//				cout << endl;
//				break;
//			case 5:
//				list.traverse();
//				cout << endl;
//				break;
//			case 6:
//				list.deteleEnd();
//				list.traverse();
//				cout << endl;
//				break;
//			case 7:
//				cout << "Enter the position for deleting at: ";
//				cin >> pos;
//				list.deletePosition(pos);
//				list.traverse();
//				break;
//			case 8:
//				list.maximum();
//				break;
//			case 9:
//				list.mean();
//				break;
//			case 10:
//				list.sort();
//					list.traverse();
//				break;
//			case 11:
//				list.reverseLL();
//				list.traverse();
//				break;
//			case 13:
//				list.palindromecheck();
//				
//				break;								
//		}
//	}

   list.insertAtEnd(1);
   list.insertAtEnd(2);
   list.insertAtEnd(2);
   list.insertAtEnd(1);
  
   
   list1.insertAtEnd(1);
   list1.insertAtEnd(2);
   list1.insertAtEnd(2);
   list1.insertAtEnd(1);
  
   
 //  list.traverse();
   
   //list.insertatposition(4,6);
   
  list1.reverseLL();
   
 cout<< list.palindromecheck(list,list1);
      
    list3.insertAtEnd(11);
	list3.insertAtEnd(7); 
	list3.insertAtEnd(2);
	list3.insertAtEnd(6);
	list3.insertAtEnd(4);
	
	
//	list3.hello();
	
//	cout<<endl;
//	list3.sort();
//	
//	list3.traverse(); 

	return 0;
}
