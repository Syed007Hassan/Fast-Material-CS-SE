#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<conio.h>
#include <windows.h>

using namespace std;

class library {
	public:
       string bookname[50],auname[50],ibook[100];
       int bookid[100],iid[100];
       int q,B,p;
       int choice;
       
       library()
       {
        	bookname[0] = "harry potter";
        	bookname[1] = "twilight";
        	bookname[2] = "diwan-e-ghalib";
        	bookname[11] = "for the love of physics";
        	bookname[12] = "newtonian";
        	bookname[13] = "einstein physics";
        	bookname[21] = "calculus v1";
        	bookname[22] = "calculus v2";
        	auname[0] = "jk rowling";
        	auname[1] = "stephenie meyer";
        	auname[2] = "mirza ghalib";
        	auname[11] = "walter lewin";
        	auname[12] = "newton jr";
        	auname[13] = "eintsein";
        	auname[21] = "sir nadeem";
        	auname[22] = "sir shoiab";
        	bookid[0] = 1;
        	bookid[1] = 2;
        	bookid[2] = 3;
        	bookid[11] = 12;
        	bookid[12] = 13;
        	bookid[13] = 14;
        	bookid[21] = 22;
        	bookid[22] = 23;
        	
       }
       
		begin() {
			system("cls");
			system("Color F5");

			cout << "\n\n\t\t     ~~~~~~~~ WElCOME TO THE MAIN MENU ~~~~~~~~";
			cout << "\n\n\n\n\t 1. Student";
			cout << "\n\n\t 2. Librarian";
			cout << "\n\n\t 3. Exit program";
			cout << "\n\n\n\t Enter your choice: ";
		
		}
		
		booklist(int i) {
			
			system("cls");
			
			int b,j,r;
			
            system("cls");
            b=course(i);
            system("cls");
            
            if(b==1) {
            	
                r=0;
                for(j=0;bookid[j]!=0 && bookid[j]<=10;j++) {
                	cout << "\n\n\t\t~~"<< r++ << "~~\n\n";
                	cout << "Book Name: " << bookname[j] << endl;
                	cout << "Author Name: " << auname[j] << endl;
                	cout << "Book ID: " << bookid[j] << endl;
				}
			}
			else if(b==2) {
				
				r=0;
                for(j=11;bookid[j]!=0 && bookid[j]<=20;j++) {
                	cout << "\n\n\t\t~~"<< r++ << "~~\n\n";
                	cout << "Book Name: " << bookname[j] << endl;
                	cout << "Author Name: " << auname[j] << endl;
                	cout << "Book ID: " << bookid[j] << endl;
				}
			}
			else if(b==3) {
				
				r=0;
                for(j=21;bookid[j]!=0 && bookid[j]<=30;j++) {
                	cout << "\n\n\t\t~~"<< r++ << "~~\n\n";
                	cout << "Book Name: " << bookname[j] << endl;
                	cout << "Author Name: " << auname[j] << endl;
                	cout << "Book ID: " << bookid[j] << endl;
				}
			}
                
            begin();
            
    		}
    		
    	course(int x) {
    		int i;
      		cout<<"\n\t\t>>Please Choose one Branch :-\n";
      		cout<<"\n\t\t1.Novels\n\n\t\t2.Physics\n\n\t\t3.Calculus\n\n\t\t4.Go to menu\n";
      		cout<<"\n\t\tEnter your choice : ";
      		cin>>i;
      		switch(i)
      		{
          		case 1: 
					return 1;
                  	break;
          		case 2: 
					return 2;
                  	break;
          		case 3:
				   	return 3;
                  	break;
          		case 4: 
					system("cls");
					
                  	if(x==1)
                  	begin();
                  	else {
                  		library::begin();
					  }
					break;  
					  
          			default : cout<<"\n\t\tPlease enter correct option :(";
                    getch();
                    
                    system("cls");
                    course(x);
                    
        		}
        		
			}
		
};

class librarian;

