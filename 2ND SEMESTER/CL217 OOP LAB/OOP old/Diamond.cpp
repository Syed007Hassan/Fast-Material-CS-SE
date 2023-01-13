#include<iostream>

using namespace std;

class LT
{
	public:
		breathe()
		{
			cout<<"LT is breathing"<<endl;
		}
};

class Animal : virtual public LT
{
	public:
//		breathe()
//		{
//			cout<<"Animal is breahing"<<endl;	
//		}	
	
};

class Reptile : virtual public LT
{
	public:
//		breathe()
//		{
//			cout<<"Reptile is breahing"<<endl;	
//		}	
	
		crawl()
		{
			cout<<"Reptile is crawling"<<endl;	
		}	
};


class Snake : public Animal, public Reptile
{

};

main()
{
	Snake s;
	s.breathe();		
}
