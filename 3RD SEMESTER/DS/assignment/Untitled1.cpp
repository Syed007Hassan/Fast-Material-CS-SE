#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
	public:
		node(){
		};
		node *next;
		char charval;
		int coeffval;
		int charpow;
		node(char v,int c,int e,node *ptr=NULL){
			charval=v;coeffval=c;charpow=e;next=ptr;
		}
};
class singlelist{
	public:
		node *head;
		int co;
		int exp;
		int checker;
		char var;
		singlelist(){
			checker=0;head=NULL;
		}
		void swapfunc(node *f1,node *f2){
	
	int swapped;
	swap(f1->charpow,f2->charpow);
	swap(f1->coeffval,f2->coeffval);
	swap(f1->charval,f2->charval);}	
	
		void travres()
		{
		node *t2=head->next;
		node *t1=head;
	for(t1=head;t1->next!=NULL;t1=t1->next)
	{
	for(t2=t1->next;t2!=NULL;t2=t2->next)
	{
     if(t1->charpow > t2->charpow )swapfunc(t1,t2);
    }
    }

}
 		void travress()
		{
		node *t2=head->next;
		node *t1=head;
	for(t1=head;t1->next!=NULL;t1=t1->next)
	{
	for(t2=t1->next;t2!=NULL;t2=t2->next)
	{
     if(t1->charval > t2->charval)swapfunc(t1,t2);
    }
    }
	t1=head;

		do{
			cout<<t1->coeffval<<" "<<t1->charval<<" "<<t1->charpow<<endl;
			t1=t1->next;
		}while(t1!=NULL);
}

	
		void input(){cin>>co>>var>>exp;
			node *n=new node(var,co,exp);
			node *tptr=head;
			if(head==NULL)
			{
				head=n;
				n->next=NULL;
			}
			else
			{
				while(tptr->next!=NULL)
				{
					tptr=tptr->next;
				}
				tptr->next=n;n->next=NULL;}
		}
		
	void addsll(singlelist &sll1,singlelist &sll2)
	{
		node *tptr2=sll2.head;
		node *tptr1=sll1.head;
		while(tptr1!=NULL)
		{
			do{
				if((tptr2->charpow==tptr1->charpow)&&(tptr2->charval==tptr1->charval))
				{	resultinsert((tptr1->coeffval + tptr2->coeffval),tptr1->charval,tptr1->charpow,checker);
					tptr1->coeffval=-1;
					tptr2->coeffval=-1;
					checker++;}	
				tptr2=tptr2->next;
			}while(tptr2!=NULL);
			tptr1=tptr1->next;tptr2=sll2.head;
		}tptr1=sll1.head;
		do
		{
			if(tptr1->coeffval > -1)
				resultinsert(tptr1->coeffval,tptr1->charval,tptr1->charpow,checker++);
			tptr1=tptr1->next;
		}	while(tptr1!=NULL);
		tptr2=sll2.head;
		while(tptr2!=NULL){
			if(tptr2->coeffval>-1)
				resultinsert(tptr2->coeffval,tptr2->charval,tptr2->charpow,++checker);
			tptr2=tptr2->next;
		}
		cout<<checker<<endl;
		travres();
		travress();
		}
		void genrus()
		{
			//	if((n1->charpow>n2->charpow)&&(n1->charval==n2->charval))
		//	cout<<n1->charpow>n2->charpow<<endl<<n1->charval==n2->charval<<endl;
		}
		void resultinsert(int c,char v,int e,int nn){node *n=new node(v,c,e);
			node *tptr=head;
			//nn=0
			if(head==NULL)
			{head=n;
				n->next=NULL;//nn++
					}
			
			else
			{//nn--
				while(tptr->next!=NULL)
					tptr=tptr->next;
				tptr->next=n;
				n->next=NULL;}
		}
	 };
int main(){
	int a;
		cin>>a;
	int b;
	singlelist sl1;
	for(int i=0;i<a;i++)
		sl1.input();
	cin>>b;
	singlelist sl2;
	for(int i=0;i<b;i++)
		sl2.input();
	singlelist sl3;
	sl3.addsll(sl1,sl2);
	return 0;
}
