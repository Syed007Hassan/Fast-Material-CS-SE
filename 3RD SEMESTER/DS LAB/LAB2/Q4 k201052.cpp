#include<iostream>
#include <cstdlib>
#include<string.h>
using namespace std;
//S.M.HASSAN ALI K201052


class Friendcheck{
	
	int r,c;
	int**arr = new int *[r];
	
	
	
	public:
		
		Friendcheck(){
			r=0;
			c=0;
			arr=0;
		}
		
		int ab[5][5] = {{0,1,0,1,1},{1,0,1,0,1},{0,1,0,0,0},{1,0,0,0,1},{1,1,0,1,0}};
		
		Friendcheck(int rr,int cc):r(rr),c(cc){    //constructor 
			
			for(int i=0;i<r;i++){
				arr[i] = new int[c];
			}
			
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
				   	
				    arr[i][j] = ab[i][j];	
				}
			}
		}
		
		void checking(int r1,int r2){    //function for checking
			
			bool x;
			for(int j=0;j<5;j++){     //checking each column
           
               if(arr[r1][j] == 1 && arr[r2][j] == 1){
               	
               cout<<r1<<" and "<<r2<<" are Friends with: "<<j<<endl;
			      x = true;
                        }
                     
                }
                 if( x!= true)
					  cout<<"They have no common friends "<<endl;
			
		}
		
		
		Friendcheck(const Friendcheck &ff){   //copy constructor
			cout<<"Copy Constructor is working "<<endl;
			r = ff.r;
			c = ff.c;
			
			arr = new int*[r];
			for(int i= 0;i<r;i++){
				arr[i] = new int[c];
				
				memcpy(arr[i],ff.arr[i],sizeof(int)*c);
			}
				
		}
		
		int &operator ()(int r1,int r2){    //operator overloading for bound check
			
			if(r1 < 0 || r1 >r-1 || r2<0 || r2> r-1){
				cout<<"Boundary Error "<<endl;
				exit(1);
			}
			return arr[r1][r2];
		}
		
		
		Friendcheck &operator=(const Friendcheck& rhs){
          cout<<"Assignment operator is working "<<endl;
		  if (this == &rhs)
          return *this;
       
	    for (int i=r-1; i>=0; i--){
         delete arr[i];
		 }
        delete [] arr;
        arr = 0;
       
	    r = rhs.r;
        c = rhs.c;
      
	    arr = new int*[r];

       for( int i = 0 ; i <r ; i++ ){
        arr[i] = new int [c];
        memcpy(arr[i],rhs.arr[i],sizeof(int)*c);

     }
        
		return *this;
}
	
		
	
};



int main (){
	
	Friendcheck a(5,5),c;

    int r1, r2;

    cout<<"Input the two rows for searching friends: "<<endl;
    cin>>r1>>r2;
    
    cout<<a(r1,r2);
    a.checking(r1,r2);
    
    Friendcheck b=a; 
    
	c = b;    
        
        
                
}