class student:public library {
	public: 
		int opt;
		
		begin() {
			
			system("cls");
			system("Color F3");
			cout << endl;
			cout << "\n\n\t\t\t\t~~~~STUDENT PORTAL~~~~\n\n\n\n";	
			cout << "\n\n\t Choose a option ";
			cout << "\n\n\t 1. View all Books";
			cout << "\n\n\t 2. Search a Book";
			cout << "\n\n\t 3. Go to Main Menu";
			cout << "\n\n\t Enter your Option: ";
			cin >> opt;	
			
			if(opt == 1) {
				booklist(1);
			}
			else if(opt==2) {
				search(1);
			}
			else if(opt ==3) {
				library::begin();
			}
			else {
      			cout << "\n\n\t\t\t Wrong Choice! ";
      			getch();
      			begin();
		  	}
		}
		
		booklist(int i) {
			system("cls");
			
			int b,j,r;
			
            system("cls");
            b=course(i);
            system("cls");
            
            if(b==1) {
                r=1;
                for(j=0;bookid[j]!=0 && bookid[j]<=10;j++) {
                	cout << "\n\n\t\t\t~~"<< r++ << "~~\n\n";
                	cout << "\t\tBook Name: " << bookname[j] << endl;
                	cout << "\t\tAuthor Name: " << auname[j] << endl;
                	cout << "\t\tBook ID: " << bookid[j] << endl;
				}
			}
			else if(b==2) {
				r=1;
                for(j=11;bookid[j]!=0 && bookid[j]<=20;j++) {
                	cout << "\n\n\t\t~~"<< r++ << "~~\n\n";
                	cout << "\t\tBook Name: " << bookname[j] << endl;
                	cout << "\t\tAuthor Name: " << auname[j] << endl;
                	cout << "\t\tBook ID: " << bookid[j] << endl;
			    }
			}
			else if(b==3) {
				r=1;
                for(j=21;bookid[j]!=0 && bookid[j]<=30;j++) {
                	cout << "\n\n\t\t~~"<< r++ << "~~\n\n";
                	cout << "\t\tBook Name: " << bookname[j] << endl;
                	cout << "\t\tAuthor Name: " << auname[j] << endl;
                	cout << "\t\tBook ID: " << bookid[j] << endl;
				}
			
			}
            getch();
            if(i==1) {
            	begin();
			}
            else {
                library::begin();
			}
                    
    	}
    		
    	course(int x) {
    		int i;
    		system("cls");
    		
      		cout<<"\n\n\t\t>>Please Choose one Branch :-\n";
      		cout<<"\n\t\t1.Novels\n\n\t\t2.Physics\n\n\t\t3.Calculus\n\n\t\t4.Go to menu\n";
      		cout<<"\n\t\tEnter your choice : ";
      		cin>>i;
      		
      		switch(i)
      		{
          		case 1: 
				  	return 1;
               		break;
          		case 2: 
				  	return 2;
              		break;
          		case 3:
				   	return 3;
              		break;
          		case 4: 
					system("cls");
                  	if(x==1) {
                  		begin();
                  	}
                  	else {
                  		library::begin();
				  	}
				  	break;
				  	
          		default : cout<<"\n\t\tPlease enter correct option :(";
                    getch();
                    system("cls");
                    course(x);
        	}
		}
		
