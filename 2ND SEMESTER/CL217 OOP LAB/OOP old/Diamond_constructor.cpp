#include<iostream>

using namespace std;

class LT
{
	int x;
	
	public:
		
		LT()
		{
			
		}
		
		LT (int i)
		{
			cout<<"LT"<<endl;
			x = i;
		}
		
		breathe()
		{
			cout<<"LT is breathing"<<endl;
		}
};

class Animal : virtual public LT
{	
	public:
		
		Animal()
		{
			
		}
		
		Animal(int x) : LT (x)
		{
			cout<<"Animal"<<endl;
		}
		
//		breathe()
//		{
//			cout<<"Animal is breahing"<<endl;	
//		}	
	
};

class Reptile : virtual public LT
{
	public:
		
		Reptile()
		{
			
		}
		
		Reptile(int x) : LT (x)
		{
			cout<<"Reptile"<<endl;
		}
		
		breathe()
		{
			cout<<"Reptile is breahing"<<endl;	
		}	
	
		crawl()
		{
			cout<<"Reptile is crawling"<<endl;	
		}	
};


class Snake : public Animal, public Reptile
{
		public:
		
		Snake();
		
		Snake(int x) : Animal(x) , Reptile(x), LT(x)
		{
			cout<<"Snake"<<endl;
		}
		
};

main()
{
	Snake s(1);
	//s.breathe();		
}
