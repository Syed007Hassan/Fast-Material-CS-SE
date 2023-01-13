#include<iostream>

using namespace std;

int count(int *pt,int key,int size,int start,int countt)
{

	if(size == 0)
	{
		return countt;
	}
	else
	{
		if(pt[start]==key)
		{
			countt++;
			return count(pt,key,size-1,start+1,countt);
		}
		else
		{
			return count(pt,key,size-1,start+1,countt);
		}
	}
}

int main()
{
	int size,i,*p;
	
	cout << "Enter size of array : ";
	cin >> size;
	
	p = new int [size];
	cout << "Enter elements : ";
	for(i=0;i<size;i++)
	{
		cin >> p[i];
	}
	int key;
	cout << "Enter element to search : ";
	cin >> key;
	int check=0;
	cout << "The "<<key<<" occurs "<<count(p,key,size,0,check)<< " time(s)"; 
}
