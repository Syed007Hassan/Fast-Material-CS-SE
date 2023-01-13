#include<iostream>
using namespace std;
class fruit{
	int nooffruit;
	public:
		int calfruit(int a,int m)
		{
			nooffruit=a+m;
		}
		int getnooffruit()
		{
			return nooffruit;
		}
		
};
class applee:public fruit
{
	public:
	void disapple(int a)
	{
		cout<<"\n total apples:"<<a;
	}
};
class mangoo:public fruit
{
	public:
	void dismango(int m)
	{
		cout<<"\n total mangoes:"<<m;
	}
};
int main()
{
	fruit f;
	int app;
	int man;
	cout<<"\nenter no of apple:";
	cin>>app;
	cout<<"\nenter no of mango:";
	cin>> man;
	f.calfruit(app,man);
	cout<<"\ntotal noof fruit :"<<f.getnooffruit();
	mangoo mm;
	applee a;
	 mm.dismango(man);
	 a.disapple(app);
}
