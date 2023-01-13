#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	int i,number,sum=0,sizeOfVector;
	
	
	while(1)
	{
		cout << "Enter Number: ";
		cin >> number;
		if(number==-1)
		{
			exit(1);
		}
		else
		{
			for(i=1; i<=number;i++)
			{
				if((number%i)==0)
				{
					v.push_back((i));
				}
			}
			sizeOfVector=v.size();
			cout << "The Factors of "<<number<<" are : ";
			for(i=0; i<sizeOfVector; i++)
			{
				cout << v[i]<<" ";
				sum=sum+v[i];
			}
			cout << "\nThe sum of factors = "<<sum<<endl;
			
		}
	}
	
	
	
}
