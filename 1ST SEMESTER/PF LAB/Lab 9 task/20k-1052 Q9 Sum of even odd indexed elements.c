#include<stdio.h>
void sumEvenIndex(int *ptr,int n);
void sumOddIndex(int *ptr,int n);
void sortArray(int *ptr, int n);



int main(){

int arr[100];
int n,i;
printf("Enter the no of elements ");
scanf("%d",&n);
printf("Enter the elements \n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
    }
sumEvenIndex(arr,n);
sumOddIndex(arr,n);
sortArray(arr,n);


return 0;
}

void sumEvenIndex(int *ptr, int n){
int i,seven=0;
for(i=0;i<n;i++){
if(i % 2 == 0){
  seven = seven + *(ptr + i);
 
}
}
printf("The sum of even indexed elements is %d \n",seven);

}

void sumOddIndex(int *ptr,int n){
int i,sodd=0;
for(i=0;i<n;i++){
if(i % 2 != 0){
  sodd = sodd + *(ptr + i);
 
}

}
printf("The sum of odd indexed elements is %d \n",sodd);

}

void sortArray(int *ptr, int n){
int i,j,temp;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{

   if(*(ptr + j) < *(ptr + (j+1)))
   {
   temp=*(ptr + j);
*(ptr + j)= *(ptr + (j+1));
*(ptr + (j+1))=temp;
}
}
}

printf("The elements in sorted order are\n");
for(i=0;i<n;i++)
{
printf("\n   %d\n",*(ptr + i));

}

}

