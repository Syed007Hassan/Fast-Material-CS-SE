#include<iostream>

using namespace std;

int main()
{
	int i,j,k;
	float gpa,creditH;
	
	int size[2];
	float **p= new float*[2];
	
	for(i=0;i<2;i++)
	{
		cout << "Enter total number of sujects of student "<<i+1<<" : ";
		cin >> size[i];
		p[i]= new float[size[i]];
	}
	for(i=0;i<2;i++)
	{
		cout << "Enter Student "<<i+1<<" GPA\n";
		for(j=0;j<size[i];j++)
		{
			cout << "Course "<<j+1<<" GPA : ";
			cin >> p[i][j];
		}
	}
	
	for(i=0;i<2;i++)
	{
		gpa=0;
		creditH=0;
		for(j=0;j<size[i];j++)
		{
			gpa=p[i][j]*3+gpa;
			creditH=creditH+3;
			
		}
		cout << "Student "<<i+1<< " Semester GPA = "<< (gpa/creditH)<<endl;
		
	}
	
}