		search(int x) {
			int i,j,b;
      		string ch;
      		
      		system("cls");
      		
      		cout<<"\n\n\t\t\tPlease Choose one option for below: \n";
      		cout<<"\n\n\n\t\t\t1.Search By Name";
      		cout << "\n\n\t\t\t2.Search By Book's ID\n";
      		cout<<"\n\t\t\tEnter Your Choice : ";
      		cin >> i;
      	
      		if(i==1)
      		{
          		cout<<"\n\n\t\t\nEnter the Book's Name: ";
          		getchar();
				getline(cin,ch);
          		system("cls");
          
          		cout << "\n\n\n\n\n\t\t\t";
			
				for(j=0;j<=51;j++) {
					
					if(bookname[j] == ch)
					{
						cout << "Book Name: " << bookname[j] << endl;
                		cout << "\n\n\t\t\tAuthor Name: " << auname[j] << endl;
                		cout << "\n\n\t\t\tBook ID: " << bookid[j] << endl;
                		cout << "\n\n\n\n\t\t\tPress any key to continue";
      					getch();
      					begin();
                		break;
					}
					else if(j>50) {
						cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
						getch();
						search(x);
					}
				}
      		}
      		else if(i==2) {
      			cout<<"\n\t\t\tEnter the Book's ID: ";
      			cin >> j;
      			system("cls");
      		
      			cout << "\n\n\n\n\n\t\t\t";
      		
      			for(i=0;i<=51;i++) {
      			
      				if(bookid[i] == j)
					{
						cout << "Book Name: " << bookname[i] << endl;
                		cout << "\n\n\t\t\tAuthor Name: " << auname[i] << endl;
                		cout << "\n\n\t\t\tBook ID: " << bookid[i] << endl;
                		cout << "\n\n\n\n\t\t\tPress any key to continue";
      					getch();
      					begin();
                		break;
					}
					else if(i>50) {
						cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
						getch();
						search(x);
					}
			  	}
		  	}
		  	else {
		  		cout << "\n\n\t\t\t Wrong Choice! ";
		  		getch();
		  		search(x);
		  	}
		  	
      }
      
      friend class librarian;
		
};

class librarian: public library {
	public:
		student s;
	    string sname,isname[100];
	    int sid,isid[100];
	    
	    pass() {
			int i=0;
    		char ch,st[21],ch1[21]={"ali"};
    		cout<<"\n\t Enter Password : ";
    		
    		while(1)
    		{
    			ch=getch();
    			if(ch==13)
    			{
        			st[i]='\0';
        			break;
    			}
    			else if(ch==8&&i>0)
    			{
        			i--;
        			cout<<"\b \b";
    			}
    			else
    			{
    				cout<<"*";
    				st[i]=ch;
    				i++;
    			}
    		}
    		ifstream inf("password.txt");
    		inf>>ch1;
    		inf.close();
    		for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    		if(st[i]=='\0'&&ch1[i]=='\0')
    		{
        		system("cls");
        		begin();
    		}
    		else
    		{
        		cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        		getch();
        		system("cls");
        		pass();
    		}
    	}
	
		begin() {
			system("cls");
			system("Color F1");
			
			int i;
			
        	cout << "\n\t\t~~~ WELCOME LIBRARIAN ~~~\n";
        	cout << "\n\n\t\t>>Choose One Option:\n";
        	cout << "\n\t\t1. View All Books";
			cout << "\n\n\t\t2. Search a Book";
			cout << "\n\n\t\t3. Modify/Add/Delete Book";
			cout << "\n\n\t\t4. Issue Book";
			cout << "\n\n\t\t5. Go to main menu";
			cout << "\n\n\t\t6. Close Application\n";
        	cout << "\n\t\tEnter your choice: ";
        	cin>>i;
        	
        	switch(i)
        	{
            	case 1: booklist(1);
                     	break;
            	case 2:search(1);
                    	 break;
            	case 3:modify();
                     	break;
            	case 4:issue();
                     	break;
            	case 5:library::begin();
                     	break;
            	case 6:exit(0);
            	default:cout<<"\n\t\tPlease enter correct option :(";
            	getch();
            	system("cls");
            	begin();
        	}
        
		}
		
