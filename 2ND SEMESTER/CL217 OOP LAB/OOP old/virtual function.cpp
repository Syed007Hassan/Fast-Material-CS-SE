#include<iostream>

using namespace std;

class weapon
{
	
	public:
		virtual load()
		{
			cout<<"weapon loading"<<endl;
		}
};

class gun : public weapon
{
	public:
		load()
		{
			weapon::load();
			cout<<"gun loading"<<endl;
		}
};

class bomb : public weapon
{
	public:
		load()
		{
			weapon::load();
			cout<<"bomb loading"<<endl;
		}
};

class knife : public weapon
{
//	load()
//	{
//		//weapon::load();
//		cout<<"knife is loading"<<endl;
//	}
};

class loader
{

public:
     void loadFeatures(weapon *weapon)
     {
        weapon->load();
     } 
};

int main()
{
	//compile time polymorphism
	bomb b;
	gun g;
	b.load();
	g.load();

//runtime polymorphism
//	weapon *w = new weapon;
//	loader *l = new loader;
//	
//	bomb b; //bomb loading
//	gun g; //gun loading
//	knife k; //knife loading
//	
//	w = &g;
	
//	w->load();
	
	
//	l->loadFeatures(w);	
//
//	w = &b;
//	l->loadFeatures(w);
//	w->load();
	
//	w = &k;
//	w->load();
	
	
//	
//	w = &k;
//	l->loadFeatures(w);
	





//	weapon *w = new weapon;
//	//bomb *b = new bomb;
//	//gun *g = new gun;
//	loader *l = new loader;
	
//	w->load();
//	b->load();
//	g->load();

//	gun g;
//	bomb b;
//	knife k;
//	
//	g.load();
//	b.load();
//	k.load();
	
	


}
