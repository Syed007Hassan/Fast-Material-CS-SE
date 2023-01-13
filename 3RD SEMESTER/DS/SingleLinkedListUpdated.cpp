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

class SingleLinkList
{
private:
    Node *head, *tail;

public:
    SingleLinkList()
    {
        head = tail = 0;
    }

    void AddToHead(int value)
    {
        head = new Node(value, head);
        if (tail == 0)
        {
            tail = head;
        }
    }

    void AddAfter(int info, int val = 0)
    {
        if (isEmpty())   //if no node is there means completely empty
        {
            AddToHead(val);
        }
        else if (head->info == info)   //if adding directly after head
        {
            Node *temp = new Node(val);
            temp->next = head->next;
            head->next = temp;
        }
        else
        {
            Node *temp;           //adding in between of 2 nodes anywhere
            for (temp = head; temp != 0 && !(temp->info == info); temp = temp->next)
                ;
            if (temp != 0)
            {
                Node *n = new Node(val);
                n->next = temp->next;
                temp->next = n;
            }
            else
            {
                AddToTail(val);
            }
        }
    }

    void AddToTail(int value)
    {
        if (tail != 0)
        {
            tail->next = new Node(value);
            tail = tail->next;
        }
        else
        {
            head = tail = new Node(value);
        }
    }

    int DeleteFromHead()
	{
        int val = head->info;

        Node *temp = head;

        // Only One Item in the List
        if (head == tail)
        {
        	delete head;
            head = tail = 0;
        }
        else
        {
            head = head->next;
        }

        delete temp;
        return val;
    }

    int DeleteFromTail()
    {
        int value = tail->info;
        if (head == tail)
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            Node *temp;
            for (temp = head; temp->next != tail; temp = temp->next)
                ;
            delete tail;
            tail = temp;
            tail->next = 0;
        }

        return value;
    }

    void DeleteNode(int val)
    {
        if (head != 0)
        {
            if (head == tail && val == head->info)   //first node delete with no other nodes
            {
                delete head;
                head = tail = 0;
            }
            else if (val == head->info)   //first node delete with other existing nodes
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                Node *pred, *temp;
                for (pred = head, temp = head->next;
                     temp != 0 && !(temp->info == val);
                     pred = pred->next, temp = temp->next)
                    ;
                if (temp != 0)
                {
                    pred->next = temp->next;

                    if (temp == tail)
                        tail = pred;

                    delete temp;
                }
            }
        }
        else
        {
            cout << "\nlist is Empty...!" << endl;
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
            Node *temp;
            cout << endl;
            for (temp = head; temp != 0; temp = temp->next)
                cout << temp->info << "\t";
        }
    }
    
    
    

    void ReverseList()
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
           AddToTail(node->info);
        }
    }
    
    bool palindromecheck(){
    	
     Node* slow = head;
     Node* fast = head;
     
     
     while(fast!= 0 && fast->next != 0){
     	
     	slow = slow->next;   //slow will store our middle value
     	fast = fast->next->next;
	 }
    
     Node* prev =0;
	 Node* forward;
	 Node* cur = slow;
	 
	 while(cur != 0){
	 	forward = cur->next;
	 	cur->next = prev;
	 	prev = cur;
	 	cur = forward;
	 }        
		
		fast = head;
		
		while(fast!= 0 ){
			if(fast->info != prev->info){
				return false;
			}
			else{
				fast = fast->next;
				prev = prev->next;
			}
		}	 
			 	
	
	}
	
	void samenodes(){
		
		Node* temp =head;
		Node* a = temp;
		
	
		
		if(temp->info == a->next->info){
			
			cout<<temp->info<<" is dublicate in list "<<endl;
			 a = a->next;
		}
		
		else{
			
		  a = a->next;
		}

   
	}
		
    
   

    bool ValueExist(int val) const
    {
        Node *temp;
        for (temp = head; temp != 0 && !(temp->info == val); temp = temp->next)
            ;

        return temp != 0;
    }
    
    

    ~SingleLinkList()
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
    SingleLinkList list,list2;
   
    list.AddToTail(1);
	list.AddToTail(2);
	list.AddToTail(3);
	list.AddToTail(2);
	list.AddToTail(1);

  list.samenodes();

  // list.DeleteFromTail();

//   cout<<endl<<list.palindromecheck();
//    list.PrintList();
//
//    list.AddAfter(1, 12);
//    list.AddAfter(7, 9);
//
//    list.PrintList();
//    cout << endl
//         << "REVERSE is belwo" << endl;
//
///    list.ReverseList();
//
   list.PrintList();
    return 0;
}
