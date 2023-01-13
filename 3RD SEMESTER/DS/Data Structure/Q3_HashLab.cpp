#include<iostream>
#include<list>
#include<string>
using namespace std;

class ContactBook
{
    static const int HashGroups  = 15;
    list<pair<int , string> > table[HashGroups];
    public:
    bool Isempty()
    {
        int sum{};
        for(int i{}; i < HashGroups; i++)
        {
            sum += table[i].size();
        }
        if(!sum)
        {
            return true;

        }
        else 
        return false;
    }
    int HashingF(int key)
    {
        return key % HashGroups;
    }
    void insertion(int key, string value)
    {
        int hashV = HashingF(key);
        auto& cell = table[hashV];
        auto bItr = begin(cell);
        bool  keyExists = false;

        for(; bItr != end(cell); bItr++)
        {
            if(bItr->first == key)
            {
                keyExists = true;
                bItr->second = value;
                cout << "Value already exists. Value replaced." << endl;
                break;


            }
        }
        if(!keyExists)
        {
            cell.emplace_back(key, value);
        }
        return;

    }
    void removeItem(int key)
    {
        int hashV = HashingF(key);
        auto& cell = table[hashV];
        auto bItr = begin(cell);
        bool  keyExists = false;

        for(; bItr != end(cell); bItr++)
        {
            if(bItr->first == key)
            {
                keyExists = true;
                bItr = cell.erase(bItr);
                cout << "Student record removed ." << endl;
                break;
                

            }
        }
        if(!keyExists)
        {
            cout << "Value no found," << endl;
        }
        return;


    }
    void PrintTable()
    {
        for(int i{}; i < HashGroups; i++)
        {
            if(table[i].size() == 0)
            continue;
            auto bItr =table[i].begin();
            for(; bItr != table[i].end(); bItr++)
            {
                cout << "Student ID : " << bItr->first << " Contact Number : " << bItr->second << endl;
             } 
        }

        return;
    }



};

int main()
{
    ContactBook b;
    if(b.Isempty())
    {
        cout << "Contact Book is empty." << endl;
    }
    else{
        cout << "Contact Book is not empty," << endl;

    }
    b.insertion(100, "123");
    b.insertion(120,"241");
    b.insertion(140, "212");
    b.insertion(190, "112");

    b.PrintTable();

    b.removeItem(120);
    b.PrintTable();
}
