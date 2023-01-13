#include<iostream>
using namespace std;
 
 class movie{
 	string moviename;
 	int MPArating;
 	int terrible;
 	int bad;
 	int good;
 	int ok;
 	int great;
 	float sum=0.0;
 	public:
 		movie()
		 {
		 	terrible=0;
		 	bad=0;
		 	good=0;
		 	ok=0;
		 	great=0;
		 	
		 }
		 
 		int addrating()
		 {
		 	int x;
		 	cout<<"\nhow much do u rate this movie out of 5:";
		 	 for(int i=1;i<=5;i++)
		 	 {
		 	 	cout<<"\ncustomer "<<i<<":";

		 	
		 	cin>>x;
		 	if(x<1||x>5)
		 	{
		 		cout<<"\ninvalid rating!!\n";
		addrating();
			 }
			 else{
			 	if(x==1)
			 	{terrible++;
	
				 }
				 else if(x==2)
				 {bad++;
				 }
				 else if(x==3)
				 {ok++;
				 
				 }
				 else if(x==4)
				 {good++;
				
				 }
				 else if(x==5)
				{great++;
		
				 } 
				 sum+=x;
			 }
 			
		 }}
		 void getaverage()
		 {
		 	float avg;
		 //	avg=(bad+terrible+good+great+ok);
		 	avg=sum/5.0;
		 	
		 	cout<<"\n\naverage rating of this movie is:"<<avg;
		 }
		 
 };
 int main()
 {
 	movie m1, m2;
 	cout<<"\n1st movie\n";
 	m1.addrating();
 	m1.getaverage();
 	
 	
 	cout<<"\n2nd movie\n";
 	m2.addrating();
 	m2.getaverage();
 }