		booklist(int i) {
			system("cls");
			
			int b,j,r;
			
            system("cls");
            b=course(i);
            system("cls");
                
            if(b==1) {
            	
                r=1;
                for(j=0;bookid[j]!=0 && bookid[j]<=10;j++) {
                	cout << "\n\n\t\t\t~~"<< r++ << "~~\n\n";
                	cout << "\t\tBook Name: " << bookname[j] << endl;
                	cout << "\t\tAuthor Name: " << auname[j] << endl;
                	cout << "\t\tBook ID: " << bookid[j] << endl;
				}
			}
			else if(b==2) {
				
				r=1;
                for(j=11;bookid[j]!=0 && bookid[j]<=20;j++) {
                	cout << "\n\n\t\t\t~~"<< r++ << "~~\n\n";
                	cout << "\t\tBook Name: " << bookname[j] << endl;
                	cout << "\t\tAuthor Name: " << auname[j] << endl;
                	cout << "\t\tBook ID: " << bookid[j] << endl;
				}
			}
			else if(b==3) {
				
				r=1;
               	for(j=21;bookid[j]!=0 && bookid[j]<=30;j++) {
                	cout << "\n\n\t\t~~"<< r++ << "~~\n\n";
                	cout << "\t\tBook Name: " << bookname[j] << endl;
                	cout << "\t\tAuthor Name: " << auname[j] << endl;
                	cout << "\t\tBook ID: " << bookid[j] << endl;
				}
			}
			
            getch();
            system("cls");
            
            if(i==1) {
               begin();
           }
    	}
    		
    	search(int x) {
			int i,j,b;
      		string ch;
      		
      		system("cls");

      		system("cls");
      		cout<<"\n\n\t\t\tPlease Choose one option for below: \n";
      		cout<<"\n\n\n\t\t\t1.Search By Name";
      		cout << "\n\n\t\t\t2.Search By Book's ID\n";
      		cout<<"\n\t\t\tEnter Your Choice : ";
      		cin >> i;
      	
      		if(i==1)
      		{
          		cout<<"\n\n\t\t\nEnter the Book's Name: ";
          		getchar();
				getline(cin,ch);
          		system("cls");
			
				cout << "\n\n\n\n\n\t\t\t";
				for(j=0;j<=101;j++) {
					if(bookname[j] == ch)
					{
						cout << "Book Name: " << bookname[j] << endl;
                		cout << "\n\n\t\t\tAuthor Name: " << auname[j] << endl;
                		cout << "\n\n\t\t\tBook ID: " << bookid[j] << endl;
                		cout << "\n\n\n\n\t\t\tPress any key to continue";
      					getch();
      					begin();
                		break;
					}
					else if(j>100) {
						cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
						getch();
						search(x);
					}
				}
      		}
      		else if(i==2) {
      			cout<<"\n\t\t\tEnter the Book's ID: ";
      			cin >> j;
      			system("cls");
      		
      			cout << "\n\n\n\n\n\t\t\t";
      		
      			for(i=0;i<=101;i++) {
      			
      				if(bookid[i] == j)
					{
						cout << "\n\n\t\t\tBook Name: " << bookname[i] << endl;
                		cout << "\n\n\t\t\tAuthor Name: " << auname[i] << endl;
                		cout << "\n\n\t\t\tBook ID: " << bookid[i] << endl;
                		cout << "\n\n\n\n\t\t\tPress any key to continue";
      					getch();
      					begin();
                		break;
					}
					else if(i>100) {
						cout << "\n\n\n\n\t\t\t\tBOOK NOT FOUND! ";
						getch();
						search(x);
					}
			  	}
		  	}
		  	else {
      			cout << "\n\n\t\t\t Wrong Choice! ";
      			getch();
      			search(x);
		  	}
		  	
      
  		}
		
