#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int *p=new int[11] {3,1,1,3,4,5,1,3,8,9,3};
	vector<int>v;
	int duplicate=-9999;
	
	for(int i=0;i<11;i++)
	{
		int check=p[i];
		int counter=0;
		for(int j=0;j<11;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(check==p[j])
			{	
				p[j]=duplicate;
				
				
				duplicate--;
				counter++;
			}
		}
		if(counter!=0)
		{
			v.push_back(check);
		}
	}
	
	cout << "Repeating Elements : ";
	for(int i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
