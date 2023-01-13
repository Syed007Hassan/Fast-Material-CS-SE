#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
	
	string arr[13];
	char arr2[] = "How much wood could a woodchuck chuck If a woodchuck could hello";
	
	
	int i=0,j=0,c=0;

	
	 while(arr2[i] != '\0'){
	   c++;//count of words = 13
	
	while(arr2[i] != ' '){
         
         if(arr2[i] == '\0'){
         	break;
		 }
		 
		arr[j] = arr[j] + arr2[i];
		i++;
	  
	}
	++i;
	++j;
  }
  
  cout<<c;
  

  string arr3[c];
  
  for(int i=0;i<c;i++){
  
  	arr3[i] = arr[i];
  
  }

    for(int i=0;i<c;i++){
  	
  	cout<<arr3[i]<<" ";
  	
  }
  


			
}
