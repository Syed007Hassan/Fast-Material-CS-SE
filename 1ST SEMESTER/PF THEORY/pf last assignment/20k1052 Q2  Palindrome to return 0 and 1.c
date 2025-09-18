#include<stdio.h> 
#include<string.h> 
#include<stdbool.h> 
 
 int palin(char arr[40]);
 int recpalin(char str[40], int x, int y);
 
   int main(){

    char arr[40]; 
    printf("\t\tEnter the string  ");
    gets(arr);
    printf(" %d ",palin(arr)); 
    return 0; 
} 
 
 int palin(char arr[40]){

   int n = strlen(arr); 
     if (n == 0) 
       return 1; 
  
    return recpalin(arr, 0, n - 1); 
} 
  
  int recpalin(char arr[40], int x, int y){
  
    if (x == y) 
    return 1; 
   
    if (arr[x] != arr[y]) 
    return 0; 
   
    if (x < y + 1) 
    return recpalin(arr, x + 1, y - 1); 
  
    return 1; 
} 
  