		modify(){
			
			string ch;
    		int i=0,b,j;
    		system("cls");
    		
    		cout << "\n\t\t>>Please Choose one option :-\n\n";
    		cout << "\n\t\t1. Modification In Current Books";
			cout << "\n\n\t\t2. Add New Book";
			cout << "\n\n\t\t3. Delete A Book";
			cout << "\n\n\t\t4.Go back\n";
    		cout<<"\n\n\t\tEnter your choice : ";
    		cin>>i;
    	
    		if(i==1) {
    			system("cls");
        		cout<<"\n\t\tPlease Choose One Option :-\n\n";
            	cout<<"\n\t\t1.Search By Book Name";
				cout << "\n\n\t\t2.Search By Book's ID\n";
                cout<<"\n\t\tEnter Your Choice : ";
                cin>>j;
    	
    			if(j==1)
      			{
      				system("cls");
      				cout << "\n\n\n\t\t\t~~~~ Search ~~~~\n";
          			cout<<"\n\n\t\tEnter the Book's Name: ";
          			getchar();
					getline(cin,ch);
			
					for(j=0;j<=51;j++) {
						
						if(bookname[j] == ch)
						{
							cout << "\n\n\n\t\tEnter the new name: ";
							getline(cin,bookname[j]);
                			cout << "\n\t\tEnter the new Author Name: ";
							getline(cin,auname[j]);
                			cout << "\n\t\tEnter the new Book ID: ";
							cin >> bookid[j] ;
					
							s.bookname[j] = bookname[j];
							s.auname[j] = auname[j];
							s.bookid[j] = bookid[j];
                	
                			cout<<"\n\t\tUpdate Successful.\n";
                			getch();
                			modify();
                			break;
                	
						}
						else if(j==51) {
							cout << "\n\n\t\tBook Not Found! ";
							getch();
							modify();
						}  
                        
					}
	
      			}
      			else if(j==2) {
      				system("cls");
      				
      				cout << "\n\n\n\t\t\t~~~~ Search ~~~~\n";
      				cout<<"\n\n\t\tEnter the Book's ID: ";
      				cin >> j;
      				
      				for(i=0;i<=51;i++) {
      			
      					if(bookid[i] == j)
						{
							cout << "\n\n\n\t\tEnter the new name: ";
							getchar();
							getline(cin,bookname[i]) ;
                			cout << "\n\t\tEnter the new Author Name: ";
							getline(cin,auname[i]) ;
                			cout << "\n\t\tEnter the new Book ID: ";
							cin >> bookid[i] ;
					
							s.bookname[i] = bookname[i];
							s.auname[i] = auname[i];
							s.bookid[i] = bookid[i];
							
							cout<<"\n\t\tUpdate Successful.\n";
                			getch();
                			modify();
                			break;
						}
						else if(i==51) {
							cout << "\n\n\t\tBook Not Found! ";
							getch();
							modify();
						}
			  		}
		  		}
		  		else {
      				cout << "\n\n\t\t\t Wrong Choice! ";
      				getch();
      				modify();
		  		}
		 	  
			}
			else if(i==2){
				system("cls");
			
				int cc,q;
			
				cout<<"\n\n\n\t\tHow many books you want to add?(3-4): ";
				cin>>cc;
				cout<<"\n\n\t\tIn which category you want to add the books: 1-Novel  2-Physics  3-Calculus: ";
				cin>>q;
				cout<<endl;
			
				if(q==1){
					cout<<"\n\n\n\t\tEnter the details of the new Novel Books"<<endl<<endl;
					for(j=3;j<3+cc;j++){
						cout << "\n\n\t\tEnter the new name of the book: "<<j+1<<" ";
						getchar();
						getline(cin,bookname[j]) ;
                		cout << "\n\t\tEnter the Author Name: ";
						getline(cin,auname[j]) ;
                		cout << "\n\t\tEnter the new Book ID: ";
						cin >> bookid[j] ;
						cout<<endl<<endl;
					
						s.bookname[j] = bookname[j];
						s.auname[j] = auname[j];
						s.bookid[j] = bookid[j];
					}
				
					cout << "\n\n\t\tBook Sucessfully Added! ";
					getch();		
					modify();
		
				}
				else if(q==2){
					cout<<"\n\n\n\t\tEnter the details of the new Novel Books"<<endl<<endl;
					for(j=14;j<14+cc;j++){
						cout << "\n\n\t\tEnter the new name of the book: "<<j+1<<" ";
						getchar();
						getline(cin,bookname[j]) ;
                		cout << "\n\t\tEnter the Author Name: ";
						getline(cin,auname[j]) ;
                		cout << "\n\t\tEnter the new Book ID: ";
						cin >> bookid[j] ;
						cout<<endl<<endl;
					
						s.bookname[j] = bookname[j];
						s.auname[j] = auname[j];
						s.bookid[j] = bookid[j];
					}	
				
					cout << "\n\n\t\tBook Sucessfully Added! ";
					getch();		
					modify();
		
				}
				else if(q==3){
					
					cout<<"\n\n\n\t\tEnter the details of the new Novel Books"<<endl<<endl;
					
					for(j=23;j<23+cc;j++){
						cout << "\n\n\t\tEnter the new name of the book: "<<j+1<<" ";
						getchar();
						getline(cin,bookname[j]) ;
                		cout << "\n\t\tEnter the Author Name: ";
						getline(cin,auname[j]) ;
                		cout << "\n\t\tEnter the new Book ID: ";
						cin >> bookid[j] ;
						cout<<endl<<endl;
					
						s.bookname[j] = bookname[j];
						s.auname[j] = auname[j];
						s.bookid[j] = bookid[j];
					}
				
					cout << "\n\n\t\tBook Sucessfully Added! ";
					getch();		
					modify();
		
				}
			
			}
			else if(i==3){
			
				int i,j,b;
      			string ch;

            	system("cls");
      			cout<<"\n\n\n\t\t\t Enter the Book's ID: ";
      			cin >> j;

      			for(i=0;i<=51;i++) {
      			
      				if(bookid[i] == j)
					{
				    	bookname[i]='\0';
                    	auname[i]='\0';
                		bookid[i]=bookid[i];
                	
                		s.bookname[i]='\0';
                    	s.auname[i]='\0';
                		s.bookid[i]=bookid[i];
                	
                		cout << "\n\n\t\t\t Delete Sucessful! ";
                		getch();
                		modify();
                		break;
                	
					}
					else if(i==51) {
						cout << "\n\n\t\t\t Book Not Found! ";
						getch();
						modify();
					}

			  	}
		
      		}
    		else if(i==4){
      		system("cls");
      		librarian::begin();
      		}
      		else {
      			cout << "\n\n\t\t\t Wrong Choice! ";
      			getch();
      			modify();
		  	}
      
  		}
  
