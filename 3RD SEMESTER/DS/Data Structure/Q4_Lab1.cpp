#include<iostream>

using namespace std;

int Recursivefunction(int check,int num,int sum);
int main()
{
	int number,start=1,summ=0;
	
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
			cout << "The factors of "<<number<<" are : ";
			cout << Recursivefunction(number,start,summ);
			cout<<"\n";
			
		}
	}	
}
int Recursivefunction(int check,int num,int sum)
{
	if (num > check)
	{
		cout << "\nThe sum of Factors = ";
		return sum;
	}
	else
	{
		if((check%num)==0)
		{
			cout << num<<" ";
			sum=sum+num;
		}
		return Recursivefunction(check,num+1,sum);
	}	
}

