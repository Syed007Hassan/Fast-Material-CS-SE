#include<iostream>
#include<vector>

using namespace std;

#define rows 5
#define column 5
int main()
{
	int *ptr = new int [rows*column] {
										false,true,false,true,true,
										true,false,true,false,true,
										false,true,false,false,false,
										true,false,false,false,true,
										true,true,false,true,false,
									};
									
	int i,j,commanfriend=0,Row,Column,size;
	vector<int> v;
	
	
	
	
	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<column;j++)
		{
			cout << *(ptr+i *column+j) << " ";
		}
		cout<<endl;
	}
	cout << "Enter Row index : ";
	cin >> Row;
	cout << "Enter Column Index : ";
	cin >> Column;
	
	for(i=Row;i<=Row;i++)
	{
		for(j=0;j<column;j++)
		{
			if(*(ptr+i *column+j)==true)
			{
				if(*(ptr+j *column+Column)== true)
				{
					v.push_back(j);
				}
			}
		}
		
	}
	size=v.size();
	if(v.empty()== true)
	{
		cout << "No Comman Friend";
	}
	else
	{
		cout << "Comman Friends : ";
		for(i=0;i<size;i++)
		{
			cout << v[i]<<" ";
		}
	}

}
