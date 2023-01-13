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
        head = new Node(value, head);  //newly created head
        if (tail == 0)                //previously no node was there
        {
            tail = head;              //due to which head tail becomes head 
        }
    }

    void AddAfter(int info, int val )
    {
        if (isEmpty())          //previously no node was there
        {
            AddToHead(val);
        }
        else if (head->info == info)   //if passed info is equals to the info present in head 
        {
            Node *temp = new Node(val);  //newly temporary node is created
            temp->next = head->next;     //storing head->next to temp then linking it to head again.
            head->next = temp;
        }
        else
        {   //when the node's value doesnot matches, linked it yo last node
            Node *temp;
            for (temp = head; temp != 0 && !(temp->info == info); temp = temp->next)
                ; //starting the temp from head, checking unless temp is Null or temp->info equals to
                  //passed info, then moves traverse temp 
            if (temp != 0)
            {
                Node *n = new Node(val); //newly node created
                n->next = temp->next;  //n of next pointing tem;p of next
                temp->next = n;        //then temp of nxt is n
            }
            else
            {
                AddToTail(val);   //adding it to tail
            }
        }
    }

    void AddToTail(int value)
    {
        if (tail != 0)    //check whether tail is NUll
        {
            tail->next = new Node(value);  //adding it to tail of next
            tail = tail->next;             //moving the tail to next
        }
        else
        {
            head = tail = new Node(value);   //if tail is Null means no node was there
        }
    }

    int DeleteFromHead()
    {
        int val = head->info;    //storing value into 	Val

        Node *temp = head;       //pointing temp to head

        // Only One Item in the List
        if (head == tail)
        {
            head = tail = 0;
        }
        else
        {
            head = head->next;   //moving the head to next
        }

        delete temp;
        return val;
    }

    int DeleteFromTail()
    {
        int value = tail->info;
        // Only One Item in the List
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
            tail->next = 0;  //pointing the previous node to Null
        }

        return value;
    }

    void DeleteNode(int val)
    {
        if (head != 0)   
        {
            if (head == tail && val == head->info)  //if only one node is there
            {
                delete head;
                head = tail = 0;
            }
            else if (val == head->info)
            {
                Node *temp = head;  //temp node created
                head = head->next;   //moving head to further next
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
            for (temp = head; temp != NULL; temp = temp->next)
                cout << temp->info << "\t";
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
    SingleLinkList list;
    list.AddToHead(1);
    list.AddToHead(2);
    list.AddToHead(3);
    list.AddToHead(4);
    list.AddToHead(5);
    list.AddToHead(6);
    list.AddToHead(7);
  
//   list.AddAfter(8, 12); //since 8 is not present so 12 will be added at last to tail
   list.AddAfter(6, 12); //since 6 is present so 12 will be added after 6

    list.PrintList();
    cout<<endl;
    
    cout<<list.ValueExist(12)<<endl;

 
//  //  list.AddAfter(7, 9);
//
//    list.PrintList();
//
//    list.DeleteFromHead();
//    list.DeleteFromTail();
//    list.PrintList();
//
//    list.DeleteNode(9);
//    list.DeleteNode(12);
//    list.PrintList();
    return 0;
}
