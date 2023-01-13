#include<iostream>

using namespace std;

int hash(int key)
{
	return key%10;
}
int probe(int HT[],int key)
{
	int i=0;
	int index=hash(key);
	while(HT[(index+i)%10]!=0)
	{
		i++;
	}
	return (index+i)%10;
}
void insert(int HT[],int key)
{
	int index=hash(key);
	
	
	if(HT[index]!=0)
	{
		index=probe(HT,key);
	}
	HT[index]=key;
}
int search(int HT[],int key)
{
	int index=hash(key);
	int i=0;
	while(HT[(index+i)%10]!=key)
	{
		if(HT[(index+i)%10]==0)
		{
			return -1;
		}
		i++;
	}
	return (index+i)%10;
}
bool Delete(int HT[],int key)
{
	int index=hash(key);
	int i=0;
	while(HT[(index+i)%10]!=key)
	{
		if(HT[(index+i)%10]==0)
		{
			return -1;
		}
		i++;
	}
	if((HT[(index+i)%10])==key)
	{
		HT[(index+i)%10]=0;
		return 1;
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
	
	if(search(HT,26)==-1)
	{
		cout << "Key Not Present\n";
	}
	else
	{
		cout << "Key Present\n";
	}
	if(Delete(HT,35)==1)
	{
		cout << "Key Deleted\n";
	}
	else
	{
		cout << "Key Not Present\n";
	}
	
	for(int i=0;i<10;i++)
	{
		cout << HT[i]<<"  ";
	}
}
