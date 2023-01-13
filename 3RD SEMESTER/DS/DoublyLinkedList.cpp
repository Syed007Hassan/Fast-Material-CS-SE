#include <iostream>

using namespace std;

class Node
{
public:
    int info;
    Node *next, *prev;

    Node()
    {
        next = 0;
        prev = 0;
    }

    Node(int value, Node *ptr = 0)
    {
        info = value;
        next = ptr;
        prev = 0;
    }
};

class DoublyLinkedList
{
private:
    Node *head, *tail;

public:
    DoublyLinkedList()
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
        if (isEmpty())
        {
            AddToHead(val);
        }
        else if (head->info == info)
        {
            Node *temp = new Node(val);
            temp->next = head->next;
            temp->prev = head;
            head->next->prev = temp;
            head->next = temp;
        }
        else
        {
            Node *temp;
            for (temp = head; temp != 0 && !(temp->info == info); temp = temp->next)
                ;
            if (temp != 0)
            {
                Node *node = new Node(val);
                node->next = temp->next;
                node->prev = temp;
                temp->next->prev = node;
                temp->next = node;
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
            Node *temp = new Node(value);
            tail->next = temp;
            temp->prev = tail;
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
            head = tail = 0;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
        return val;
    }

    int DeleteFromTail()
    {
        int value = tail->info;
        Node* temp = tail;
        if (head == tail)
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            tail = tail->prev;
            tail->next = 0;
        }
         delete temp;
        return value;
    }

    void DeleteNode(int val)
    {
        if (head != 0)
        {
            if (head == tail && val == head->info)
            {
                delete head;
                head = tail = 0;
            }
            else if (val == head->info)
            {
                Node *temp = head;
                head = head->next;
                head->prev = 0;
                delete temp;
            }
            else
            {
                Node *pred, *temp;
                for (temp = head; temp != 0 && !(temp->info == val); temp = temp->next)
                    ;
                if (temp != 0)
                {
                    temp->prev->next = temp->next; 
                    temp->next->prev = temp->prev;
                    if (temp == tail)
                        tail = pred;
                    delete temp;
                }
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
            Node *temp;
            cout << endl;
            for (temp = head; temp != 0; temp = temp->next)
                cout << temp->info << "\t";
        }
    }

    void ReversePrint()
    {
        if (isEmpty())
        {
            cout << "List is Empty..." << endl;
        }
        else
        {
            Node *temp;
            cout << endl;
            for (temp = tail; temp != 0; temp = temp->prev)
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

    ~DoublyLinkedList()
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
    DoublyLinkedList list;
    list.AddToHead(5);
//      list.AddToHead(6);
//        list.AddToHead(7);
//    list.AddToTail(4);

   list.AddAfter(6, 10);
     list.AddAfter(10, 8);
    

    list.PrintList();
//    list.ReversePrint();
//    list.AddAfter(2, 5);
//
//    list.AddAfter(5, 7);
//
//    list.AddAfter(1, 9);
//
//    list.AddAfter(11, 13);
//
//    list.PrintList();
//    list.ReversePrint();
//    list.DeleteFromHead();
//
//    list.PrintList();
//
//   list.DeleteFromTail();
//
 //  list.PrintList();
//
//    list.DeleteNode(2);
//    list.PrintList();
//    list.ReversePrint();

    return 0;
}
