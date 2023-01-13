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
        prev=0;
    }

    Node(int value, Node *ptr = 0)
    {
        info = value;
        next = ptr;
        prev=0;
    }
};

class CircularLL {
	private:
    Node *head;

public:
    CircularLL()
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
            head->prev=head;
        }
        else
        {
            Node *temp = head;

            while (temp->next != head){
			
                temp = temp->next;
         }  
            temp->next = newNode;
            newNode->prev=temp;
            newNode->next = head;
            head->prev=newNode;
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
                temp->next->prev=newNode;
                temp->next = newNode;
                newNode->prev=temp;
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
            head->prev=head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev=temp;
            newNode->next = head;
            head->prev=newNode;
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
                cout << temp->info << " ";
                temp = temp->next;

            } while (temp != head);
            
		
        }
    }
    
    int isEmpty() {
    	return head==0;
	}
	
	void cont() {
		Node *temp=head;
		cout << head->next;
		
		while(1) {
			cout << temp->next->info;
			cout << temp->next->next->info;
			cout << temp->next->next->next->info;
			temp=temp->next;
		}
	}

};

int main() {
	CircularLL list;
	int num,n;
	
	
	list.AddToHead(5);
		list.AddToHead(8);
	
	list.PrintList();
	
//	cout << "Enter the number of elements: ";
//	cin >> num;
//	
//	for(int i=0;i<num;i++) {
//		cout << "Enter number " << i+1 << ": ";
//		cin>> n;
//		list.AddToTail(n);
//	}
//	list.PrintList();
//	list.cont();
}
