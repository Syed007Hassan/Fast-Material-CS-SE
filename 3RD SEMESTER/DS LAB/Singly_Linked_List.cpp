#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		
		
		node(int d){
			data = d;
			next = NULL;
		}
};

void insertAtHead(node* &head,int val){
	node* n = new node(val);  //new node to be inserted
	
	n->next= head; //pointing the newly node to head;
	head = n;      
	return;
	
}

void insertAtTail(node *&head,int val){
	
	node *n = new node(val);  //new node to be inserted
	
	if(head == NULL){
		head = n;      //means we have no node and this is the first one in our linked list
		return;   
	}
	
	node *temp = head;   //temporaray node for traversing from the head till tail
	
	while(temp->next != NULL){  //moving the temp unless it reaches the NULL 
		temp = temp->next;
	}
	
	temp->next = n;   //Here the value of n(val) moves to temp of next before the NULL
}


void Display(node *head){
	
	node *temp = head;   //temporaray node for traversing from the head till tail
	
	while(temp!= NULL){   //moving the temp unless it reaches the NULL
		
		cout<<temp->data<<"->";  //accessing the data through temp node
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

void deleteatHead(node* &head){
	node* todelete = head;
	
	head = head->next;
	
	delete todelete;
}

void deletion(node* head, int val){
	
	if(head == NULL){  //if linked list is empty
		return;
	}
	
	if(head->next == NULL){  //if only one node is present 
		deleteatHead(head);
		return;
	}
	
	
	node* temp = head;    //temporaray node for traversing from the head till tail
	
	while(temp->next->data != val){  //finding n-1 node 
		temp = temp->next;          
	}
	
	node* todelete = temp->next;
	temp->next = temp->next->next;   //pointing  node n-1 = n+1
	
	delete todelete;
}

bool search(node* &head,int key){
	
	node* temp = head;
	while(temp!= NULL){
		if(temp->data == key){
			return true;
		}
		temp=temp->next;
	}
	return false;
}



int main(){
	
	node *head= NULL;
	
	insertAtHead(head,1);
	insertAtHead(head,0);
	
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	
	Display(head);
	
	deletion(head,2);
	
	Display(head);
	
	deleteatHead(head);
	Display(head);
	
	//cout<<search(head,5)<<endl;
}
