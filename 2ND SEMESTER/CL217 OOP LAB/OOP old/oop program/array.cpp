#include<iostream>
using namespace std;
template <typename A>
class item{
	public;
void add(A &a,A &b)
{
	cout<<"Enter element to be insert : ";
	cin>>insert;
	cout<<"At which position (Enter index number) ? ";
	cin>>pos;
	// now create a space at the required position
	for(i=size; i>pos; i--)
	{
		arr[i]=arr[i-1];
	}
	arr[pos]=insert;
	cout<<"Element inserted successfully..!!\n";
	cout<<"Now the new array is : \n";
	for(i=0; i<size+1; i++)
	{
		cout<<arr[i]<<" ";
	}
}
};
main()
{
	
	int i;
	int n;
	int x;
	cout<<"enter no of element:"<<endl;
	cin>>n;
	string a[n];
	cout<<"enter element:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"set updated!"<<endl;
	cout<<"which funcion you want to perform:";
	cout<<"\n1.add element in set";
	cout<<"\n2.remove element";
	cout<<"\n3.return no of item ";
	cout<<"\n4.determine element in array";
	cin>>x;
	switch(x)
	{
		case 1:
			{
				
			}
	}
}
