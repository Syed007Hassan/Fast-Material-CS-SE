#include<iostream>
#include<stdlib.h>
using namespace std;
#define TABLE_SIZE 10
class HashNode
{
    public:
    int key;
    string value;
    HashNode* next;
    HashNode(int key, string value, HashNode* ptr = NULL)
    {
        this->key = key;
        this->value = value;
        this->next = ptr;
    }
};
class HashMap
{
    private:
    HashNode** htable, *c;

    public:
    HashMap()
    {
        htable = new HashNode*[TABLE_SIZE];

        for (int i = 0; i < TABLE_SIZE; i++)
        htable[i] = NULL;
    }
    void insert()
    {
        int i, key;
        string value;
        cout << "Enter a value to insert to hashTable: " << endl;
        cin >> key;
        fflush(stdin);
        cout << "Enter the contact number";
        cin >> value;
        
        i = key % TABLE_SIZE;
        HashNode* newnode = new HashNode(key, value);
        if(htable[i] = NULL)
        {
            htable[i] = newnode;
        }
        else{

            c = htable[i];
            while(c->next != NULL)
            {
                c = c->next;
            }
            c->next = newnode;
        }
    }

    void search()
    {
        int key, index;
        cout <<"\nEnter the element to be search: ";
        cin >> key;
        index = key % TABLE_SIZE;
        if(htable[index] == NULL)
        {
            cout << "\nElement not found.";
        }
        else{

            for(c = htable[index]; c != NULL; c = c->next)
            {
                if(c->key == key)
                {
                   cout << "\nSearch element is found at position " << key;
                   break; 
                }
            }
            if(c == NULL)
            {
                cout << "\nElement not found.";
            }
        }
    }
    void dsiplay()
    {
        for(int i = 0; i< TABLE_SIZE; i++)
        {
            cout << "\n";
            if(htable[i] == NULL)
            {
                continue;
            }
            else{

                for(c = htable[i]; c!=NULL; c = c->next)
                {
                    cout << "\nID: " << c->key << " Contact number: " << c->value;
                }
            }
        }
    }
};
int main()
{
	HashMap h;
	h.insert();
	h.insert();
	h.dsiplay();   
}
