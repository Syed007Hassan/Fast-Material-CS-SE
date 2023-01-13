#include<iostream>

using namespace std;

int hash(int key)
{
	return key%10;
}
int mid_square_hash(int key)
{
	int value = key*key;
	//int middle_value= middle_value(value);
	//Return middle_value;
}
int radix_hash(int value)
{
//	int result= base _number(value)
//	return result;
// return last4 digit of result;
}
void insert(int HT[],int key)
{
	int index=hash(key);
	
	if(HT[index]!=0)
	{
		cout << "Element Present Already "<<key<< " Not inserted\n";
		return;
	}
	HT[index]=key;
}
bool search(int HT[],int key)
{
	int index=hash(key);
	
	if(HT[index]==key)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Delete(int HT[],int key)
{
	int index=hash(key);
	if(HT[index]==key)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int HT[10]={0};
	insert(HT,12);
	insert(HT,35);
	insert(HT,25);
	insert(HT,26);
	
	for(int i=0;i<10;i++)
	{
		cout << HT[i]<<"  ";
	}
	cout <<endl;
	cout << search(HT,26);
	cout <<endl;
	cout << Delete(HT,25);
	
}
