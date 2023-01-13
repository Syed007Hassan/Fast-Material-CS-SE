#include<iostream>
#include<stdlib.h>
#include <iomanip>
using namespace std;

Gpacal(string *name,float **arr,int r) {
	
	float sum[5]= {0};
	

     
      for(int j=0;j<5;j++)
       {
       	
       	sum[0]= sum[0] + (arr[0][j]*3);
         
       }
     
    
      for(int j=0;j<4;j++)
       {
       	
       	sum[1]= sum[1] + (arr[1][j]*3);
         
       }
      
      for(int j=0;j<3;j++)
       {
       	
       	sum[2]= sum[2] + (arr[2][j]*3);
         
       }
     
      for(int j=0;j<3;j++)
       {
       	
       	sum[3]= sum[3] + (arr[3][j]*3);
         
       }
       
      for(int j=0;j<5;j++)
       {
       	
       	sum[4]= sum[4] + (arr[4][j]*3);
         
       }
       
       cout<<endl<<"The following SGPA's of students are:  "<<endl;
     	for(int i=0;i<5;i++){
     	if(i==0) {
     		sum[i] = sum[i]/15;
        	cout<< *(name+i)<<" "<<sum[i]<<endl;	
		}
		else if(i==1) {
     		sum[i] = sum[i]/12;
        	cout<< *(name+i)<<" "<<sum[i]<<endl;	
		}
		else if(i==2) {
     		sum[i] = sum[i]/9;
        	cout<< *(name+i) <<" "<<sum[i]<<endl;	
		}
        else if(i==3) {
     		sum[i] = sum[i]/9;
        	cout<< *(name+i) <<" "<<sum[i]<<endl;	
		}
		else if(i==4) {
     		sum[i] = sum[i]/15;
        	cout<< *(name+i) <<" "<<sum[i]<<endl;	
		}
	 }
	
}








int main(){

    int r=5;
  float** array=new float*[r];
  


   array[0]=new float[5];
   array[1]=new float[4];
   array[2]=new float[3];
   array[3]=new float[3];
   array[4]=new float[5];
   
   
   float arr2[5][5]={{3.66,3.33,4.00,3.00,2.66},{3.33,3.00,3.66,3.00,0},{4.00 ,3.66,2.66,0,0},{2.66,2.33,4.00,0,0},{3.33,3.66,4.00,3.00,3.33}};
   
     
     for(int i=0;i<1;i++){
     	for(int j=0;j<5;j++){
		
       array[i][j]= arr2[i][j];

  }
 }
 
     for(int i=1;i<2;i++){
     	for(int j=0;j<4;j++){
		
       array[i][j]= arr2[i][j];

  }
 }
 
    for(int i=2;i<3;i++){
     	for(int j=0;j<3;j++){
		
       array[i][j]= arr2[i][j];

  }
 }
 
    for(int i=3;i<4;i++){
     	for(int j=0;j<3;j++){
		
       array[i][j]= arr2[i][j];

  }
 }
 
   for(int i=4;i<5;i++){
     	for(int j=0;j<5;j++){
		
       array[i][j]= arr2[i][j];

  }
 }
 
 string *names { new string[5]{"ALI   ","HIBA  ","ASMA  ","ZAIN  ","FAISAL"}};
 
 	cout<<"               DA          PAI          DLD         PAS        FAA"<<endl<<endl;
 
           for(int i=0;i<r;i++){
			cout<<setw(1)<<*(names + i);
   		
			if(i==0) {
				for(int j=0;j<5;j++) {
					cout<<setw(12)<<array[i][j]; 
				}
				cout<<endl << endl;	
			}
			else if(i==1) {
			
				for(int j=0;j<4;j++) {
					cout<<setw(12)<<array[i][j]; 
				}
				cout<<endl<< endl;
			}
			else if(i==2) {
			
				for(int j=0;j<3;j++) {
					cout<<setw(12)<<array[i][j]; 
				}
				cout<<endl<< endl;
			}
			else if(i==3) {
			
				for(int j=0;j<3;j++) {
					cout<<setw(12)<<array[i][j]; 
				}
				cout<<endl<< endl;
			}
			else if(i==4) {
			
				for(int j=0;j<5;j++) {
					cout<<setw(12)<<array[i][j]; 
				}
				cout<<endl<< endl;
			}
		}


   	Gpacal(names,array,r);

}