  		issue() {
  			system("cls");
  	
  			string name,line;
			int i,id,j;
			  
			cout<<"\n\t\t->Please Choose one option :-\n";
    		cout<<"\n\t\t1.Issue Book";
			cout << "\n\n\t\t2.View Issued Book";
			cout << "\n\n\t\t3.Return Book";
			cout << "\n\n\t\t4.Go back to menu";
			cout << "\n\n\t\tEnter Your Choice: "; 
			cin >> i;
	
			if(i==1) {
				system("cls");
				cout << "\n\n\n\tPress 1 if you like to view the book list else press 0: ";
				cin >> j;
				if(j==1) {
					booklist(1);
				}
				else {
					cout << "\n\n\t\t Enter the name of book: ";
					getchar();
					getline(cin,name);
					cout << "\n\t\t Enter the ID of Book: ";
					cin >> id;
					
					for(j=0;j<=51;j++) {
				
						if(bookname[j] == name) {
							if(bookid[j] == id) {
								cout << "\n\n\t\t Enter your name: ";
								getchar();
								getline(cin,sname);
								cout << "\n\t\t Enter your ID: ";
								cin >> sid;
								cout << "\n\nISSUE SUCCESSFUL!!";
								ibook[id-1] = name;
								iid[id-1] = id;
								isname[id-1] = sname;
								isid[id-1] = sid;
					
								fstream issuee;
								issuee.open("issue.txt",ios::app);
								if(!issuee) {
									cout << "\n\n File not created!.";
								}
								else {
								issuee << "Student Name: " << sname << endl;
								issuee << "Student's ID: " << sid << endl;
								issuee << "Book Name: " << name << endl;
								issuee << "Book ID: " << id << endl << endl << endl; 
								issuee.close();
								}
					
								cout << "\n\n Press any key to continue.";
								getch();
								issue();
		
							}		
	
						}
						else if(j==51) {
								cout << "\n\n Book not found!";
								getch();
								issue();
							}
					}
			
				}	
			}
			else if(i==2) {
				system("cls");
				
				cout << "\n\n\t\t\t ~~~~ List of issued Books ~~~~\n\n\n";
				string ch;
				int k=1,l=2;
				
				for(j=0;iid[j]!=0 && iid[j] <=100;j++) {
					fstream issuee;
					issuee.open("issue.txt",ios::in);
					if(!issuee) {
						cout << "\n\n File not created!.";
					}
					else {
						cout << "\n\n\n\t\t\t\t  ~~~" << 1 << "~~~\n\n";
						while(issuee) {
							if(k==6) {
								cout << "\n\n\n\t\t\t\t  ~~~" << l++ << "~~~\n";
								k=0;
							}
							getline(issuee,ch);
							cout << "\t\t\t" << ch << endl;
							k++;
						}
						issuee.close();
					}
			
				}
				
				cout << "\n\t Press any key to continue!";
				getch();
				issue();
			}
			else if (i==3) {
				system ("cls");
				cout << "\n\n \t\t~~~Return Book~~~\n";
				
				cout << "\n\n\t Enter your Name: ";
				getchar();
				getline(cin,sname);
				cout << "\n\n\t Enter your ID: ";
				cin >> sid;
				cout << "\n\n\t Enter Book Name: ";
				getchar();
				getline(cin,name);
				cout << "f\n\n\t Enter Book ID: ";
				cin >> id; 
				
				for(j=0;j<=99;j++) {
					if(sname == isname[j]) {
						if(sid == isid[j]) {
							if(id == iid[id-1]) {
								ibook[id-1] = '\0';
								isname[j] = '\0';
								isid[j] = '\0';
								cout << "\n\n\n\t\tRETURN SUCESSFULL! ";
								getch();
								issue();
							}
					
						}
					
					}
					else if(j==99){
						cout << "\n\n\n\t\t DATA NOT FOUND! ";
						getch();
						issue();
					}	   
				}
			}
			else if(i==4) {
				begin();
			}
			else {
				cout << "\n\n\t\t\t Wrong Choice! ";
				getch();
				issue();
			}
  		}
			

}; 


