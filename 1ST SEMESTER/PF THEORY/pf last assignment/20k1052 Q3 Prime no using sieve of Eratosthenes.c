#include<stdio.h>
int main(){

int i,j,num[100];

    for(i=0;i<100;i++){

      num[i]=i+1; 
	  }

    printf("\n Numbers stored in array are: \n\n");

   for(i=0;i<100;i++){
    printf("%5d ",num[i]);
    printf("\n");
}

   printf("\n\n After the procedure of Sieve of Eratosthenes:\n\n");

   for(i=2;i<100;i++){

   for(j=2;j<num[i];j++){

       if(num[i] % j == 0)
          num[i]=0;
        }
    }


   for(i=1;i<100;i++) {
     printf("%5d ",num[i]);
     printf("\n");
}

     printf("\n\n Prime numbers are: \n\n");
      for(i=1;i<100;i++) {
         if(num[i] != 0)

       printf("%5d ",num[i]);
}

return 0;
}
 

