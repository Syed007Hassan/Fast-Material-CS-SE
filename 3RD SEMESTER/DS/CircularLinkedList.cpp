#include <iostream>

using namespace std;

class Node
{
public:
    int info;
    Node *next;

    Node()
    {
        next = 0;
    }

    Node(int value, Node *ptr = 0)
    {
        info = value;
        next = ptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = 0;
    }

    void AddToHead(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;

            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void AddAfter(int info, int value = 0)
    {
    	
		
        if (isEmpty())
        {
            AddToHead(value);
        }
      
        
        else
        {
            Node *temp = head;

            while (temp->info != info && temp->next != head)
            {
                temp = temp->next;
                
            }
            if (temp->next != head)
            {
                Node *newNode = new Node(value);
                newNode->next = temp->next;
                temp->next = newNode;
            }
            else if(temp->next == head){
            	
            	AddToTail(value);
			}
        }
    }

    void AddToTail(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
     //       AddToHead(value);
        }
        else
        {
            Node *temp = head;
            while (temp->next != head){
			
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void DeleteHead()
    {
        if (isEmpty())
        {
            cout << "List is Already Empty";
        }
        else
        {
//            Node *pred = head, *temp = head;
//            if (temp->next == head)
//            {
//                head = NULL;
//                delete temp;
//            }
//            else
//            {
//                while (temp->next != head)
//                {
//                    temp = temp->next;
//                }
//                temp->next = head->next;
//                delete head;
//                head = temp->next;
//
//                cout << "HERE....";
//            }
           
            Node* temp = head;
            
            if (temp->next == head)
            {
               head = NULL;
                delete temp;
            }
            
            while(temp->next != head){
            	temp = temp->next;
			}
			
		//	cout<<"tewjnf "<<temp->info<<endl;
			
			Node* todelete = head;
			temp->next = head->next;
			head = head->next;
			
			
			delete todelete;

        }
        
     
    }

     // Class Activity
       void DeleteSpecific(int value)
    {
        Node* temp = head->next, *pred= head;
                
        if (isEmpty())
        {
       		cout << "List is already Empty";
    	}
    
        while(value != temp->info){
        	pred=temp;
          	temp = temp->next;	
		}
		
		if(temp==head) {
			delete temp;
			head=head->next;
			pred->next=head;
		}
		else {
			pred->next=temp->next;
				delete temp;	
		}
				
            }
					
	
    void DeleteEnd()
    {
        if (isEmpty())
        {
            cout << "List is already Empty";
        }
        else
        {
            Node *pred = head, *temp = head->next;
            if (temp->next == head)
            {
                head = NULL;
                delete temp;
            }
            else
            {
                while (temp->next != head)
                {
                    pred = temp;
                    temp = temp->next;
                }
                pred->next = head;
                delete temp;
            }
        }
    }
  
     void deletePosition(int c){   //working based on inserting node
	     	
	     	Node *temp;
	     	Node *n = head;
	     	int x,y;
	     	
	     	while(!(n->next == head)){
	     		y++;          //total no of list counter
	     		n = n->next;
			 }
			 
	     	
	     	for(temp = head; !(temp->next == head) && !(x == c-1);temp = temp->next,x++);
	     	
	        if(!(temp->next == head)){
	        	
	        	if(c == 0){       //if c==0 delete from head
	        		
	        		 DeleteHead();
				}
				
				else if( y == (c+1)){   //if c is at delete from tail
					
					 DeleteEnd();
					
				}
				
			else if( (c+1) > y){   //if c is greater than nodes position also delete from last
			
				 DeleteEnd();
			}
				
				
				else{           //if c is between the range add respectively
					
				  
				  temp->next = temp->next->next;
				   
				}
				
			}
				
	     }

    void PrintList()
    {
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
                cout << temp->info << "\t";
                temp = temp->next;

            } while (temp != head);
        }
    }

    bool ValueExist(int val) const
    {
        Node *temp = head;
        while (temp->next != head && temp->info != val)
            temp = temp->next;

        return temp != 0;
    }

    ~CircularLinkedList()
    {
        for (Node *p; !isEmpty();)
        {
            p = head->next;
            delete head;
            head = p;
        }
    }

    int isEmpty()
    {
        return head == 0;
    }
};

int main()
{
    CircularLinkedList list;
//    list.AddToHead(1);
//    list.AddToHead(5);
//    list.AddToTail(2);
//    list.AddToTail(3);

//    list.AddAfter(3, 4);
//     list.AddToTail(5);
//      list.AddAfter(5, 6);
//    
    list.AddToTail(5);
     list.AddToTail(5);
      list.AddToTail(5);
  
    // list.DeleteEnd();
    
    //list.DeleteSpecific(1);

    list.PrintList();
    
    //    list.DeleteHead();
    
 //  list.DeleteSpecific(1);
   
   
   
 //   list.PrintList();

//    list.AddToHead(6);
//    list.DeleteEnd();
//    list.AddToTail(7);
//    list.AddToHead(11);
 //   list.DeleteHead();
//
//    list.PrintList();
//    cout << endl;
//    cout << "VALUE: \t" << list.ValueExist(4);
//    cout << endl;
//    return 0;
}
