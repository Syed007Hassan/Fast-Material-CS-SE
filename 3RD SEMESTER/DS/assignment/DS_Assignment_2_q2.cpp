#include<iostream>
using namespace std;

class Node{
	
	public:
		string pid;
		int tt;
		int qouta;
		Node *next;
		
	Node(string p,int t,int q,Node *ptr = 0){
		pid = p;
		tt = t;
		qouta = q;
		next = ptr;
	}	
};

class CircularList{
	
	Node *head;
	
	public:
		
		CircularList(){
			head = 0;
		}	
	
	void insertAtEnd(string p,int t,int q){
        Node *n = new Node(p,t,q);
        if (head == NULL)
        {   
		    
            head = n; head->next = head;
        }
        else
        {  
		    Node *temp = head;
            while (temp->next != head){   temp = temp->next; }
            temp->next = n;
            n->next = head;
        }
    }
    
    
   void TinyOs(){
    	
    	Node *temp = head;
    	Node *temp1 = 0;
    	
    	do{
    		
    		if(temp->tt != 0){
    			cout<<temp->pid<<endl;
    			temp->tt = temp->tt - temp->qouta;
    			temp1 = temp;
    			temp = temp->next;
			}
			else{
			 
			  	temp = temp1->next->next;	
			}
			
			if(temp->tt == 0 && temp->next->tt == 0 && temp->next->next->tt == 0) {
				break;
			}
    			
		}
		while(temp!=0);
    	
	}
    
    	void traverse(){	
			Node *temp =head;
			
			if(!isEmpty()){
			 do
            {
              cout<<temp->pid;
                temp = temp->next;

            } while (temp != head);
			}
				
		}
		
	
	
	int isEmpty()
    {
        return head == 0;
    }
	
	
};

int main(){
	
	CircularList cl;
	string a; int b,c,n;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>a;
	cin>>b;
	cin>>c;
	cl.insertAtEnd(a,b,c);
  }   	
	cl.TinyOs();	
}
