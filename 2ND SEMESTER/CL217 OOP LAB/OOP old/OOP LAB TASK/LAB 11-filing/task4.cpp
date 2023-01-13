#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class participant
{
	int ID;
	string name;
	double score;
	public:
		void input()
		{
			cout<<"\nenter participant detail:";
			cout<<"\nenter ID:";
			cin>>ID;
			cout<<"\nenter name:";
			cin>>name;
			cout<<"\nenter score:";
			cin>>score;
		}
		void output()
		{
			cout<<"\nParticipant detail:";
			cout<<"\nNAME:"<<name;
			cout<<"\nID:"<<ID;
			cout<<"\nSCORE:"<<score;
		}		
		
};
int main()
{
	participant p;
	fstream f;
	f.open("participant.txt",ios::out|ios::binary|ios::in);
	if(f)
	{
		cout<<"file opened!";
		p.input();
		if(f.write((char*)&p,sizeof(p)))
	
	f.close();
	}
	else{
		cout<<"file didnt open";
	}
	f.open("participant.txt",ios::out|ios::binary|ios::in);
	if(f)
	{
		if(f.read((char*)&p,sizeof(p)))
	{
		cout<<"\n\ndata extracted from file :\n";
		p.output();
	}
	
        	f.close();
	}
	else
	{
		cout<<"file didnt open!";
	}
}