void text_animation(string a);



main() {
	system("Color FC");
	int i=0;
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
	cout << "~~~~~ LIBRARY MANAGEMENT SYSTEM ~~~~~\n\n\n\n\t\t\t\t\t~~~~~ Created by: El Programmers ~~~~\n\n\n\n\t\t\t\t\t\t~~~ Ehetsham Zafar ~~~\n\n\n\n\t\t\t\t\t\t~~~~ Hassan Ali ~~~~";
	//text_animation("~~~~~ LIBRARY MANAGEMENT SYSTEM ~~~~~\n\n\n\n\t\t\t\t\t~~~~~ Created by: El Programmers ~~~~\n\n\n\n\t\t\t\t\t\t~~~ Ehetsham Zafar ~~~\n\n\n\n\t\t\t\t\t\t~~~~ Hassan Ali ~~~~");
	getch();
	system("cls");
	
	library lib;
	librarian l;
	student s;
	
	
	lib.begin();
	
	for(i=1;i>0;i++) {
		cin >> lib.choice;
		if(lib.choice==1) {
	
			s.begin();
		}
		else if(lib.choice==2){
			l.pass();	
		}
		else if(lib.choice==3){
			exit(0);
		}
		else {
			cout << "\n\n \t\t Wrong Choice!!";
			getch();
			lib.begin();
		}
	
	}
}



void text_animation(string a){
	system("Color FC");
	
	int i;
	long double k;
	
	for(i=0;a[i]!='\0';i++){

		for(k=0;k<5500000;k++);
			cout<<a[i];
	}
}



