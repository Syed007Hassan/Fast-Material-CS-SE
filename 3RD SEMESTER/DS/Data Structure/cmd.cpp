#include<iostream>
#include<fstream>

using namespace std;

int main(int arg, char *arr[])
{
    ofstream o;
    ifstream i;
    char ch;

    i.open(arr[1],ios::in);
    o.open(arr[2],ios::out);

    if(i.is_open()&&o.is_open())
    {
        cout<< "Success in opening in the files";

        while(!i.eof())
        {
            i.get(ch);
            if(i.eof())
            {
                break;
            }
            o << ch;
        }
    }
    i.close();
    o.close();
    // remove("old.txt");
    // rename("new.txt","old.txt");
    
}
