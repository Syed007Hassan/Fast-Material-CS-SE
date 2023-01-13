//Students data project with file stream
#include<fstream>
#include<iostream>
#include<conio.h>
#include<process.h>
#include<stdio.h>
using namespace std;
class Student
{
 int rollno;
 char name[20];
 int Class;
 int marks;
 char grade;
 public:
 void getdata();
 void display();
 int getmarks() {return marks;}
 int getno() {return rollno;}
 int getClass() {return Class;}
}s;

void Student::getdata()
{
 cout<<"Enter Roll No. : ";
 cin>>rollno;
 cout<<"Enter Name     : ";
 cin>>name;
// cin.getline(name,20);
// gets(name);
 cout<<"Enter Class    : ";
 cin>>Class;
 cout<<"Enter Marks    : ";
 cin>>marks;
      if(marks>=75) grade='A';
 else if(marks>=60) grade='B';
 else if(marks>=50) grade='C';
 else if(marks>=35) grade='D';
 else grade='F';
}
void Student::display()
{
 cout<<"=================================================\n";
 cout<<"Roll No. : "<<rollno<<"\tName  : "<<name<<"\n";
 cout<<"Class    : "<<Class <<"\tMarks : "<<marks<<"\tGrade : "<<grade<<"\n";
// cout<<"=================================================\n";
}

//Prototyping of functions for menu
void menu();
void search();
void add();
void displayall();
void Classwise();
void Modify();
void Delete();
void options();
void Trash();
void SizeofFile();
int main()
{
 int n,rno,i;
 fstream fio("stud.dat",ios::in|ios::out|ios::binary);
 system("cls");
 menu();
// fio.close();
 getch();
 return 0;
}

void options()
{
 cout<<"\n\t...MENU OF PROGRAM...\n";
 cout<<"\t0. EXIT....\n";
 cout<<"\t1. Add the record...\n";
 cout<<"\t2. Search the record...\n";
 cout<<"\t3. Display all records...\n";
 cout<<"\t4. Class wise records...\n";
 cout<<"\t5. Modify the Record...\n";
 cout<<"\t6. Delete the Record...\n";
 cout<<"\t7. View Deleted Records...\n";
 cout<<"\t8. View the Size of File...\n";
 cout<<"\nEnter Your Choice  : ";
}

void menu()
{
 int ch;
 options();
 cin>>ch;
 while(ch)
 {
   switch(ch)
   {
  case 1: add(); break;
  case 2: search(); break;
  case 3: displayall(); break;
  case 4: Classwise(); break;
  case 5: Modify(); break;
  case 6: Delete(); break;
  case 7: Trash(); break;
  case 8: SizeofFile(); break;
  default: cout<<"Wrong Input please enter the correct value....";
   }
   system("pause");
   system("cls");
   options();
   cin>>ch;
 }
}

void search()
{
 ifstream fin("stud.dat",ios::in|ios::binary);
 int rno,i=0;
 char found='n';
 cout<<"\nEnter Roll No. to be searched : ";
 cin>>rno;

 while(fin.read((char*)&s,sizeof(s)))
 {
  if(s.getno()==rno)
  {
   s.display();
   found='y';
  }
  i++;
 }
 if(found=='n') cout<<"\nThe Roll No. "<<rno<<" is not in the file...\n";
 fin.close();
}

//For Displaying the all data of the students.
void displayall()
{
 ifstream fin("stud.dat",ios::in|ios::binary|ios::app);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.display();
 }
 fin.close();
// int x=gcount();
// cout<<"\n"<<x<<" Bytes read from file...\n";
}

//For adding the data into the file.
void add()
{
 char ch='y';
 ofstream fout("stud.dat",ios::out|ios::app|ios::binary);
 while(ch=='y'||ch=='Y')
 {
  s.getdata();
  fout.write((char*)&s,sizeof(s));
  cout<<"\nDo you want to add more : ";
  cin>>ch;
 }
 cout<<"\nData Appended and Transferred to file...\n";
 fout.close();
}

void Classwise()
{
 ifstream fin("stud.dat",ios::in|ios::binary);
 int std;
 char found='n';
 cout<<"\nEnter the class to be searched : ";
 cin>>std;

 while(fin.read((char*)&s,sizeof(s)))
 {
  if(s.getClass()==std)
  {
   s.display();
   found='y';
  }
 }
 if(found=='n') cout<<"\nThe Class "<<std<<" is not in the file...\n";
 fin.close();
}

void Modify()
{
 fstream fio("stud.dat",ios::in|ios::out|ios::binary);
 int rno;
 char found='n';
 fio.seekg(0);
 cout<<"\nEnter the Roll No. whose record is to be modified: ";
 cin>>rno;

 while(fio)
// while(fio.read((char*)&s,sizeof(s)))
 {
// fio.read((char*)&s,sizeof(s));
   int loc=fio.tellg();
   fio.read((char*)&s,sizeof(s));
//   fio.read((char*)&s,sizeof(s));
   if(s.getno()==rno)
   {
  s.getdata();
  found='y';
  fio.seekg(loc);
  fio.write((char*)&s,sizeof(s));
  cout<<"\nYour record of Roll No. "<<rno
      <<" has been updated....";
   }
 }
 if(found=='n') cout<<"\nThe Class "<<rno<<" is not in the file...\n";
 fio.close();
}

void Delete()
{
 int rno;
 char found='n';
 fstream fio("stud.dat",ios::in|ios::out|ios::binary|ios::app);
 ofstream fout("temp.dat",ios::out|ios::binary|ios::app);
 ofstream out("trash.dat",ios::out|ios::binary|ios::app);

 cout<<"\nEnter the Roll No. whose record is to be deleted: ";
 cin>>rno;

 while(fio.read((char*)&s,sizeof(s)))
 {
  if(s.getno()==rno)
  {
   out.write((char*)&s,sizeof(s));
   found='y';
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 if(found=='n') cout<<"\nThe Roll No."<<rno<<" is not in the file...\n";
 fio.close();
 fout.close();
 remove("stud.dat");
 rename("temp.dat","stud.dat");
}

void Trash()
{
 ifstream fin("trash.dat",ios::in|ios::binary);
// ofstream fout("stud.dat",ios::out|ios::binary|ios::app);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.display();
//  fout.write((char*)&s,sizeof(s));
 }
 fin.close();
// fout.close();
//Commented lines are for restoring the deleted files to stud.dat file.
}
void SizeofFile()
{
 fstream fio("stud.dat",ios::in|ios::out|ios::binary);
 int size;
 int begin,last;
 begin=fio.tellg();
 while(fio.read((char*)&s,sizeof(s)));
 last=fio.tellg();
 fio.close();
 cout<<"\nThe Size of Stud.dat file is : "<<(last-begin)<<" bytes...\n";
}

