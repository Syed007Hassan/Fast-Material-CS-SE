#include<iostream>

using namespace std;

class Node
{
	public:
		int coeff;
		char var;
		int pow;
		Node *next;
	Node(int coeff,char var,int pow)
	{
		this->coeff=coeff;
		this->var=var;
		this->pow=pow;
		next=NULL;
	}	
};
class PolynomialList
{
	Node *head,*tail;
	int count;
	
	
	public:
		PolynomialList()
		{
			head=NULL;
			tail=NULL;
			count=0;
		}
		
		void input(int co,char va,int po)
		{
			if(head==NULL&&tail==NULL)
			{
				head=tail=new Node(co,va,po);
				count++;
			}	
			else
			{
				tail->next=new Node(co,va,po);
				tail=tail->next;
				count++;
			}
		}
		Node* gethead()
		{
			return head;
		}
		
		void print()
		{
			Node *temp;
			
			cout << count <<endl;
			for(temp=head;temp!=NULL;temp=temp->next)
			{
				cout << temp->coeff<<" "<<temp->var<<" "<<temp->pow<<endl;
			}
			cout << endl;
		}
		void sort()
		{
			int tempCo,tempPo;
			char tempVar;
			Node *temp1,*temp2;
			
			for(temp1=head;temp1!=0;temp1=temp1->next)
			{
				for(temp2=head;temp2!=tail;temp2=temp2->next)
				{
					if(temp2->pow>temp2->next->pow)
					{
						tempCo=temp2->coeff;
						temp2->coeff=temp2->next->coeff;
						temp2->next->coeff=tempCo;
						
						tempVar=temp2->var;
						temp2->var=temp2->next->var;
						temp2->next->var=tempVar;
						
						tempPo=temp2->pow;
						temp2->pow=temp2->next->pow;
						temp2->next->pow=tempPo;			
					}
				}
			}	
		}
		void sortvar()
		{
			int tempCo,tempPo;
			char tempVar;
			Node *temp1,*temp2;
			
			for(temp1=head;temp1!=0;temp1=temp1->next)
			{
				for(temp2=head;temp2!=tail;temp2=temp2->next)
				{
					if(temp2->var>temp2->next->var)
					{
						tempCo=temp2->coeff;
						temp2->coeff=temp2->next->coeff;
						temp2->next->coeff=tempCo;
						
						tempVar=temp2->var;
						temp2->var=temp2->next->var;
						temp2->next->var=tempVar;
						
						tempPo=temp2->pow;
						temp2->pow=temp2->next->pow;
						temp2->next->pow=tempPo;			
					}
				}
			}	
		}
		
};
void addpolynomialEq(PolynomialList &ob1,PolynomialList &ob2,PolynomialList &final)
{
	Node *temp1,*temp2;
	temp1=ob1.gethead();
	temp2=ob2.gethead();
	int add;
	
	while(temp1!=NULL&&temp2!=NULL)
	{
		if(temp1->var==temp2->var&&temp1->pow==temp2->pow)
		{
			
			add=temp1->coeff+temp2->coeff;
			final.input(add,temp1->var,temp1->pow);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->pow<temp2->pow)
		{
			
			final.input(temp2->coeff,temp2->var,temp2->pow);
			temp2=temp2->next;
		}
		else
		{	
			
			final.input(temp1->coeff,temp1->var,temp1->pow);
			temp1=temp1->next;
		}
	}
	if(temp1==NULL)
	{
		while(temp2!=NULL)
		{
		
			final.input(temp2->coeff,temp2->var,temp2->pow);
			temp2=temp2->next;
		}
	}
	else
	{
		while(temp1!=NULL)
		{
			
			final.input(temp1->coeff,temp1->var,temp1->pow);
			temp1=temp1->next;
		}
	}
	
}
int main()
{
	int num1,num2;
	int co;char var;int po;
	PolynomialList l1,l2,final;
	cin >> num1;
	for(int i=0;i<num1;i++)
	{
		cin >> co;
		cin >> var;
		cin >> po;
		l1.input(co,var,po);
	}
	cin >> num2;
	for(int i=0;i<num2;i++)
	{
		cin >> co;
		cin >> var;
		cin >> po;
		l2.input(co,var,po);
	}
	
	addpolynomialEq(l1,l2,final);
	final.sort();
	final.sortvar();
	final.print();
	
}
