#include<iostream>
using namespace std;
class vector
{
	int x;
	int y;
	int z;
	public:
		vector()
		{
		}
		vector(int x,int y,int z)
		{
			this->x=x;
			this->y=y;
			this->z=z;
		}
		int getx()
		{
			return x;
		}
		int gety()
		{
			return y;
		}
		int getz()
		{
			return z;
		}
		vector operator+(vector v)
		{
			vector a;
			a.x=x+v.x;
			a.y=y+v.y;
			a.z=z+v.z;
			return a;
		}
		
};
int main()
{
	
	int x,y,z;
	cout<<"vector 1\nenter x compnent:";
	cin>>x;
	cout<<"\nenter y component:";
	cin>>y;
	cout<<"\nenter z component:";
	cin>>z;
	vector v1(x,y,z);
	cout<<"vector 2\nenter x compnent:";
	cin>>x;
	cout<<"\nenter y component:";
	cin>>y;
	cout<<"\nenter z component:";
	cin>>z;
	vector v2(x,y,z);
	vector v3;
	v3=v1+v2;
	 cout<<"\n after adding two vector:";
	 cout<<"\nX COMPONENT:"<<v3.getx();
	cout<<"\nY COMPONENT:"<<v3.gety();
	cout<<"\nZ COMPONENT:"<<v3.getz();
}

